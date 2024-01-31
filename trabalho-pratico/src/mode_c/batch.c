#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <sys/resource.h>
#include "../include/general_functions_h/general_functions.h"
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/interpreter_h/interpreter.h"

void batch(Catalogs* catalog_s, char *file) {

    char linha[1024];

if(file != NULL) {
    FILE *arquivo = fopen(file, "r");

    if (arquivo == NULL) {
        perror("Error opening file");
        return;
    }


    int j = 1;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *linha_copia = strdup(linha);
        if (linha_copia == NULL) {
            perror("Error duplicating string");
            break;
        }

        char *tokens[6];
        char *token = strtok(linha_copia, " \t\n");

        int i = 0;
        while (token != NULL && i < 6) {
            tokens[i] = token;
            i++;
            token = strtok(NULL, " \t\n");
        }

        interpreter(tokens, j, i, catalog_s,0);
        
        j++;
        
        free(linha_copia);
    }

    fclose(arquivo);

} else {

}
}