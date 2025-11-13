#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define STORAGE_SIZE 4096
static char storage[STORAGE_SIZE];
static const char *storage_end = storage + STORAGE_SIZE;

typedef struct {
  uint64_t size : 63;
  bool allocated : 1;
} Header;

static Header read_header(const char *ptr) { 
    return *(Header *)ptr; 
}

static void write_header(char *ptr, Header header) {
  *(Header *)ptr = header;
}

void simple_heap_init() {
  // On startup, all the heap is one free range.
  Header hdr = {
    .size = STORAGE_SIZE, 
    .allocated = false
};
  write_header(storage, hdr);
}

static char *find_free_space(size_t bytes) {
  Header header = {.size = 0, .allocated = false};
  for (char *header_ptr = storage; header_ptr < storage_end; header_ptr += header.size) {
    header = read_header(header_ptr);
    assert(header.size != 0 && "Header should always have non-zero size.");
    if (!header.allocated && (header.size >= bytes))
      return header_ptr;
  }

  return NULL;
}

static void split_range(char *range, uint64_t size) {
  Header original_header = read_header(range);
  assert(!original_header.allocated &&
         "Shouldn't be splitting an allocated range.");

  // Mark what we need as allocated.
  Header new_header = {.size = size, .allocated = true};
  write_header(range, new_header);

  // The following space is free and needs a new header to say so.
  uint64_t remaining = original_header.size - size;
  if (remaining) {
    Header free_header = {.size = remaining, .allocated = false};
    write_header(range + size, free_header);
  }
}


void *simple_malloc(size_t size) {
  if (!size)
    return NULL;

  // Extra space to include the header.
  uint64_t required_size = size + sizeof(Header);
  char *allocated = find_free_space(required_size);

  if (!allocated) {
    return NULL;
  }

  // Split the found range into this new allocation and a new free range after
  // it.
  split_range(allocated, required_size);

  // Return a pointer to after the header.
  allocated += sizeof(Header);

  return allocated;
}


void simple_free(void *ptr) {
  if (!ptr)
    return;

	assert(((char*)ptr > storage) && ((char*)ptr < storage_end) &&
         "Trying to free pointer that is not within the heap.");

  // This will point to after the header of the range it's in, so we must walk
  // back a bit.
  char *header_ptr = (char *)ptr - sizeof(Header);

  Header header = read_header(header_ptr);
  assert(header.size != 0 && "Can't free an allocation of zero size.");

  // Mark this range as free, leave the size unchanged.
  header.allocated = false;
  write_header(header_ptr, header);


  // ------------------------ Coalescing ------------------------
  char* next_header_ptr = header_ptr + header.size;
  Header nextHeader = read_header(next_header_ptr);
  if(nextHeader.allocated == false) {
    Header combined_header = {.size = header.size+nextHeader.size, .allocated = false };
    write_header(header_ptr, combined_header);
  }
}