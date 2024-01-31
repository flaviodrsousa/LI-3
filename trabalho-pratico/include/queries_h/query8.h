#ifndef _QUERY8_
#define _QUERY8_

/**
 * @file query8.h
 * @brief Documentação relacionada à Query 8.
 */

#include <glib.h>

/**
 * @brief Executa a Query 8.
 *
 * Esta função realiza a Query 8 com base nos parâmetros fornecidos.
 *
 * @param[in] reservation A hash table que contem as informações das reservas.
 * @param[in] id A entrada para a Query 8.
 * @param[in] begin A entrada para a Query 8.
 * @param[in] end A entrada para a Query 8.
 */
void query8 (GHashTable* reservation, char *id, char *begin, char *end, int numbe,int type, int l);

/**
 * @brief Converte e guarda a revenue da Query 8 em um ficheiro de texto.
 *
 * Esta função converte e guarda a revenue da Query 8 em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] revenueTotal A revenue total no espaço de tempo definido.
 * @param[in] i O valor i é utilizado para definir o número do comando executado.
 */
void to_txt_8(int revenueTotal, int i);

#endif /* _QUERY8_ */