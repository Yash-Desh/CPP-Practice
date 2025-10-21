// Tutor : ChatGPT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    void *start, *end;
    size_t step = 1024 * 1024;  // grow by 1 MB at a time
    size_t total = 0;

    // get initial program break (heap end)
    start = sbrk(0);
    printf("Initial program break: %p\n", start);

    // keep growing heap until failure
    while (1) {
        void *prev = sbrk(step);
        if (prev == (void *) -1) {
            perror("sbrk failed");
            break;
        }
        total += step;
        end = sbrk(0);

        if ((total / (1024 * 1024)) % 100 == 0) {  // print every 100 MB
            printf("Heap grown to: %p (total %.1f MB)\n", end, total / 1048576.0);
        }
    }

    printf("\nHeap growth stopped after %.1f MB\n", total / 1048576.0);
    printf("Final program break: %p\n", sbrk(0));
    return 0;
}
