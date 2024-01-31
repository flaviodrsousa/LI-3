#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/catalogs_h/catalog_flights.h"

void parser(char *nome, int tamanho, void (*function)(char* nome1, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1), GHashTable* hash, GHashTable* hash_01) {   
    char *nome_arquivo = nome;
    char linha[1024];

    FILE *arquivo = fopen(nome_arquivo, "r");

    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
    
        char *linha_copia = strdup(linha);
        char *tokens[tamanho]; 
        int i = 0;
    
        char *token = strsep(&linha_copia, ";");
        
    
        while (token && i < tamanho) {
            tokens[i] = token;
            i++;
            token = strsep(&linha_copia, ";");
        }

        function(nome, tokens, linha, hash, hash_01);
        
        
    }

    fclose(arquivo);
}
