#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/general_functions_h/general_functions.h"
#include "../include/catalogs_h/catalog_reservations_aux.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/structs_h/struct_reservations.h"
#include "../include/structs_h/struct_hash.h"
#include "../include/parser_h/parser.h"

struct catalog_reservations {
    GHashTable* reservations_hash; ///< Hash table containing reservation information.
};

GHashTable* get_reservations_hash(const struct catalog_reservations* reservation_catalog) {
    return reservation_catalog->reservations_hash;
}

void free_catalog_reservations(Catalog_reservations* r) {
    free(r->reservations_hash);
}

void reservation_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1) {
    gchar* value = (gchar*)g_hash_table_lookup(hash1, tokens[1]);
    
    if (value == NULL || check_null_camp_res(tokens) || check_hotel_stars(tokens[4]) || check_city_tax(tokens[5]) || check_date(tokens[7]) || check_date(tokens[8]) || compare_date(tokens[7], tokens[8]) || check_price_per_night(tokens[9]) || check_includes_breakfast(tokens[10]) || check_classification(tokens[12])) {
        write_reservation_error(linha);
    } else {
        Reserva* reservation = create_res();
        set_reserva(reservation, tokens[1], tokens[2] ,tokens[3], tokens[4], tokens[7], tokens[8], calculate_pequeno_almoco(tokens[10]), calculate_preco_total(calculate_n_noites(tokens[7], tokens[8]), tokens[9], tokens[5]),tokens[9], tokens[12]);
        g_hash_table_insert(hash_recebe, tokens[0], reservation);

    }

    //freeTokens(tokens, 14);
    
}

Catalog_reservations* create_reservations_catalog(char* path, GHashTable* users) {
    
    Catalog_reservations* r_catalog = (Catalog_reservations*)malloc(sizeof(Catalog_reservations));
    
    r_catalog->reservations_hash = create_hash();
    
    parser(path, 14, reservation_hash, r_catalog->reservations_hash, users);
    
    return r_catalog;
}



