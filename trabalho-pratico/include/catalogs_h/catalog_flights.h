/**
 * @file parser_flights_functions.h
 * @brief Header file for flight data processing functions.
 *
 * This file contains the declaration of functions responsible for processing flight data.
 * The functions include setting flight information, calculating delays, freeing memory,
 * and handling flight data in GHashTables.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_FLIGHTS__H_
#define _CATALOG_FLIGHTS__H_

#include <glib.h>

typedef struct catalog_flights Catalog_flights;

GHashTable* get_flights_hash(const struct catalog_flights* flight_catalog);

void free_catalog_flights(Catalog_flights* f);


/**
 * @brief Handles flight data and stores it in GHashTables.
 *
 * This function processes flight data, creates Voo structures, and stores them in GHashTables.
 *
 * @param nome The flight's name.
 * @param tokens An array of tokens containing flight information.
 * @param linha The entire line of flight data.
 * @param hash_recebe A GHashTable for receiving processed flight data.
 * @param hash1 A GHashTable for additional storage.
 * @param hash2 Another GHashTable for additional storage.
 */

void flights_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1);

Catalog_flights* create_flights_catalog(char* path);

void check_sits_flight(char* path, GHashTable* hash1);

void catalog_sits(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1);


//Lista* passengers();

#endif /* _CATALOG_FLIGHTS__H_ */
