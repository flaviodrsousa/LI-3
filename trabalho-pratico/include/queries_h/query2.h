/**
 * @file query2.h
 * @brief Header file for Query 2 functionality.
 *
 * This file contains the declaration of functions related to Query 2 operations.
 * Query 2 involves processing and analyzing reservation and flight data stored in GHashTables,
 * as well as defining data structures like TreeV, TreeR, ListNode, and ListX.
 *
 * @author [Grupo35]
 */

#ifndef _QUERY2_
#define _QUERY2_

#include "../include/queries_h/query2.h"
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_reservations.h"

/**
 * @struct TreeV
 * @brief Structure to represent a node in the binary search tree for flights (TreeV).
 */
typedef struct TreeV TreeV;

/**
 * @struct TreeR
 * @brief Structure to represent a node in the binary search tree for reservations (TreeR).
 */
typedef struct TreeR TreeR;

/**
 * @struct ListNode
 * @brief Structure to represent a node in a linked list (ListNode).
 */
typedef struct ListNode ListNode;

/**
 * @struct ListX
 * @brief Structure to represent a linked list (ListX) with a top and last node.
 */
typedef struct ListX ListX;

/**
 * @brief Executes Query 2 operation on reservation and flight data.
 *
 * This function performs the Query 2 operation on reservation and flight data stored in GHashTables.
 * It takes input parameters such as GHashTables, strings, integers, and a type to filter and process
 * reservation and flight information based on specific criteria.
 *
 * @param reservations A GHashTable containing reservation information.
 * @param flights A GHashTable containing flight information.
 * @param users A GHashTable containing user information.
 * @param passengers A GHashTable containing passenger information.
 * @param input The input string for the operation.
 * @param type The type of operation to be performed.
 * @param t An integer parameter for the operation.
 * @param j An integer parameter for the operation.
 * @param l An integer parameter for the operation.
 */
void query2(GHashTable* reservations, GHashTable* flights, GHashTable* users, char* input, char* type, int t, int j, int l);

/**
 * @brief Creates a node for the binary search tree for flights (TreeV).
 *
 * This function creates a node for the binary search tree for flights (TreeV) used in Query 2.
 *
 * @param id_f The ID associated with the flight.
 * @param flight A pointer to the flight information.
 * @return A pointer to the created node.
 */
TreeV* criarNoV(char* id_f, Voo* flight);

/**
 * @brief Inserts a node into the binary search tree for flights (TreeV).
 *
 * This function inserts a node into the binary search tree for flights (TreeV) based on the flight ID
 * and associated flight information.
 *
 * @param raiz The root of the binary search tree.
 * @param id_f The flight ID for insertion.
 * @param f A pointer to the flight information for insertion.
 * @return The root of the modified binary search tree.
 */
TreeV* inserirV(TreeV* raiz, char* id_f, Voo* f);

/**
 * @brief Retrieves flights associated with a specific user.
 *
 * This function retrieves flights associated with a specific user from the binary search tree for flights (TreeV).
 *
 * @param passengers A GHashTable containing passenger information.
 * @param flights A GHashTable containing flight information.
 * @param input The user for filtering flights.
 * @return The root of the binary search tree for flights (TreeV) containing filtered flight data.
 */
TreeV* userFlights(GHashTable* passengers, GHashTable* flights, char* input);

/**
 * @brief Creates a node for the binary search tree for reservations (TreeR).
 *
 * This function creates a node for the binary search tree for reservations (TreeR) used in Query 2.
 *
 * @param id_r The ID associated with the reservation.
 * @param reservation A pointer to the reservation information.
 * @return A pointer to the created node.
 */
TreeR* criarNoR(char* id_r, Reserva* reservation);

/**
 * @brief Inserts a node into the binary search tree for reservations (TreeR).
 *
 * This function inserts a node into the binary search tree for reservations (TreeR) based on the reservation ID
 * and associated reservation information.
 *
 * @param raiz The root of the binary search tree.
 * @param id_r The reservation ID for insertion.
 * @param r A pointer to the reservation information for insertion.
 * @return The root of the modified binary search tree.
 */
TreeR* inserirR(TreeR* raiz, char* id_r, Reserva* r);

/**
 * @brief Retrieves reservations associated with a specific user.
 *
 * This function retrieves reservations associated with a specific user from the binary search tree for reservations (TreeR).
 *
 * @param reservations A GHashTable containing reservation information.
 * @param input The user for filtering reservations.
 * @return The root of the binary search tree for reservations (TreeR) containing filtered reservation data.
 */
TreeR* useReservations(GHashTable* reservations, char* input);

#endif /* _QUERY2_ */
