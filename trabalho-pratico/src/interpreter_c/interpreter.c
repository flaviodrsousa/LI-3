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
#include "../include/queries_h/query1.h"
#include "../include/queries_h/query2.h"
#include "../include/queries_h/query3.h"
#include "../include/queries_h/query4.h"
#include "../include/queries_h/query5.h"
#include "../include/queries_h/query6.h"
#include "../include/queries_h/query8.h"
#include "../include/queries_h/query9.h"
#include "../include/queries_h/query1_output.h"

// TODO: Alterar o return do interpreter

void interpreter(char** tokens, int j, int i, Catalogs* catalog_s, int l) {

    GHashTable* users = get_users_hash(get_user_catalog(catalog_s));
    GHashTable* flights = get_flights_hash(get_flight_catalog(catalog_s));
    GHashTable* reservations = get_reservations_hash(get_reservation_catalog(catalog_s));

    if (strcmp(tokens[0], "1") == 0 || strcmp(tokens[0], "1F") == 0) {
            query1(reservations, flights, users, tokens[1], j, (strcmp(tokens[0], "1F") == 0) ? 1 : 0, l);
        } else if (strcmp(tokens[0], "2") == 0 || strcmp(tokens[0], "2F") == 0) {
            query2(reservations, flights, users, tokens[1], (i < 3) ? "" : tokens[2], (strcmp(tokens[0], "2F") == 0) ? 1 : 0, j, l);
            
        } else if (strcmp(tokens[0], "3") == 0 || strcmp(tokens[0], "3F") == 0)  {
            query3(reservations, tokens[1], j, (strcmp(tokens[0], "3F") == 0) ? 1 : 0, l);
            
        } else if (strcmp(tokens[0], "4") == 0 || strcmp(tokens[0], "4F") == 0 ) {
            query4(reservations, tokens[1], j, (strcmp(tokens[0], "4F") == 0) ? 1 : 0, l);
            
        } else if (strcmp(tokens[0], "5") == 0 || strcmp(tokens[0], "5F") == 0) {
            char data1[100];
            char data2[100];

            strcpy(data1, tokens[2]);
            strcat(data1, " ");
            strcat(data1, tokens[3]);

            strcpy(data2, tokens[4]);
            strcat(data2, " ");
            strcat(data2, tokens[5]);

            removeChar(data1, '"');
            removeChar(data2, '"');
            query5(flights, tokens[1], data1, data2, j, (strcmp(tokens[0], "5F") == 0) ? 1 : 0, l);
            
        } else if(strcmp(tokens[0], "6") == 0 || strcmp(tokens[0], "6F") == 0 ) {
            query6(flights,tokens[1], atoi(tokens[2]), j, (strcmp(tokens[0], "6F") == 0) ? 1 : 0,l);
        } else if (strcmp(tokens[0], "7") == 0) {
            //printf("Não implementado");
            

        } else if (strcmp(tokens[0], "8") == 0 || strcmp(tokens[0], "8F") == 0)  {
            
            query8(reservations, tokens[1], tokens[2], tokens[3], j, (strcmp(tokens[0], "8F") == 0) ? 1 : 0, l);
            //void query8 (GHashTable* reservation, char *id, char *begin, char *end, int type, int l){
            
        } else if (strcmp(tokens[0], "9") == 0 || strcmp(tokens[0], "9F") == 0) {
            if (strcmp(tokens[2], "") == 0) {
                query9(users, tokens[1], j, (strcmp(tokens[0], "9F") == 0) ? 1 : 0,l);
        
            } else {
                char resultado[100];
                strcpy(resultado, tokens[1]);

        
                if (strlen(resultado) == 1) {
                query9(users, resultado, j, (strcmp(tokens[0], "9F") == 0) ? 1 : 0,l);
            
                } else {
                    for (int i = 0; resultado[i] != '\0'; i++) {
                        if (resultado[i] == '\"') {
                            int j = i;
                            while (resultado[j] != '\0') {
                                resultado[j] = resultado[j + 1];
                                j++;
                        
                }
            i--; 
            }
        }

            char copyTokenTwo[100];

            strcat(resultado, " ");
            strcpy(copyTokenTwo, tokens[2]);
            strcat(resultado, tokens[2]);
            strcpy(tokens[2], "\0");

            
            int compr = strlen(resultado);
            while (compr > 0 && resultado[compr - 1] == '\"') {
                resultado[compr - 1] = '\0';
                compr--;
            }

            query9(users, resultado, j, (strcmp(tokens[0], "9F") == 0) ? 1 : 0,l);
            
        }
    }
        } else if (strcmp(tokens[0], "10") == 0) {
            //printf("Não implementado");
            
        } else {
            //printf("Erro no número de query");
            
        }

}




