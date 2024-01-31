/**
 * @file _struct_hash_.h
 * @brief Header file for creating and managing a GHashTable.
 */

#ifndef _STRUCT_HASH_
#define _STRUCT_HASH_

#include <glib.h>

/**
 * @brief Creates a new GHashTable.
 *
 * This function initializes and returns a new GHashTable.
 *
 * @return A pointer to the newly created GHashTable.
 */
GHashTable* create_hash();

#endif
