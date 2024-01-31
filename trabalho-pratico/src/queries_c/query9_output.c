#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include "../include/queries_h/query9.h"

struct KeyNomeId {
    gpointer key; /**< Pointer para a chave. */
    char *name;   /**< Pointer para o nome. */
    char *id;     /**< Pointer para o ID. */
};
void to_txt_9(int i, int sizeArray, KeyNomeId* arrayPares, int l) {
    if(l == 0){
    FILE *arquivo;
    char file[40]; 

    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    for(int i=0;i<sizeArray;i++){
        fprintf(arquivo, "%s;%s\n",(char*)arrayPares[i].id,arrayPares[i].name);
        free(arrayPares[i].name);
        free(arrayPares[i].id);
    }

    fclose(arquivo);
    } else if (l==1){
        for(int i=0;i<sizeArray;i++){
        printf("%s;%s\n",(char*)arrayPares[i].id,arrayPares[i].name);
        free(arrayPares[i].name);
        free(arrayPares[i].id);
        }
    }
}
void to_txt_9_1(int i, int sizeArray, KeyNomeId* arrayPares) {
    
    FILE *arquivo;
    char file[40]; 

    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    for(int i=0;i<sizeArray;i++){
        if(i == sizeArray-1) {
            fprintf(arquivo, "--- %d ---\n", i + 1);
            fprintf(arquivo, "id: %s\n", (char*)arrayPares[i].id);
            fprintf(arquivo, "name: %s\n", arrayPares[i].name);

        } else {
            fprintf(arquivo, "--- %d ---\n", i + 1);
            fprintf(arquivo, "id: %s\n", (char*)arrayPares[i].id);
            fprintf(arquivo, "name: %s\n\n", arrayPares[i].name);
        }
        free(arrayPares[i].name);
        free(arrayPares[i].id);
    }

    fclose(arquivo);
}