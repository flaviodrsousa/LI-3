#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>

void to_txt_3(double mediaRating, int i) {
    
    FILE *arquivo;
    char file[40];

    
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- 1 ---\n");
    fprintf(arquivo, "rating: %0.3f\n", mediaRating);

    fclose(arquivo);
}