#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/catalogs_h/catalog_flights_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_hash.h"
#include "../include/parser_h/parser.h"


//Ter uma struct catalog_flights
struct catalog_flights {
    GHashTable* flights_hash; ///< Hash table containing flight information.
};

GHashTable* get_flights_hash(const struct catalog_flights* flight_catalog) {
    return flight_catalog->flights_hash;
}

void free_catalog_flights(Catalog_flights* f) {
    free(f->flights_hash);
}

void flights_hash (char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1) {
    if(check_null_camp_fli(tokens) || check_airport(tokens[4]) || check_airport(tokens[5]) || check_date_time(tokens[6]) || check_date_time(tokens[7]) || check_date_time(tokens[8]) || check_date_time(tokens[9]) || compare_date_time(tokens[6], tokens[7]) || compare_date_time(tokens[8], tokens[9])) {
            write_flights_error(linha);
        } else {

            Voo* flight = create_voo();
            char* atraso = calculate_atraso(tokens[6], tokens[8]);
            set_voo(flight, tokens[1], tokens[2], tokens[4], tokens[5], tokens[6], tokens[7], atraso);
            free(atraso);

            g_hash_table_insert(hash_recebe, tokens[0], flight);
        }

}

Catalog_flights* create_flights_catalog(char* path) {
    
    Catalog_flights* f_catalog = malloc(sizeof(Catalog_flights));
    
    f_catalog->flights_hash = create_hash();
    
    parser(path, 13, flights_hash, f_catalog->flights_hash, NULL);
    
    return f_catalog;
}


void catalog_sits(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1) {

    if(g_hash_table_contains(hash_recebe, tokens[0])) {
        int n = getN_Passageiros(g_hash_table_lookup(hash_recebe, tokens[0]));
    
        if(check_sits(n,tokens[3])) {
                write_flights_error(linha);
                Voo* flight = (Voo*)g_hash_table_lookup(hash_recebe,tokens[0]);
                free_voo(flight);
                g_hash_table_remove(hash_recebe, tokens[0]);
        }
    }
    
}



void check_sits_flight(char* path, GHashTable* hash1) {
    parser(path, 13, catalog_sits, hash1, NULL);
}

