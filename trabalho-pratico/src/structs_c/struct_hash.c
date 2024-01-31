#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/general_functions_h/general_functions.h"


GHashTable* create_hash() {
    GHashTable* hash = g_hash_table_new_full(g_str_hash, g_str_equal, free_key_value, free_key_value);
    return hash;
}