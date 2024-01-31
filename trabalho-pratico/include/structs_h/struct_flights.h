/**
 * @file struct_flights.h
 * @brief Header file for flight data structures and functions.
 *
 * This file contains the declaration of structures and functions related to flight information.
 * The main structure is `Voo` representing flight details, and various functions are provided
 * for setting, creating, freeing, and accessing information within the flight structure.
 *
 * @author [Seu Nome]
 */

#ifndef _STRUCT_FLIGHTS_
#define _STRUCT_FLIGHTS_

#include <glib.h>
#include "../include/structs_h/struct_list.h"

/**
 * @struct Voo
 * @brief Structure to represent flight information.
 */
typedef struct voo Voo;

/**
 * @brief Structure to represent a list of flights.
 */
typedef struct lista Lista;

/**
 * @brief Sets flight information in a Voo structure.
 *
 * This function sets flight information in a Voo structure based on input parameters.
 *
 * @param flight A pointer to the Voo structure to be set.
 * @param companhia The airline company associated with the flight.
 * @param aviao The airplane model associated with the flight.
 * @param origem The departure location of the flight.
 * @param destino The destination of the flight.
 * @param p_e The estimated departure time of the flight.
 * @param c_e The estimated arrival time of the flight.
 * @param atraso The delay information associated with the flight.
 */
void set_voo(Voo* flight, char* companhia, char* aviao, char* origem, char* destino, char* p_e, char* c_e, char* atraso);

/**
 * @brief Creates a new Voo structure.
 *
 * @return A pointer to the newly created Voo structure.
 */
Voo* create_voo();

/**
 * @brief Frees memory allocated for a Voo structure.
 *
 * This function frees memory allocated for a Voo structure.
 *
 * @param flight A pointer to the Voo structure to be freed.
 */
void free_voo(Voo* flight);

/**
 * @brief Frees memory allocated for a GHashTable containing Voo structures.
 *
 * This function frees memory allocated for a GHashTable containing Voo structures.
 *
 * @param key The key associated with a Voo structure.
 * @param value A pointer to the Voo structure.
 * @param user_data Additional user data (not used in this context).
 */
void free_hash_tableV(gpointer key, gpointer value, gpointer user_data);

/**
 * @brief Gets the airline company associated with the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The airline company associated with the flight.
 */
char* getCompanhia(const Voo* flight);

/**
 * @brief Gets the airplane model associated with the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The airplane model associated with the flight.
 */
char* getAviao(const Voo* flight);

/**
 * @brief Gets the departure location of the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The departure location of the flight.
 */
char* getOrigem(const Voo* flight);

/**
 * @brief Gets the destination of the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The destination of the flight.
 */
char* getDestino(const Voo* flight);

/**
 * @brief Gets the estimated departure time of the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The estimated departure time of the flight.
 */
char* getPartidaEstimada(const Voo* flight);

/**
 * @brief Gets the estimated arrival time of the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The estimated arrival time of the flight.
 */
char* getChegadaEstimada(const Voo* flight);

/**
 * @brief Gets the delay information associated with the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The delay information associated with the flight.
 */
char* getAtraso(const Voo* flight);

/**
 * @brief Gets the number of passengers on the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return The number of passengers on the flight.
 */
int getN_Passageiros(const Voo* flight);

/**
 * @brief Gets the number of passengers on the flight from a Voo structure.
 *
 * @param flight A pointer to the Voo structure.
 * @return Increment the number of passengers on the flight.
 */
void incrementeN_Passageiros(Voo *flight);

#endif /* _STRUCT_FLIGHTS_ */
