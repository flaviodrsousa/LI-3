/**
 * @file query5.h
 * @brief Header file for Query 5 functionality.
 *
 * This file contains the declaration of functions related to Query 5 operations.
 * Query 5 involves processing and analyzing flight data stored in a GHashTable,
 * with functions for creating and manipulating a binary search tree (TreeV).
 *
 * @author [Grupo35]
 */

#ifndef _QUERY5_
#define _QUERY5_

#include <glib.h>

/**
 * @brief Executes Query 5 operation on flight data.
 *
 * This function performs the Query 5 operation on flight data stored in a GHashTable.
 * It takes input parameters such as strings, integers, and dates to filter and process
 * flight information based on specific criteria.
 *
 * @param flights A GHashTable containing flight information.
 * @param input The input string for the operation.
 * @param data1 The first date parameter for the operation.
 * @param data2 The second date parameter for the operation.
 * @param i An integer parameter for the operation.
 * @param j An integer parameter for the operation.
 */
void query5(GHashTable* flights, char* input, char* data1, char* data2, int i, int j, int l);

/**
 * @brief Creates a node for the binary search tree (TreeV).
 *
 * This function creates a node for the binary search tree (TreeV) used in Query 5.
 * The node contains an ID and a pointer to a flight reservation (Voo).
 *
 * @param id_r The ID associated with the node.
 * @param reservation A pointer to the flight reservation (Voo) associated with the node.
 * @return A pointer to the created node.
 */
TreeV* criarNoB(char* id_r, Voo* reservation);

/**
 * @brief Inserts a node into the binary search tree (TreeV).
 *
 * This function inserts a node into the binary search tree (TreeV) based on the flight ID
 * and associated flight reservation.
 *
 * @param raiz The root of the binary search tree.
 * @param id_f The flight ID for insertion.
 * @param f A pointer to the flight reservation (Voo) for insertion.
 * @return The root of the modified binary search tree.
 */
TreeV* inserirB(TreeV* raiz, char* id_f, Voo* f);

/**
 * @brief Traverses the binary search tree (TreeV) in-order.
 *
 * This function traverses the binary search tree (TreeV) in-order, performing a specific
 * operation on each node based on parameters i, j, and k.
 *
 * @param raiz The root of the binary search tree.
 * @param i An integer parameter for the traversal operation.
 * @param j An integer parameter for the traversal operation.
 * @param k An integer parameter for the traversal operation.
 */
void percorrerEmOrdemB(TreeV* raiz, int i, int j, int k, int l);

/**
 * @brief Frees memory allocated for the binary search tree (TreeV).
 *
 * This function recursively frees the memory allocated for the binary search tree (TreeV).
 *
 * @param raiz The root of the binary search tree.
 */
void libertarArvoreB(TreeV* raiz);

/**
 * @brief Retrieves flights originating from a specific location within a date range.
 *
 * This function retrieves flights originating from a specific location within a given date range.
 *
 * @param flights A GHashTable containing flight information.
 * @param input The origin location for filtering flights.
 * @param date1 The start date for filtering flights.
 * @param date2 The end date for filtering flights.
 * @return The root of the binary search tree (TreeV) containing filtered flight data.
 */
TreeV* voosOrigem(GHashTable* flights, char* input, char* date1, char* date2);

/**
 * @brief Counts the number of nodes in the binary search tree (TreeV).
 *
 * This function counts the number of nodes in the binary search tree (TreeV).
 *
 * @param raiz The root of the binary search tree.
 * @return The number of nodes in the binary search tree.
 */
int contaNos(TreeV* raiz);

void printNodeV(TreeV* node);

void printPageV(struct TreeV* raiz, int i, int j, int k, int l, int pageNumber);

void storeNodesInArrayV(TreeV* raiz, TreeV* nodesArray[], int* currentIndex);

#endif /* _QUERY5_ */
