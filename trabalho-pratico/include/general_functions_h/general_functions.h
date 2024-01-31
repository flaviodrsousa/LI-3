/**
 * @file general_functions.h
 * @brief Header file for general utility functions.
 *
 * This file contains the declaration of general utility functions that are used across the application.
 * The functions include date and time checking, date comparison, age calculation, and other general-purpose operations.
 *
 * @author [Grupo35]
 */

#ifndef _GENERAL_FUNCTIONS_H_
#define _GENERAL_FUNCTIONS_H_

#include <glib.h>

/**
 * @brief Verifica se uma string fornecida representa uma data válida.
 *
 * @param date A string que representa uma data.
 * @return 1 se a data for válida, 0 caso contrário.
 */
int check_date(char* date);

/**
 * @brief Verifica se uma string fornecida representa uma data e hora válidas.
 *
 * @param date A string que representa uma data e hora.
 * @return 1 se a data e hora forem válidas, 0 caso contrário.
 */
int check_date_time(char* date);

/**
 * @brief Compara duas datas.
 *
 * @param date1 A primeira data a ser comparada.
 * @param date2 A segunda data a ser comparada.
 * @return 1 se date1 for posterior a date2, -1 se date1 for anterior a date2, 0 se forem iguais.
 */
int compare_date(char* date1, char* date2);

/**
 * @brief Compara duas datas e horas.
 *
 * @param date1 A primeira data e hora a ser comparada.
 * @param date2 A segunda data e hora a ser comparada.
 * @return 1 se date1 for posterior a date2, -1 se date1 for anterior a date2, 0 se forem iguais.
 */
int compare_date_time(char* date1, char* date2);

/**
 * @brief Remove um caractere especificado de uma string.
 *
 * @param input A string de entrada.
 * @param remover O caractere a ser removido.
 * @return A string modificada.
 */
char* removeChar(char *input, char remover);

/**
 * @brief Libera a memória alocada para um par chave-valor em uma GHashTable.
 *
 * Esta função é adequada para uso com g_hash_table_foreach().
 *
 * @param data O valor associado à chave.
 */
void free_key_value(gpointer data);

/**
 * Libera a memória alocada para os tokens e a matriz que os contém.
 * 
 * @param tokens A matriz de ponteiros de caracteres que contém os tokens.
 * @param max O número máximo de tokens na matriz.
 */
void freeTokens(char** tokens, int max);

#endif /* _GENERAL_FUNCTIONS_H_ */

/**
 * Calcula a diferença em minutos entre duas datas e horas.
 *
 * @param date1 A primeira data e hora.
 * @param date2 A segunda data e hora.
 * @return A diferença em minutos entre as duas datas e horas.
 */
int timeDifference(char* date1, char* date2);

/**
 * Calcula o atraso em minutos entre duas datas e horas.
 *
 * @param date1 A primeira data e hora.
 * @param date2 A segunda data e hora.
 * @return O atraso em minutos entre as duas datas e horas.
 */
int atraso(char* date1, char* date2);

/**
 * Compara os anos de duas datas.
 *
 * @param date1 A primeira data.
 * @param date2 A segunda data.
 * @return 1 se o ano de date1 for maior que o ano de date2, -1 se for menor, 0 se forem iguais.
 */
int compare_year(char* date1, char* date2);