// Tutor : ChatGPT

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const size_t step = 1024 * 1024;  // allocate 1 MB at a time
    size_t total = 0;
    void **blocks = NULL;             // store pointers to avoid freeing early

    while (1) {
        void *ptr = malloc(step);
        if (!ptr) {
            perror("malloc failed");
            break;
        }

        total += step;
        blocks = realloc(blocks, (total / step) * sizeof(void *));
        if (!blocks) {
            perror("realloc failed");
            break;
        }
        blocks[(total / step) - 1] = ptr;

        if ((total / step) % 100 == 0) {
            printf("Allocated total: %.1f MB\n", total / 1048576.0);
            fflush(stdout);
        }
    }

    printf("\nStopped after %.1f MB allocated.\n", total / 1048576.0);

    // keep memory until exit so you can inspect /proc/<pid>/maps
    getchar();

    // free all blocks
    for (size_t i = 0; i < total / step; ++i)
        free(blocks[i]);
    free(blocks);

    return 0;
}
