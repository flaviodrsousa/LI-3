/**
 * @file catalog_reservations.h
 * @brief Header file for managing reservations in a catalog.
 *
 * This file contains the declaration of functions related to managing reservations in a catalog.
 * The functions include creating a reservation hash, which involves processing reservation data
 * and storing it in multiple hash tables for efficient retrieval and manipulation.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_RESERVATIONS_H_
#define _CATALOG_RESERVATIONS_H_


typedef struct catalog_reservations Catalog_reservations;

GHashTable* get_reservations_hash(const struct catalog_reservations* reservation_catalog);

void free_catalog_reservations(Catalog_reservations* r);


/**
 * @brief Creates and populates hash tables with reservation data.
 *
 * This function processes reservation data, such as a reservation name, tokens, and a full line of data,
 * and populates multiple hash tables for efficient retrieval and manipulation of reservation information.
 * It is designed to work with three separate hash tables, which are passed as parameters.
 *
 * @param nome The name associated with the reservation.
 * @param tokens An array of tokens containing reservation information.
 * @param linha The full line of reservation data.
 * @param hash_recebe The main hash table to receive the reservation data.
 * @param hash1 The first auxiliary hash table for additional data processing.
 * @param hash2 The second auxiliary hash table for further data processing.
 */
void reservation_hash(char* nome, char** tokens, char* linha, GHashTable* hash_recebe, GHashTable* hash1);


Catalog_reservations* create_reservations_catalog(char* path, GHashTable* users);

#endif /* _CATALOG_RESERVATIONS_H_ */
