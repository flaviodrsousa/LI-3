/**
 * @file parser_passengers_functions.h
 * @brief Header file for passenger data processing functions.
 *
 * This file contains the declaration of functions responsible for processing passenger data.
 * The functions include setting passenger information, freeing memory, and handling passenger
 * data in GHashTables.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_PASSENGERS__H_
#define _CATALOG_PASSENGERS__H_

#include <glib.h>


/**
 * @brief Handles passenger data and stores it in GHashTables.
 *
 * This function processes passenger data, creates Passageiro structures, and stores them in GHashTables.
 *
 * @param nome The passenger's name.
 * @param tokens An array of tokens containing passenger information.
 * @param linha The entire line of passenger data.
 * @param hash_recebe A GHashTable for receiving processed passenger data.
 * @param hash1 A GHashTable for additional storage.
 * @param hash2 Another GHashTable for additional storage.
 */
void passengers_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1);



void create_passengers_catalog(char* path, GHashTable* users, GHashTable* flights);
#endif /* _CATALOG_PASSENGERS__H_ */
