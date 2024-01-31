#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_reservations_aux.h"
#include "../include/queries_h/query1_output.h"
#include "../include/queries_h/query3_output.h"
#include "../include/structs_h/struct_reservations.h"

void query3 (GHashTable* reservation, char *input, int i, int type, int l){
    GHashTableIter iter;
    gpointer key, value;
    int x = 0;
    double ratingTotal=0;
    double mediaRating=0;
    char linha[100];
    int h = 0;

    g_hash_table_iter_init (&iter, reservation);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        char* id_hotel = getIdHotel(value);
        char* classificacao = getClassificacao(value);
        if (strcmp(input, id_hotel) == 0) {
            ratingTotal += atoi(classificacao);
            x++;
            h = 1;
            }
        free(id_hotel);
        free(classificacao);
        }
    if(h == 0 && l == 0){
        to_txt_0(i, " ");
    } else if (h != 0 && l == 0){ 
        if(type == 0){
    mediaRating=(ratingTotal)/(x);
    snprintf(linha, sizeof(linha),"%.3f\n",mediaRating);
    to_txt_0(i, linha);
    }
        else{
            mediaRating=(ratingTotal)/(x);
        snprintf(linha, sizeof(linha),"%.3f",mediaRating);
        to_txt_3(mediaRating, i);
        }
    } else if (h != 0 && l == 1){
        mediaRating=(ratingTotal)/(x);
        printf("Rating: %.3f\n",mediaRating);
    }
}
