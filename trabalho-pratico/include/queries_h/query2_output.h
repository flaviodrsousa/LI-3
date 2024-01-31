/**
 * @file query2_output.h
 * @brief Header file for Query 2 output functionality.
 *
 * This file contains the declaration of functions responsible for generating output
 * for Query 2. The output functions handle converting binary search trees to linked lists,
 * printing lists, and freeing memory associated with these structures.
 *
 * @author [Seu Nome]
 */

#ifndef _QUERY2_OUTPUT_
#define _QUERY2_OUTPUT_

/**
 * @brief Creates a node for the linked list (ListX).
 *
 * This function creates a node for the linked list (ListX) used in Query 2.
 *
 * @param id_flight The ID associated with the flight.
 * @param flight A pointer to the flight information.
 * @param id_reservation The ID associated with the reservation.
 * @param reservation A pointer to the reservation information.
 * @return A pointer to the created node.
 */
ListNode* createNode(char* id_flight, Voo* flight, char* id_reservation, Reserva* reservation);

/**
 * @brief Converts a binary search tree for flights to a linked list.
 *
 * This function converts a binary search tree for flights (TreeV) to a linked list (ListX).
 *
 * @param v The root of the binary search tree for flights.
 * @param x A pointer to the linked list for flights (ListX).
 */
void TreeToListV(TreeV* v, ListX* x);

/**
 * @brief Converts a binary search tree for reservations to a linked list.
 *
 * This function converts a binary search tree for reservations (TreeR) to a linked list (ListX).
 *
 * @param r The root of the binary search tree for reservations.
 * @param x A pointer to the linked list for reservations (ListX).
 */
void TreeToListR(TreeR* r, ListX* x);

/**
 * @brief Prints the linked list for flights.
 *
 * This function prints the linked list for flights (ListX).
 *
 * @param x A pointer to the linked list for flights (ListX).
 * @param type An integer representing the type of print operation.
 * @param j An integer parameter for the print operation.
 * @param l An integer parameter for the print operation.
 */
void ImprimirListaV(ListX* x, int type, int j, int l);

/**
 * @brief Prints the linked list for reservations.
 *
 * This function prints the linked list for reservations (ListX).
 *
 * @param x A pointer to the linked list for reservations (ListX).
 * @param type An integer representing the type of print operation.
 * @param j An integer parameter for the print operation.
 * @param l An integer parameter for the print operation.
 */
void ImprimirListaR(ListX* x, int type, int j, int l);

/**
 * @brief Prints the linked lists for flights and reservations together.
 *
 * This function prints the linked lists for flights and reservations together (ListX).
 *
 * @param v A pointer to the linked list for flights (ListX).
 * @param r A pointer to the linked list for reservations (ListX).
 * @param type An integer representing the type of print operation.
 * @param j An integer parameter for the print operation.
 * @param l An integer parameter for the print operation.
 */
void ImprimirListaVeR(ListX* v, ListX* r, int type, int j, int l);

/**
 * @brief Frees memory allocated for a binary search tree for flights (TreeV).
 *
 * This function recursively frees the memory allocated for a binary search tree for flights (TreeV).
 *
 * @param raiz The root of the binary search tree for flights.
 */
void freeTreeV(TreeV* raiz);

/**
 * @brief Frees memory allocated for a binary search tree for reservations (TreeR).
 *
 * This function recursively frees the memory allocated for a binary search tree for reservations (TreeR).
 *
 * @param root The root of the binary search tree for reservations.
 */
void freeTreeR(TreeR* root);

/**
 * @brief Frees memory allocated for a linked list node (ListNode).
 *
 * This function frees the memory allocated for a linked list node (ListNode).
 *
 * @param node A pointer to the linked list node.
 */
void freeListNode(ListNode* node);

/**
 * @brief Frees memory allocated for a linked list (ListX).
 *
 * This function frees the memory allocated for a linked list (ListX).
 *
 * @param list A pointer to the linked list (ListX).
 */
void freeListX(ListX* list);

#endif /* _QUERY2_OUTPUT_ */
