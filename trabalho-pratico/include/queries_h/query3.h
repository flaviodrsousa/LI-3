#ifndef _QUERY3_
#define _QUERY3_

/**
 * @file query3.h
 * @brief Documentação relacionada à Query 3.
 */

#include <glib.h>

/**
 * @brief Executa a Query 3.
 *
 * Esta função realiza a Query 3 com base nos parâmetros fornecidos.
 *
 * @param[in] reservation A hash table que contem as informações das reservas.
 * @param[in] input A entrada para a Query 3.
 * @param[in] i O valor i é utilizado para definir o número do comando executado.
 * @param[in] type O tipo de execução da Query 3.
 *                 - 0: Execução padrão.
 *                 - else: Execução alternativa.
 */
void query3(GHashTable *reservation, char *input, int i, int type, int l);

/**
 * @brief Converte e guarda a média de classificações da Query 3 em um ficheiro de texto.
 *
 * Esta função converte e guarda a média de classificações da Query 3 em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] mediaRating A média de classificações calculada.
 * @param[in] i O valor i é utilizado para definir o número do comando executado.
 */
void to_txt_3(double mediaRating, int i);

#endif /* _QUERY3_ */
