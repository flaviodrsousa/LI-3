#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>


int w = 1;

void to_txt_5(char* id, char* departure, char* destination, char* airline, char* plane, int i, int k) {
    FILE *arquivo;
    char file[40];
    
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- %d ---\n", w);
    fprintf(arquivo, "id: %s\n", id);
    fprintf(arquivo, "schedule_departure_date: %s\n", departure);
    fprintf(arquivo, "destination: %s\n", destination);
    fprintf(arquivo, "airline: %s\n", airline);
    fprintf(arquivo, "plane_model: %s\n", plane);
    if(w!=k){
        fprintf(arquivo, "\n");
    }

    if(w<k){
        w++;
    } else {
        w=1;
    }

    fclose(arquivo);
}
