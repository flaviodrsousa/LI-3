#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>

void to_txt_8F(int i, const char *linha) {
    
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    if(strcmp(linha, "") != 0) {
        fprintf(arquivo, "--- 1 ---\n");
        fprintf(arquivo, "revenue: %s", linha);
    }

    fclose(arquivo);
}