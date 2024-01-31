#ifndef _QUERY1_
#define _QUERY1_

/**
 * @file query1.h
 * @brief Documentação relacionada à Query 1.
 */

#include <glib.h>

/**
 * @brief Executa a Query 1.
 *
 * Esta função realiza a Query 1 com base nos parâmetros fornecidos.
 *
 * @param[in] reservations A hash table que contem as informações das reservas.
 * @param[in] flights A hash table que contem as informações dos voos.
 * @param[in] users A hash table que contem as informações dos usuários.
 * @param[in] passengers A hash table que contem as informações dos passageiros.
 * @param[in] input O input para a Query 1.
 * @param[in] i Identifica o número do ficheiro.
 * @param[in] type O tipo de execução da Query 1.
 */
void query1(GHashTable *reservations, GHashTable *flights, GHashTable *users, char *input, int i, int type, int l);

#endif /* _QUERY1_ */
