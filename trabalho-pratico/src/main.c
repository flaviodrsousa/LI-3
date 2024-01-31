#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/start.h"


int main(int argc, char** argv) {
    

    //Medir o tempo de execução
    //struct timespec start, end;
    //double elapsed;
    //Start time
    //lock_gettime(CLOCK_REALTIME, &start);

    

    /*--------------------------------------------------------------------------------------------------------------------------------------------*/
    
    int prog = start_program(argc, argv);
    if(prog != 0) {
        printf("\n\n\n!!!Algo de errado aconteceu!!!\n\n\n");
    }

    /*--------------------------------------------------------------------------------------------------------------------------------------------*/
    
    

    //Medir a memória usada
    //struct rusage r_usage;
    //getrusage(RUSAGE_SELF, &r_usage);
    //printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);


    //Medir o tempo de execução
    //End time
    //clock_gettime(CLOCK_REALTIME, &end);
    //Elapsed time
    //elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9; 
    //printf("Elapsed time: %.6f seconds\n", elapsed);


return 0;
}
