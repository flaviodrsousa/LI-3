#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/catalogs_h/catalog_passengers.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/queries_h/query1_output.h"
#include "../include/menu_h/interface.h"
#include "../include/queries_h/query6_output.h"
#include "../include/structs_h/struct_flights.h"

#define MAX_AIRPORTS 1000

typedef struct Airport{
    char name[50];
    int passengers;
} Airport;

int compareAirports(const void *a, const void *b) {
    const Airport *airportA = (const Airport *)a;
    const Airport *airportB = (const Airport *)b;

    return airportB->passengers - airportA->passengers;
}

void airportStore(GHashTable *flights, char* y, int n, int j, int type, int l) {
    Airport airports[MAX_AIRPORTS];
    int num_airports = 0;

    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, flights);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char resultadoD[4];
        char resultadoO[4];
        int np = getN_Passageiros(value);
        char* date = getPartidaEstimada(value);

        for (int l = 0; l < 4; l++) {
            if(l<3){
                char* dest = getDestino(value);
                resultadoD[l] = toupper(dest[l]);
                free(dest);
            } else {resultadoD[l] = '\0';}
        }

        for (int l = 0; l < 4; l++) {
            if(l<3){
            char* ori = getOrigem(value);
            resultadoO[l] = toupper(ori[l]);
            free(ori);
        } else {resultadoO[l] = '\0';}
    }

        if (compare_year(y,date) == 1) {
            int inArray = 0;
            for (int i = 0; i < num_airports; i++) {
                if (strcmp(airports[i].name, resultadoO) == 0) {
                    airports[i].passengers += np;
                    inArray = 1;
                    break;
                }
            }
            
            if (!inArray && num_airports < MAX_AIRPORTS) {
                strcpy(airports[num_airports].name, resultadoO);
                airports[num_airports].passengers = np;
                num_airports++;
            }

            inArray = 0;
            for (int i = 0; i < num_airports; i++) {
                if (strcmp(airports[i].name, resultadoD) == 0) {
                    airports[i].passengers += np;
                    inArray = 1;
                    break;
                }
            }
            
            if (!inArray && num_airports < MAX_AIRPORTS) {
                strcpy(airports[num_airports].name, resultadoD);
                airports[num_airports].passengers = np;
                num_airports++;
            }
        }
    }
    qsort(airports, num_airports, sizeof(Airport), compareAirports);

    char linha[1024];
    for (int k = 0; k < n && k < num_airports; k++) {
        if(type == 0 && l == 0){
            snprintf(linha, sizeof(linha),"%s;%d\n",airports[k].name, airports[k].passengers);
            to_txt_0(j,linha);
        } else if(type == 1 && l == 0) {
            to_txt_6F(j,airports[k].name, airports[k].passengers,n);
        } else if(type == 0 && l == 1){
            int currentPage = 1;
            int airportsPerPage = 10;

            for (int k = 0; k < num_airports; k++) {
                if ((k % airportsPerPage) == 0) {
            system("clear");
            pageN(currentPage);
            currentPage++;
        }

            printf("name: %s\n", airports[k].name);
            printf("passengers: %d\n", airports[k].passengers);

            if ((k + 1) % airportsPerPage == 0) {
            char choice;
            pageBar();
            scanf(" %c", &choice);
            if (choice == 'Q' || choice == 'q') {
                printf("Exiting...\n");
                return;
                    }
                }
            }
        }
    }
}
void query6(GHashTable *flights,char* y, int n, int j, int i, int l){
    airportStore(flights,y,n,j,i,l);
}
