#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/catalogs_h/catalog_passengers_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/catalogs_h/catalog_passengers.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/structs_h/struct_passengers.h"
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_hash.h"
#include "../include/structs_h/struct_list.h"
#include "../include/parser_h/parser.h"

void passengers_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1) {
    size_t len = strlen(tokens[1]);
    tokens[1][len - 1] = '\0';

    Voo *flight = (Voo*)g_hash_table_lookup(hash_recebe, tokens[0]);
    Utilizador *user = (Utilizador*)g_hash_table_lookup(hash1, tokens[1]);

    if (flight == NULL || user == NULL) {
        write_passenger_error(linha);
    } else {

        List *lista_voos = (List*)getListUser(user);
        if (lista_voos != NULL) {
            List* temp0 = lista_voos;
            while(getNextList(temp0) != NULL) temp0 = getNextList(temp0);
            setNext(temp0, set_list(tokens[0])); 
        } else {
            List* new = set_list(tokens[0]);
            setListUser(user, new);
        }

        incrementeN_Passageiros(flight);
    
        
    }
}

void create_passengers_catalog(char* path, GHashTable* users, GHashTable* flights) {
    
    parser(path, 2, passengers_hash, flights, users);    
    
}





