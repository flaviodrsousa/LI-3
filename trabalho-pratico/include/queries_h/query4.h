/**
 * @file query4.h
 * @brief Header file for Query 4 functionality.
 *
 * This file contains the declaration of functions related to Query 4 operations.
 * Query 4 involves processing and analyzing hotel reservation data stored in a GHashTable,
 * with functions for creating and manipulating a binary search tree (TreeR).
 *
 * @author [Seu Nome]
 */

#ifndef _QUERY4_
#define _QUERY4_

#include <glib.h>
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_reservations.h"

/**
 * @brief Executes Query 4 operation on hotel reservation data.
 *
 * This function performs the Query 4 operation on hotel reservation data stored in a GHashTable.
 * It takes input parameters such as strings and integers to filter and process
 * hotel reservation information based on specific criteria.
 *
 * @param reservations A GHashTable containing hotel reservation information.
 * @param input The input string for the operation.
 * @param i An integer parameter for the operation.
 * @param j An integer parameter for the operation.
 * @param l An integer parameter for the operation.
 */
void query4(GHashTable* reservations, char* input, int i, int j, int l);

/**
 * @brief Creates a node for the binary search tree (TreeR).
 *
 * This function creates a node for the binary search tree (TreeR) used in Query 4.
 * The node contains an ID and a pointer to a hotel reservation (Reserva).
 *
 * @param id_r The ID associated with the node.
 * @param reservation A pointer to the hotel reservation (Reserva) associated with the node.
 * @return A pointer to the created node.
 */
TreeR* criarNoH(char* id_r, Reserva* reservation);

/**
 * @brief Inserts a node into the binary search tree (TreeR).
 *
 * This function inserts a node into the binary search tree (TreeR) based on the reservation ID
 * and associated hotel reservation.
 *
 * @param raiz The root of the binary search tree.
 * @param id_r The reservation ID for insertion.
 * @param r A pointer to the hotel reservation (Reserva) for insertion.
 * @return The root of the modified binary search tree.
 */
TreeR* inserirH(TreeR* raiz, char* id_r, Reserva* r);

/**
 * @brief Traverses the binary search tree (TreeR) in-order.
 *
 * This function traverses the binary search tree (TreeR) in-order, performing a specific
 * operation on each node based on parameters i, j, and k.
 *
 * @param raiz The root of the binary search tree.
 * @param i An integer parameter for the traversal operation.
 * @param j An integer parameter for the traversal operation.
 * @param k An integer parameter for the traversal operation.
 * @param l An integer parameter for the traversal operation.
 */
void percorrerEmOrdemH(TreeR* raiz, int i, int j, int k, int l);

/**
 * @brief Frees memory allocated for the binary search tree (TreeR).
 *
 * This function recursively frees the memory allocated for the binary search tree (TreeR).
 *
 * @param raiz The root of the binary search tree.
 */
void libertarArvoreH(TreeR* raiz);

/**
 * @brief Retrieves hotel reservations associated with a specific hotel.
 *
 * This function retrieves hotel reservations associated with a specific hotel.
 *
 * @param reservations A GHashTable containing hotel reservation information.
 * @param input The hotel for filtering reservations.
 * @return The root of the binary search tree (TreeR) containing filtered hotel reservation data.
 */
TreeR* hotelReservations(GHashTable* reservations, char* input);

/**
 * @brief Counts the number of nodes in the binary search tree (TreeR).
 *
 * This function counts the number of nodes in the binary search tree (TreeR).
 *
 * @param raiz The root of the binary search tree.
 * @return The number of nodes in the binary search tree.
 */
int contaNosR(TreeR* raiz);


/**
 * @brief Prints information of a single node in the binary search tree (TreeR).
 *
 * This function prints information of a single node in the binary search tree (TreeR).
 *
 * @param node A pointer to the node in the binary search tree.
 */
void printNode(TreeR* node);

/**
 * @brief Prints a page of nodes from the binary search tree (TreeR).
 *
 * This function prints a page of nodes from the binary search tree (TreeR).
 *
 * @param raiz The root of the binary search tree.
 * @param i An integer parameter for printing.
 * @param j An integer parameter for printing.
 * @param k An integer parameter for printing.
 * @param l An integer parameter for printing.
 * @param pageNumber The page number to be printed.
 */
void printPage(struct TreeR* raiz, int i, int j, int k, int l, int pageNumber);

/**
 * @brief Stores nodes of the binary search tree (TreeR) in an array.
 *
 * This function stores nodes of the binary search tree (TreeR) in an array.
 *
 * @param raiz The root of the binary search tree.
 * @param nodesArray An array to store nodes.
 * @param currentIndex A pointer to the current index in the array.
 */
void storeNodesInArray(TreeR* raiz, TreeR* nodesArray[], int* currentIndex);
#endif /* _QUERY4_ */
