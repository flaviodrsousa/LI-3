#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/catalogs_h/catalog_users.h"
#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_hash.h"
#include "../include/parser_h/parser.h"

struct catalog_users {
    GHashTable* users_hash; ///< Hash table containing user information.
};

GHashTable* get_users_hash(const struct catalog_users* user_catalog) {
    return user_catalog->users_hash;
}

void free_catalog_users(Catalog_users* u) {
    free(u->users_hash);
}

void user_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1) { 

    if(check_null_camp_urs(tokens) || check_email(tokens[2]) ||check_date(tokens[4]) || check_country_code(tokens[7]) || check_date_time(tokens[9]) || check_status(tokens[11]) || compare_date(tokens[4], tokens[9])) {
        write_user_error(linha);
        return;
            } else {
                int status = 0;
                if(strncasecmp(tokens[11], "active", 6) == 0) status = 1;

                Utilizador* usr = create_usr();

                int idade = calculate_age(tokens[4]);

                set_utilizador(usr, tokens[1], tokens[5], idade, tokens[7], tokens[6], status);
                g_hash_table_insert(hash_recebe, tokens[0], usr);
                
        }

        //freeTokens(tokens, 13);
}

Catalog_users* create_users_catalog(char* path) {
    
    Catalog_users* u_catalog = malloc(sizeof(Catalog_users));
    
    u_catalog->users_hash = create_hash();
    
    parser(path, 12, user_hash, u_catalog->users_hash, NULL);
    
    return u_catalog;
}