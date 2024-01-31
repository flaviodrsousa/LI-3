/**
 * @file struct_passengers.h
 * @brief Header file for passenger data structures and functions.
 *
 * This file contains the declaration of structures and functions related to passenger information.
 * The main structure is `Passageiro` representing passenger details, and various functions are provided
 * for setting, creating, freeing, and accessing information within the passenger structure.
 *
 * @author [Seu Nome]
 */

#ifndef _STRUCT_PASSENGERS_
#define _STRUCT_PASSENGERS_

#include <glib.h>

/**
 * @struct Passageiro
 * @brief Structure to represent passenger information.
 */
typedef struct passageiro Passageiro;

/**
 * @brief Sets passenger information in a Passageiro structure.
 *
 * This function sets passenger information in a Passageiro structure based on input parameters.
 *
 * @param p A pointer to the Passageiro structure to be set.
 * @param f The flight associated with the passenger.
 * @param u The user associated with the passenger.
 */
Passageiro* set_passageiro(const char* data);

/**
 * @brief Frees memory allocated for a Passageiro structure.
 *
 * This function frees memory allocated for a Passageiro structure.
 *
 * @param passageiro A pointer to the Passageiro structure to be freed.
 */
void free_passageiro(Passageiro* passageiro);

/**
 * @brief Frees memory allocated for a GHashTable containing Passageiro structures.
 *
 * This function frees memory allocated for a GHashTable containing Passageiro structures.
 *
 * @param key The key associated with a Passageiro structure.
 * @param value A pointer to the Passageiro structure.
 * @param user_data Additional user data (not used in this context).
 */
void free_hash_tableP(gpointer key, gpointer value, gpointer user_data);

/**
 * @brief Gets the user associated with the passenger from a Passageiro structure.
 *
 * @param passengers A pointer to the Passageiro structure.
 * @return The user associated with the passenger.
 */
char* getUser(const Passageiro* passengers);

/**
 * @brief Sets the next passenger pointer for a given passenger.
 *
 * This function sets the next passenger pointer of a given passenger structure
 * to point to another passenger structure, establishing a link between them.
 *
 * @param pass A pointer to the passenger whose next pointer will be set.
 * @param nex A pointer to the next passenger in the sequence.
 */
void setNext(Passageiro* pass, Passageiro* nex);

/**
 * @brief Retrieves a pointer to the next passenger in the sequence.
 *
 * This function returns a pointer to the passenger structure that follows
 * the given passenger in the sequence.
 *
 * @param passenger A pointer to the passenger whose next pointer will be retrieved.
 * @return A pointer to the next passenger in the sequence.
 */
Passageiro* getNext(const Passageiro* passenger);

#endif /* _STRUCT_PASSENGERS_ */
