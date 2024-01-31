/**
 * @file check_flights_errors.h
 * @brief Header file for flights data error-checking functions.
 *
 * This file contains the declaration of functions responsible for checking errors in flight data.
 * The functions include checking for null fields, validating airports, validating seat information,
 * and logging flight data errors.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_FLIGHTS_AUX_H_
#define _CATALOG_FLIGHTS_AUX_H_

/**
 * @brief Checks for null fields in an array of tokens.
 *
 * @param tokens An array of tokens to be checked for null fields.
 * @return 1 if there are null fields, 0 otherwise.
 */
int check_null_camp_fli(char* tokens[]);

/**
 * @brief Checks if a given string is a valid airport code.
 *
 * @param air The string to be checked.
 * @return 1 if the airport code is valid, 0 otherwise.
 */
int check_airport(char* air);

/**
 * @brief Checks if the seat information is valid for a flight.
 *
 * @param nome The name of the flight.
 * @param id The ID of the flight.
 * @param sit The seat information to be checked.
 * @return 1 if the seat information is valid, 0 otherwise.
 */
int check_sits(int n, char* n_sits);


/**
 * @brief Counts the number of flights.
 *
 * @param passengers A GHashTable containing flight data.
 * @param input The input parameter (may be used to filter data).
 * @return The number of flights.
 */
int calculate_numeroVoos(GHashTable* passengers, char *input);


/**
 * @brief Calculates the delay based on estimated and real departure times.
 *
 * @param data_estimada The estimated departure time.
 * @param data_real The real departure time.
 * @return The delay information.
 */
char* calculate_atraso(char* data_estimada, char* data_real);

/**
 * @brief Logs errors in flight data.
 *
 * This function logs errors in flight data to an appropriate location.
 *
 * @param linha The line of flight data with errors.
 */
void write_flights_error(char *linha);

#endif /* _CATALOG_FLIGHTS_AUX_H_ */
