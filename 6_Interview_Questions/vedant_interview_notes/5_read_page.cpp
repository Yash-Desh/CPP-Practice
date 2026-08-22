// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Egor and Eylon (Apple)
// Link  : https://gist.github.com/VedantParanjape/7a0c3e2d42ab669a144da67cebde041b

#include <string.h>
#include <iostream>
#include <cstdint>

#define PAGE_SIZE 4096

// * The following low-level function attempts to read `PAGE_SIZE` bytes of data
// from the input file into the memory location pointed to by `ptr`.
// * The function returns the number of bytes that were **actually** read.
// * Upon reading `EOF`, 0 is returned.
size_t read_next_page(void *ptr);

// For example, the input file has size of `(2 x PAGE_SIZE + 42)` bytes:
// | ------ PAGE_SIZE bytes ------ |
// | ------ PAGE_SIZE bytes ------ |
// | - 42 bytes - |

// Then
// * the 1-st call to `read_next_page` will return PAGE_SIZE and copy
//   the content of the first `PAGE_SIZE` bytes in the file to `ptr`.
// * the 2-nd call to `read_next_page` will return PAGE_SIZE and copy
//   the content of the next `PAGE_SIZE` bytes in the file to `ptr`.
// * the 3-rd call will return 42 and copy the remaining 42 bytes to `ptr`.
// * the 4-th and all the consecutive calls will return 0.

// Problem: Implement a high-level function that allow reading an arbitrary
// number of bytes from the input file.

// read x
// read y and y < x

size_t read_arbitrary(void *ptr, size_t num) {

//  call read_next_page -> num % PAGE_SIZE // 1
//  call read_next_page -> for remaining bytes // 0

  // 12 bytes
  // PS = 4 bytes
  // num_calls = 2
  // 10 - 2 * 4 = 2
  int num_calls = num / PAGE_SIZE;
  bool rem = num % PAGE_SIZE;
  size_t count = 0;
  for (int i = 0; i < num_calls; i++) {
    size_t out = read_next_page(ptr);
    uint8_t *temp = (uint8_t*)ptr;
    temp += out;
    ptr = (void*)temp;
    count += out;

    if (out != PAGE_SIZE) {
      rem = false;
      break;
    }
  }

  if (rem) {
    size_t out = read_next_page(ptr);
    uint8_t *temp = (uint8_t*)ptr;
    if (out > num)
      temp += (num % PAGE_SIZE);
    else
      temp += out;
    ptr = (void*)temp;
    count += out;

    if (out != (num % PAGE_SIZE)) {
    }
  }

  return count;
}

// page size = 4KB

// char buf[5];
// read_arbitrary(buf, 5)

/*

Because ptr points into the caller's buffer, not into the file. Advancing it does
  nothing to where read_next_page reads next — that position is private state inside
  read_next_page, and it only ever moves in whole-page steps. There's no seek, no
  rewind, no "read from offset" in the API you were given

num is the caller's request, not the file's length. Those are two independent
quantities, and num_calls only bounds the loop by the first one — nothing in the loop knows how
much data actually exists.

Think about the interesting cases here. 
1. file is 6KB units you ask to read 16KB --> rem => 0
2. file is 8Kb units you ask to read 5KB  --> rem != 0


for the last iteration when rem < PAGE_SIZE for e.g. rem = 5
read_next_page writes up to PAGE_SIZE bytes
  into ptr — it has no idea you only wanted 5. The tail path at line 64 hands it the caller's
  buffer directly:

  small request (char buf[5])  file=8192  req=5  -> returned 4096  overflow=4091 bytes <-- BUFFER
  OVERRUN
  request 1.5 pages            file=16384 req=6144 -> returned 8192 overflow=2048 bytes <-- BUFFER
  OVERRUN

  That's the char buf[5]; read_arbitrary(buf, 5); case sketched at lines 82–83 — it smashes 4091
  bytes past the end of a 5-byte stack array. The return value is wrong too: 4096 for a 5-byte
  request.

  The fix is a bounce buffer for the final partial read:

  size_t tail = num % PAGE_SIZE;
  if (tail && count == (size_t)num_calls * PAGE_SIZE) {   // loop didn't hit EOF
      uint8_t scratch[PAGE_SIZE];
      size_t out = read_next_page(scratch);               // safe: full page available
      size_t take = out < tail ? out : tail;
      memcpy(ptr, scratch, take);
      count += take;
  }

  Read the whole page somewhere safe, then copy only what was asked for. Note this discards out - 
  take bytes, so a correct implementation also needs somewhere to stash that remainder for the
  next call — otherwise read_arbitrary isn't resumable and data silently vanishes between calls.
  That's very likely the follow-up the Apple interviewers were driving at, and it's the part the
  current code doesn't attempt.


  Claude's corrected version. 
  Corrected version

  The carry buffer is what makes it resumable:

  static uint8_t g_carry[PAGE_SIZE];
  static size_t g_carry_len = 0, g_carry_off = 0;

  size_t read_arbitrary(void *ptr, size_t num) {
    uint8_t *dst = (uint8_t*)ptr;
    size_t count = 0;
    if (!dst || num == 0) return 0;

    // 1. drain leftovers from a previous call
    if (g_carry_len > g_carry_off) {
      size_t take = g_carry_len - g_carry_off;
      if (take > num) take = num;
      memcpy(dst, g_carry + g_carry_off, take);
      g_carry_off += take; dst += take; count += take;
      if (count == num) return count;
    }
    // 2. full pages go straight into the caller's buffer
    while (num - count >= PAGE_SIZE) {
      size_t out = read_next_page(dst);
      dst += out; count += out;
      if (out != PAGE_SIZE) return count;        // EOF
    }
    // 3. tail: bounce through scratch, stash the surplus
    if (count < num) {
      size_t tail = num - count;
      size_t out  = read_next_page(g_carry);
      size_t take = out < tail ? out : tail;
      memcpy(dst, g_carry, take);
      count += take;
      g_carry_len = out; g_carry_off = take;
    }
    return count;
  }


*/ 