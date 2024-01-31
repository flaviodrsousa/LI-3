/**
 * @file query4_output.h
 * @brief Header file for Query 4 output functionality.
 *
 * This file contains the declaration of the function responsible for generating output
 * for Query 4. The output function takes parameters such as strings, integers, and a double
 * to produce output in a specific format.
 *
 * @author [Seu Nome]
 */

#ifndef _QUERY4_OUTPUT_
#define _QUERY4_OUTPUT_

/**
 * @brief Writes output to a text file based on specific hotel reservation information.
 *
 * This function writes output to a text file based on specific parameters such as reservation ID,
 * begin and end dates, user information, rating, price, and integers i and k. The output is
 * formatted accordingly.
 *
 * @param id The reservation ID for the output.
 * @param begin The begin date for the output.
 * @param end The end date for the output.
 * @param user The user information for the output.
 * @param rating The rating for the output.
 * @param price The price for the output.
 * @param i An integer parameter for the output.
 * @param k An integer parameter for the output.
 */
void to_txt_4(char* id, char* begin, char* end, char* user, char* rating, double price, int i, int k);

#endif /* _QUERY4_OUTPUT_ */
