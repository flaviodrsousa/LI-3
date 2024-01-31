#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <locale.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/queries_h/query9.h"
#include "../include/queries_h/query9_output.h"
#include "../include/structs_h/struct_users.h"

struct KeyNomeId {
    gpointer key; /**< Pointer para a chave. */
    char *name;   /**< Pointer para o nome. */
    char *id;     /**< Pointer para o ID. */
};

int comparaPares(const void *a, const void *b) {
    const KeyNomeId *parA = (const KeyNomeId *)a;
    const KeyNomeId *parB = (const KeyNomeId *)b;

    int comparaNomes = strcoll(parA->name, parB->name);
    if (comparaNomes != 0) {
        return comparaNomes;
    }
    return strcoll(parA->id, parB->id);
}


void query9(GHashTable *users, char *input, int j, int type, int l) {
    GHashTableIter iter;
    gpointer key, value;
    int x = strlen(input);

    setlocale(LC_COLLATE, "en_US.UTF-8");

    KeyNomeId *arrayPares = NULL;
    int sizeArray = 0;

    g_hash_table_iter_init(&iter, users);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char *userName = getNome(value);  
        int statuses = getStatus(value);
        if (strncmp(input, userName, x) == 0 && statuses == 1) {
            arrayPares = realloc(arrayPares, (sizeArray + 1) * sizeof(KeyNomeId));
            arrayPares[sizeArray].key = key;
            arrayPares[sizeArray].name = strdup(userName);
            arrayPares[sizeArray].id = strdup(key);
            sizeArray++;
        }
        free(userName);
    }

    qsort(arrayPares, sizeArray, sizeof(KeyNomeId), comparaPares);

    if (type == 0 && l == 0) {
        to_txt_9(j, sizeArray, arrayPares,l);
    } else if (type == 1 && l == 0) {
        to_txt_9_1(j, sizeArray, arrayPares);
    } else if (type == 0 && l == 1){
        to_txt_9(j, sizeArray, arrayPares,l);
    }

    free(arrayPares);
}
