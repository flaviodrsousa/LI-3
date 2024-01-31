/**
 * @file struct_users.h
 * @brief Header file for user data structures and functions.
 *
 * This file contains the declaration of structures and functions related to user information.
 * The main structure is `Utilizador` representing user details, and various functions are provided
 * for setting, creating, freeing, and accessing information within the user structure.
 *
 * @author [Seu Nome]
 */

#ifndef _STRUCT_USERS_
#define _STRUCT_USERS_

#include <glib.h>
#include "../include/structs_h/struct_list.h"

/**
 * @struct Utilizador
 * @brief Structure to represent a user.
 */
typedef struct utilizador Utilizador;

/**
 * @brief Initializes a Utilizador structure with the provided values.
 *
 * This function initializes a Utilizador structure with the provided values.
 *
 * @param[out] usr Pointer to the Utilizador structure to be initialized.
 * @param[in] nome The user's name.
 * @param[in] sexo The user's gender.
 * @param[in] idade The user's age.
 * @param[in] codigo_pais The user's country code.
 * @param[in] passport The user's passport number.
 * @param[in] status The user's status.
 */
void set_utilizador(Utilizador *usr, char *nome, char *sexo, int idade, char *codigo_pais, char *passport, int status);

/**
 * @brief Creates a new Utilizador structure.
 *
 * @return A pointer to the newly created Utilizador structure.
 */
Utilizador* create_usr();

/**
 * @brief Frees memory associated with a Utilizador structure.
 *
 * This function frees memory associated with a Utilizador structure.
 *
 * @param[in] usr Pointer to the Utilizador structure to be freed.
 */
void free_user(Utilizador *usr);

/**
 * @brief Frees memory associated with a hash table of Utilizadores.
 *
 * This function frees memory associated with a GHashTable containing Utilizador structures.
 *
 * @param[in] key The key of the hash table.
 * @param[in] value The value associated with the key.
 * @param[in] user_data User data (not used in this context).
 */
void free_hash_tableU(gpointer key, gpointer value, gpointer user_data);

/**
 * @brief Gets the user's name from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's name.
 */
char *getNome(const Utilizador *user);

/**
 * @brief Gets the user's gender from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's gender.
 */
char *getSexo(const Utilizador *user);

/**
 * @brief Gets the user's age from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's age.
 */
int getIdade(const Utilizador *user);

/**
 * @brief Gets the user's country code from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's country code.
 */
char *getCodigoPais(const Utilizador *user);

/**
 * @brief Gets the user's passport number from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's passport number.
 */
char *getPassport(const Utilizador *user);

/**
 * @brief Gets the user's status from a Utilizador structure.
 *
 * @param[in] user Pointer to the Utilizador structure.
 * @return The user's status.
 */
int getStatus(const Utilizador *user);

List* getListUser(const Utilizador *user);

void setListUser(Utilizador* user, List* lista);

#endif /* _STRUCT_USERS_ */
