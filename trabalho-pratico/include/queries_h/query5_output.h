/**
 * @file query5_output.h
 * @brief Header file for Query 5 output functionality.
 *
 * This file contains the declaration of the function responsible for generating output
 * for Query 5. The output function takes parameters such as strings and integers to produce
 * output in a specific format.
 *
 * @author [Grupo35]
 */

#ifndef _QUERY5_OUTPUT_
#define _QUERY5_OUTPUT_

/**
 * @brief Writes output to a text file based on specific flight information.
 *
 * This function writes output to a text file based on specific parameters such as flight ID,
 * departure and destination locations, airline, plane, and integers i and k. The output is
 * formatted accordingly.
 *
 * @param id The flight ID for the output.
 * @param departure The departure location for the output.
 * @param destination The destination location for the output.
 * @param airline The airline for the output.
 * @param plane The plane for the output.
 * @param i An integer parameter for the output.
 * @param k An integer parameter for the output.
 */
void to_txt_5(char* id, char* departure, char* destination, char* airline, char* plane, int i, int k);

#endif /* _QUERY5_OUTPUT_ */
