/**
 * @file check_passengers_errors.h
 * @brief Header file for passengers data error-checking functions.
 *
 * This file contains the declaration of a function responsible for logging errors in passenger data.
 * The function is used to log errors related to passengers' data.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_PASSENGERS_AUX_H_
#define _CATALOG_PASSENGERS_AUX_H_

/**
 * @brief Counts the number of passengers.
 *
 * @param passengers A GHashTable containing passenger data.
 * @param input The input parameter (may be used to filter data).
 * @return The number of passengers.
 */
int calculate_numeroPassageiros(GHashTable* passengers, char *input);

/**
 * @brief Logs errors in passenger data.
 *
 * This function logs errors in passenger data to an appropriate location.
 *
 * @param linha The line of passenger data with errors.
 */
void write_passenger_error(char* linha);

#endif /* _CATALOG_PASSENGERS_AUX_H_ */
