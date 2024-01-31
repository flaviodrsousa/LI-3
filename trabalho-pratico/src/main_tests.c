#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#include "../include/start_tests.h"

int main(int argc, char** argv) {
    clock_t start_time, end_time;

    start_time = clock();

    int prog = start_program_tests(argc, argv);

    end_time = clock();
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("CPU Time: %.8f seconds\n", cpu_time_used);

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);

    if (prog != 0) {
        printf("\n\n\n!!!Algo de errado aconteceu!!!\n\n\n");
    }

    return 0;
}