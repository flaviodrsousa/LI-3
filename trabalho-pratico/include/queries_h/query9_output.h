#ifndef _QUERY9_OUTPUT_
#define _QUERY9_OUTPUT_

/**
 * @file query9_output.h
 * @brief Documentação relacionado ao output da Query 9.
 */

/**
 * @brief Converte e guarda os resultados da Query 9 num ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da execução padrão da Query 9
 * em um documento de texto, conforme especificado pelos parâmetros.
 *
 * @param[in] i O índice associado ao número do comando da Query 9.
 * @param[in] sizeArray O tamanho do array de resultados.
 * @param[in] arrayPares O array contendo os resultados da Query 9.
 */
void to_txt_9(int i, int sizeArray, KeyNomeId *arrayPares, int l);

/**
 * @brief Converte e guarda os resultados da Query 9 (execução alternativa, ou seja, else) em um ficheiro de texto.
 *
 * Esta função converte e guarda os resultados da execução alternativa da Query 9
 * em um ficheiro de texto, conforme especificado pelos parâmetros.
 *
 * @param[in] i O índice associado ao número do comando alternativa da Query 9.
 * @param[in] sizeArray O tamanho do array de resultados.
 * @param[in] arrayPares O array contendo os resultados da Query 9 (execução alternativa).
 */
void to_txt_9_1(int i, int sizeArray, KeyNomeId *arrayPares);

#endif /* _QUERY9_OUTPUT_ */
