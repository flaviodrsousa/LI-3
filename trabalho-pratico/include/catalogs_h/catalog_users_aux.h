/**
 * @file check_user_errors.h
 * @brief Header file for user data error-checking functions.
 *
 * This file contains the declaration of functions responsible for checking errors in user data.
 * The functions include email validation, status checking, country code validation, handling null fields,
 * and logging user data errors.
 *
 * @author [Seu Nome]
 */

#ifndef _CATALOG_USERS_AUX_H_
#define _CATALOG_USERS_AUX_H_

/**
 * @brief Checks if a given string is a valid email address.
 *
 * @param email The string to be checked.
 * @return 1 if the email is valid, 0 otherwise.
 */
int check_email(char* email);

/**
 * @brief Checks if a given string represents an active status.
 *
 * @param active The string to be checked.
 * @return 1 if the status is valid, 0 otherwise.
 */
int check_status(char* active);

/**
 * @brief Checks if a given status string represents an active status.
 *
 * @param active The status string to be checked.
 * @return 1 if the status is active, 0 otherwise.
 */
int check_is_active(char* active);

/**
 * @brief Checks if a given string is a valid country code.
 *
 * @param cc The string to be checked.
 * @return 1 if the country code is valid, 0 otherwise.
 */
int check_country_code(char *cc);

/**
 * @brief Checks for null fields in an array of tokens.
 *
 * @param tokens An array of tokens to be checked for null fields.
 * @return 1 if there are null fields, 0 otherwise.
 */
int check_null_camp_urs(char* tokens[]);


/**
 * @brief Calculates the age based on a given date of birth.
 *
 * @param date The date of birth.
 * @return The calculated age.
 */
int calculate_age(char* date);


/**
 * @brief Logs errors in user data.
 *
 * This function logs errors in user data to an appropriate location.
 *
 * @param linha The line of user data with errors.
 */
void write_user_error(char *linha);

#endif /* _CATALOG_USERS_AUX_H_ */
