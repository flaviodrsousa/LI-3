#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/structs_h/struct_flights.h"

int calculate_numeroPassageiros (GHashTable* flights, char *input){

return getN_Passageiros(g_hash_table_lookup(flights, input));

}

void write_passenger_error(const char* linha) {
    FILE *arquivo = fopen("Resultados/passengers_errors.csv", "a"); // Abre o arquivo em modo "append" para acrescentar ao final

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo passengers_errors.csv.\n");
        return;
    }

    fprintf(arquivo, "%s", linha); // Escreve a linha no arquivo
    fclose(arquivo); // Fecha o arquivo
}