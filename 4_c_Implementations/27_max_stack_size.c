#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("Current stack limit: %ld bytes\n", limit.rlim_cur);
        printf("Maximum stack limit: %ld bytes\n", limit.rlim_max);
    } else {
        perror("getrlimit failed");
    }

    return 0;
}