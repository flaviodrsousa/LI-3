#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>

int u = 1;

void to_txt_4(char* id, char* begin_date, char* end_date, char* user_id, char* rating, double total_price, int i, int k) {
    FILE *arquivo;
    char file[40];
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- %d ---\n", u);
    fprintf(arquivo, "id: %s\n", id);
    fprintf(arquivo, "begin_date: %s\n", begin_date);
    fprintf(arquivo, "end_date: %s\n", end_date);
    fprintf(arquivo, "user_id: %s\n", user_id);
    fprintf(arquivo, "rating: %s\n", rating);
    fprintf(arquivo, "total_price: %0.3f\n", total_price);

    if(u!=k){
    fprintf(arquivo, "\n");
    }

    if(u<k){
        u++;
    } else {
        u=1;
    }

    fclose(arquivo);
}