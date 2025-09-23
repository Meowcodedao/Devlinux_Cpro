/*
 * memory_lab.c
 *
 * Usage:
 *   ./memory_lab stack_overflow
 *   ./memory_lab memory_leak
 *   ./memory_lab out_of_memory
 *
 * Compile with debug symbols:
 *   gcc -g -O0 memory_lab.c -o memory_lab
 *
 * Note: -g và -O0 để GDB hoạt động dễ dàng và tránh tối ưu làm biến biến mất.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* --- STACK OVERFLOW --- */
/* Use a reasonably large local buffer to consume stack quickly.
 * volatile để tránh bị compiler tối ưu bỏ. */
void recurse_stack(size_t depth) {
    volatile char buffer[65536]; /* 64KB per frame -> nhanh tràn stack */
    /* Touch buffer so compiler doesn't optimize it away */
    memset((void*)buffer, (int)(depth & 0xFF), sizeof(buffer));

    if (depth % 10 == 0) {
        printf("[stack] depth = %zu\n", depth);
        fflush(stdout);
    }

    /* Tail-call optimizations may interfere; recursion with observable side-effects avoids it. */
    recurse_stack(depth + 1);
}

/* --- MEMORY LEAK / OUT OF MEMORY --- */
void leak_until_oom(size_t alloc_size, int quiet) {
    size_t count = 0;
    for (;;) {
        void *p = malloc(alloc_size);
        if (!p) {
            fprintf(stderr, "[oom] malloc returned NULL after %zu allocations (%zu bytes)\n",
                    count, count * alloc_size);
            /* safe exit after OOM detected */
            exit(EXIT_FAILURE);
        }

        /* Touch memory to ensure pages are actually committed */
        memset(p, 0, alloc_size);

        /* Intentionally do NOT free(p) -> memory leak */
        count++;

        if (!quiet && (count % 1024) == 0) {
            /* report every ~1MB if alloc_size=1024 */
            printf("[leak] allocated %zu blocks (%zu KB)\n", count, (count * alloc_size) / 1024);
            fflush(stdout);
        }

        /* optional small sleep to slow down so you can attach debugger */
        /* usleep(1000); */
    }
}

void usage(const char *argv0) {
    fprintf(stderr,
            "Usage: %s <mode>\n"
            "Modes:\n"
            "  stack_overflow    -> cause stack overflow via recursion\n"
            "  memory_leak       -> leak memory until OOM (alloc 1KB per loop, no free)\n"
            "  out_of_memory     -> same as memory_leak (detect malloc==NULL and exit)\n",
            argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 2) usage(argv[0]);

    if (strcmp(argv[1], "stack_overflow") == 0) {
        printf("Starting stack overflow test...\n");
        fflush(stdout);
        /* It's useful to set ulimit -s smaller or leave default; recursion will continue until segfault. */
        recurse_stack(1);
    } else if (strcmp(argv[1], "memory_leak") == 0 ||
               strcmp(argv[1], "out_of_memory") == 0) {
        size_t alloc_size = 1024; /* 1 KB per allocation */
        int quiet = 0;
        printf("Starting memory leak test (alloc %zu bytes repeatedly)...\n", alloc_size);
        fflush(stdout);
        leak_until_oom(alloc_size, quiet);
    } else {
        usage(argv[0]);
    }

    return 0;
}

