#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>

int o = 1;

void to_txt_6F(int i, const char *nome, int passengers, int n) {
    FILE *arquivo;
    char file[40];

    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }
        fprintf(arquivo, "--- %d ---\n", o);
        fprintf(arquivo, "name: %s\n", nome);
        fprintf(arquivo, "passengers: %d\n", passengers);
    
    if(o!=n){
    fprintf(arquivo, "\n");
    }

    if(o<n){
        o++;
    } else {
        o=1;
    }

    fclose(arquivo);
}