/**
 * @file list.h
 * @brief Header file for a simple linked list implementation in C.
 */

#ifndef LIST_H
#define LIST_H

/**
 * @struct List
 * @brief Structure representing a node in the linked list.
 */
typedef struct list List;

/**
 * @brief Creates a new linked list node and initializes it with the given data.
 *
 * This function allocates memory for a new List node, sets its data, and
 * initializes the next pointer to NULL.
 *
 * @param data A pointer to the data to be stored in the new node.
 * @return A pointer to the newly created List node.
 */
List* set_list(const char* data);

/**
 * @brief Sets the next pointer of a given list node to point to another list node.
 *
 * @param pass A pointer to the list node whose next pointer will be set.
 * @param nex A pointer to the list node that will be the next node in the list.
 */
void setNextList(List* pass, List* nex);

/**
 * @brief Retrieves the data stored in a given list node.
 *
 * @param lista A pointer to the list node whose data will be retrieved.
 * @return A pointer to the data stored in the list node.
 */
char* getDataList(const struct list* lista);

/**
 * @brief Retrieves a pointer to the next list node in the sequence.
 *
 * @param lista A pointer to the list node whose next pointer will be retrieved.
 * @return A pointer to the next list node.
 */
List* getNextList(const struct list* lista);

/**
 * @brief Frees the memory allocated for a linked list and its nodes.
 *
 * This function recursively frees the memory for the given list node and all
 * its subsequent nodes in the linked list.
 *
 * @param lista A pointer to the head of the linked list to be freed.
 */
void freeList(List* lista);

#endif /* LIST_H */
