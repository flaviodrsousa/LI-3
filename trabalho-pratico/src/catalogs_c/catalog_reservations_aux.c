#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/structs_h/struct_reservations.h"

int check_null_camp_res(char* tokens[]) {
    
    if(strlen(tokens[0]) > 0 && strlen(tokens[1]) > 0 && strlen(tokens[2]) > 0 && strlen(tokens[3]) > 0 && strlen(tokens[6]) > 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_hotel_stars(const char* star) {
    char *endptr;
    long value = strtol(star, &endptr, 10);

    if (*endptr == '\0' && (value >= 1 && value <= 5)) {
        return 0;
    } else {
        return 1;
    }
}

int check_city_tax(char* city) {
    char *endptr;
    long value = strtol(city, &endptr, 10);

    if(*endptr == '\0' && value >= 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_price_per_night(char* night) {
    char *endptr;
    long value = strtol(night, &endptr, 10);

    if(*endptr == '\0' && value > 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_includes_breakfast(char* breakfast) {
    if(strncasecmp(breakfast, "f", strlen(breakfast)) == 0 || strncasecmp(breakfast, "false", strlen(breakfast)) == 0 || strncasecmp(breakfast, "0", strlen(breakfast)) == 0 || strncasecmp(breakfast, "t", strlen(breakfast)) == 0 || strncasecmp(breakfast, "true", strlen(breakfast)) == 0 || strncasecmp(breakfast, "1", strlen(breakfast)) == 0 || strlen(breakfast) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_classification(char *classification) {
    char *endptr;
    long value = strtol(classification, &endptr, 10);

    if(*endptr == '\0' && (value >= 1 && value <= 5)) {
        return 0;
    } else {
        return 1;
    }
}

int calculate_numeroReservas (GHashTable* reservation, char *input){
    GHashTableIter iter;
    gpointer key, value;
    int x = 0;

    g_hash_table_iter_init (&iter, reservation);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        char* user = getIdUser(value);
        if (strcmp(input, user) == 0) {x++;};
        free(user);
    }
    return x;
}

int calculate_n_noites(char* data1, char* data2) {
    int y1, m1, d1;
    sscanf(data1, "%d/%d/%d", &y1, &m1, &d1);

    int y2, m2, d2;
    sscanf(data2, "%d/%d/%d", &y2, &m2, &d2);

    return (d2 - d1);
}

char* calculate_pequeno_almoco(char* pa) {
    char* res = NULL;

    if (strncasecmp(pa, "f", strlen(pa)) == 0 || strncasecmp(pa, "false", strlen(pa)) == 0 || strncasecmp(pa, "0", strlen(pa)) == 0) {
        res = "False";
    } else {
        res = "True";
    }

    return res;
}

double calculate_preco_total(int n_noites, char* preco_noite, char* imposto_da_cidade) {
    int precoNoite = atoi(preco_noite);
    int imposto = atoi(imposto_da_cidade);

    double precoTotal = precoNoite * n_noites + ((precoNoite * n_noites / 100.0) * imposto);

    return precoTotal;
}

double calculate_totalGasto (GHashTable* reservation, char *input){
    GHashTableIter iter;
    gpointer key, value;
    double x = 0;

    g_hash_table_iter_init (&iter, reservation);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        char* user = getIdUser(value);
        if (strcmp(input, user) == 0) {
            x+= getPrecoTotal(value);
            }
        free(user);
    }
    return x;
}

void write_reservation_error(char *linha) {
    FILE *arquivo = fopen("Resultados/reservations_errors.csv", "a"); // Abre o arquivo em modo "append" para acrescentar ao final

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo user_errors.csv.\n");
        return;
    }

    fprintf(arquivo, "%s", linha); // Escreve a linha no arquivo
    fclose(arquivo); // Fecha o arquivo
}