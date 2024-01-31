#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_list.h"

int check_null_camp_fli(char* tokens[]) {
    
    if(strlen(tokens[0]) > 0 && strlen(tokens[1]) > 0 && strlen(tokens[2]) > 0 && strlen(tokens[10]) > 0 && strlen(tokens[11]) > 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_airport(char* air) {
    if(strlen(air) == 3) {
        return 0;
    } else {
        return 1;
    }
}
 
int check_sits(int n, char* n_sits) {
    int sits = atoi(n_sits);
    if(sits>n) return 0;
    return 1;
}



int calculate_numeroVoos(GHashTable* users, char* input) {

    int res = 0;
    List *value = getListUser(g_hash_table_lookup(users,input));
    List * temp = value;
    while (temp != NULL) {
        res++;
        temp = getNextList(temp);
    }


    return res;
}


char* calculate_atraso(char* data_estimada, char* data_real) {
   char resultado[9];
    int ye, me, de, he, mine, se;
    sscanf(data_estimada, "%d/%d/%d %d:%d:%d", &ye, &me, &de, &he, &mine, &se);

    int yr, mr, dr, hr, minr, sr;
    sscanf(data_real, "%d/%d/%d %d:%d:%d", &yr, &mr, &dr, &hr, &minr, &sr);

    if (de == dr) {
        int difh, difm, difs;
        difh = hr - he;
        difm = minr - mine;
        difs = sr - se;
        snprintf(resultado, sizeof(resultado), "%d", (difh*3600+difm*60+difs));

        char* atraso_str = (char*)malloc(strlen(resultado) + 1);
        strcpy(atraso_str, resultado);

        return atraso_str;

    } else {
        int difh, difm, difs, difd;
        difd = dr-de;
        difh = difd * 24 + (hr - he);
        difm = minr - mine;
        difs = sr - se;
        snprintf(resultado, sizeof(resultado), "%d", (difh*3600+difm*60+difs));

        char* atraso_str = (char*)malloc(strlen(resultado) + 1);
        strcpy(atraso_str, resultado);

        return NULL;
    }
}

void write_flights_error(char *linha) {
    FILE *arquivo = fopen("Resultados/flights_errors.csv", "a"); // Abre o arquivo em modo "append" para acrescentar ao final

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo user_erros.csv.\n");
        return;
    }

    fprintf(arquivo, "%s", linha); // Escreve a linha no arquivo
    fclose(arquivo); // Fecha o arquivo
}
