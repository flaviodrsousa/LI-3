/**
 * @file check_reservation_errors.h
 * @brief Header file for reservation data error-checking functions.
 *
 * This file contains the declaration of functions responsible for checking errors in reservation data.
 * The functions include checking for null fields, validating hotel stars, city tax, price per night,
 * breakfast inclusion, classification, and logging reservation data errors.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_RESERVATIONS_AUX_H_
#define _CATALOG_RESERVATIONS_AUX_H_

/**
 * @brief Checks for null fields in an array of tokens.
 *
 * This function checks for null fields in an array of tokens.
 *
 * @param tokens An array of tokens to be checked for null fields.
 * @return 1 if there are null fields, 0 otherwise.
 */
int check_null_camp_res(char* tokens[]);

/**
 * @brief Checks if a given string is a valid hotel star rating.
 *
 * This function checks if a given string is a valid hotel star rating.
 *
 * @param star The string to be checked.
 * @return 1 if the star rating is valid, 0 otherwise.
 */
int check_hotel_stars(char* star);

/**
 * @brief Checks if a given string is a valid city tax value.
 *
 * This function checks if a given string is a valid city tax value.
 *
 * @param city The string to be checked.
 * @return 1 if the city tax is valid, 0 otherwise.
 */
int check_city_tax(char* city);

/**
 * @brief Checks if a given string is a valid price per night value.
 *
 * This function checks if a given string is a valid price per night value.
 *
 * @param night The string to be checked.
 * @return 1 if the price per night is valid, 0 otherwise.
 */
int check_price_per_night(char* night);

/**
 * @brief Checks if a given string is a valid indication of breakfast inclusion.
 *
 * This function checks if a given string is a valid indication of breakfast inclusion.
 *
 * @param breakfast The string to be checked.
 * @return 1 if the indication of breakfast inclusion is valid, 0 otherwise.
 */
int check_includes_breakfast(char* breakfast);

/**
 * @brief Checks if a given string is a valid classification value.
 *
 * This function checks if a given string is a valid classification value.
 *
 * @param classification The string to be checked.
 * @return 1 if the classification is valid, 0 otherwise.
 */
int check_classification(char *classification);

/**
 * @brief Counts the number of reservations.
 *
 * This function counts the number of reservations based on the input parameters.
 *
 * @param reservation A GHashTable containing reservation data.
 * @param input The input parameter (may be used to filter data).
 * @return The number of reservations.
 */
int calculate_numeroReservas(GHashTable* reservation, char *input);

/**
 * @brief Calculates the number of nights between two dates.
 *
 * This function calculates the number of nights between two dates.
 *
 * @param data1 The start date.
 * @param data2 The end date.
 * @return The number of nights.
 */
int calculate_n_noites(char* data1, char* data2);

/**
 * @brief Calculates the indication of breakfast inclusion.
 *
 * This function calculates the indication of breakfast inclusion based on the input parameter.
 *
 * @param pa The input parameter.
 * @return The indication of breakfast inclusion.
 */
char* calculate_pequeno_almoco(char* pa);

/**
 * @brief Calculates the total price including city tax for a reservation.
 *
 * This function calculates the total price including city tax for a reservation.
 *
 * @param n_noites The number of nights.
 * @param preco_noite The price per night.
 * @param imposto_da_cidade The city tax.
 * @return The total price.
 */
double calculate_preco_total(int n_noites, char* preco_noite, char* imposto_da_cidade);

/**
 * @brief Calculates the total amount spent on reservations.
 *
 * This function calculates the total amount spent on reservations based on the input parameters.
 *
 * @param reservation A GHashTable containing reservation data.
 * @param input The input parameter (may be used to filter data).
 * @return The total amount spent on reservations.
 */
double calculate_totalGasto(GHashTable* reservation, char *input);

/**
 * @brief Logs errors in reservation data.
 *
 * This function logs errors in reservation data to an appropriate location.
 *
 * @param linha The line of reservation data with errors.
 */
void write_reservation_error(char *linha);

#endif /* _CATALOG_RESERVATIONS_AUX_H_ */
