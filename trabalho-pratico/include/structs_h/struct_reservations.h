/**
 * @file struct_reservations.h
 * @brief Header file for reservation data structures and functions.
 *
 * This file contains the declaration of structures and functions related to reservation information.
 * The main structure is `Reserva` representing reservation details, and various functions are provided
 * for setting, creating, freeing, and accessing information within the reservation structure.
 *
 * @author [Seu Nome]
 */

#ifndef _STRUCT_RESERVATIONS_
#define _STRUCT_RESERVATIONS_

#include <glib.h>

/**
 * @struct Reserva
 * @brief Structure to represent reservation information.
 */
typedef struct reserva Reserva;

GHashTable* get_reservations_hash(const struct catalog_reservations* reservation_catalog);

/**
 * @brief Sets reservation information in a Reserva structure.
 *
 * This function sets reservation information in a Reserva structure based on input parameters.
 *
 * @param reserva A pointer to the Reserva structure to be set.
 * @param id_user The user ID associated with the reservation.
 * @param id_hotel The hotel ID associated with the reservation.
 * @param nome_hotel The name of the hotel associated with the reservation.
 * @param estrelas_hotel The star rating of the hotel associated with the reservation.
 * @param data_inicial The start date of the reservation.
 * @param data_fim The end date of the reservation.
 * @param pequeno_almoco The indication of breakfast inclusion in the reservation.
 * @param preco_total The total price of the reservation.
 * @param classificacao The classification associated with the reservation.
 */
void set_reserva(Reserva* reserva, char* id_user, char* id_hotel,char* nome_hotel, char* estrelas_hotel, char* data_inicial, char* data_fim, char* pequeno_almoco, double preco_total, char* preco_noite, char* classificacao);

/**
 * @brief Creates a new Reserva structure.
 *
 * @return A pointer to the newly created Reserva structure.
 */
Reserva* create_res();

/**
 * @brief Frees memory allocated for a Reserva structure.
 *
 * This function frees memory allocated for a Reserva structure.
 *
 * @param reserva A pointer to the Reserva structure to be freed.
 */
void free_reserva(Reserva* reserva);

/**
 * @brief Frees memory allocated for a GHashTable containing Reserva structures.
 *
 * This function frees memory allocated for a GHashTable containing Reserva structures.
 *
 * @param key The key associated with a Reserva structure.
 * @param value A pointer to the Reserva structure.
 * @param user_data Additional user data (not used in this context).
 */
void free_hash_tableR(gpointer key, gpointer value, gpointer user_data);

/**
 * @brief Gets the user ID associated with the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The user ID associated with the reservation.
 */
char *getIdUser(const Reserva *reservation);

/**
 * @brief Gets the hotel ID associated with the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The hotel ID associated with the reservation.
 */
char *getIdHotel(const Reserva *reservation);

/**
 * @brief Gets the name of the hotel associated with the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The name of the hotel associated with the reservation.
 */
char *getNomeHotel(const Reserva *reservation);

/**
 * @brief Gets the star rating of the hotel associated with the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The star rating of the hotel associated with the reservation.
 */
char *getEstrelasHotel(const Reserva *reservation);

/**
 * @brief Gets the start date of the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The start date of the reservation.
 */
char *getDataInicial(const Reserva *reservation);

/**
 * @brief Gets the end date of the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The end date of the reservation.
 */
char *getDataFim(const Reserva *reservation);

/**
 * @brief Gets the indication of breakfast inclusion in the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The indication of breakfast inclusion in the reservation.
 */
char *getPequenoAlmoco(const Reserva *reservation);

/**
 * @brief Gets the total price of the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The total price of the reservation.
 */
double getPrecoTotal(const Reserva *reservation);

char *getPrecoNoite(const Reserva *reservation);

/**
 * @brief Gets the classification associated with the reservation from a Reserva structure.
 *
 * @param reservation A pointer to the Reserva structure.
 * @return The classification associated with the reservation.
 */
char *getClassificacao(const Reserva *reservation);

#endif /* _STRUCT_RESERVATIONS_ */
