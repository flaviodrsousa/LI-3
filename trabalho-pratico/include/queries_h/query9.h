#ifndef _QUERY9_
#define _QUERY9_

/**
 * @file query9.h
 * @brief Documentação relacionado à Query 9.
 */

#include <glib.h>

/**
 * @struct KeyNomeId
 * @brief Estrutura para armazenar a key, o nome e o ID.
 */
typedef struct KeyNomeId KeyNomeId;

/**
 * @brief Executa a Query 9.
 *
 * Esta função realiza a Query 9 com base nos critérios fornecidos.
 *
 * @param[in] users A hash table que contem as informações dos utilizadores.
 * @param[in] input O input usado para a Query 9.
 * @param[in] j O valor j que entrega o numero a cada elemento do ficheiro da Query 9.
 * @param[in] type O tipo de execução da Query 9.
 *                 - 0: Execução padrão.
 *                 - else: Execução alternativa.
 */
void query9(GHashTable *users, char *input, int j, int type, int l);

#endif /* _QUERY9_ */
