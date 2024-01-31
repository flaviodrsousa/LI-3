#ifndef _QUERY6_
#define _QUERY6_

/**
 * @file query6.h
 * @brief Documentação relacionada à Query 6.
 */

#include <glib.h>

/**
 * @brief Estrutura que representa um Aeroporto.
 */
typedef struct Airport Airport;

/**
 * @brief Executa a Query 6.
 *
 * Esta função realiza a Query 6 com base nos parâmetros fornecidos.
 *
 * @param[in] flights A tabela hash que contém as informações dos voos.
 * @param[in] y O ano para a execução da Query 6.
 * @param[in] n Um inteiro para a execução da Query 6.
 * @param[in] j Um inteiro para a execução da Query 6.
 * @param[in] i Um inteiro para a execução da Query 6.
 * @param[in] l Um inteiro para a execução da Query 6.
 */
void query6(GHashTable *flights,char* y, int n, int j, int i, int l);

/**
 * @brief Armazena informações sobre aeroportos com base nos parâmetros fornecidos.
 *
 * Esta função armazena informações sobre aeroportos com base nos parâmetros fornecidos.
 *
 * @param[in] flights A tabela hash que contém as informações dos voos.
 * @param[in] year O ano para o qual armazenar as informações.
 * @param[in] n Um inteiro para a execução da Query 6.
 * @param[in] j Um inteiro para a execução da Query 6.
 * @param[in] i Um inteiro para a execução da Query 6.
 * @param[in] l Um inteiro para a execução da Query 6.
 */
void airportStore(GHashTable *flights, char* year, int n, int j, int i, int l);

/**
 * @brief Função de comparação para ordenar aeroportos.
 *
 * Esta função de comparação é utilizada para ordenar aeroportos com base na sua receita.
 *
 * @param[in] a Um ponteiro para o primeiro aeroporto.
 * @param[in] b Um ponteiro para o segundo aeroporto.
 * @return Um inteiro negativo se a < b, 0 se a == b, e um inteiro positivo se a > b.
 */
int compareAirports(const void *a, const void *b);

/**
 * @brief Converte e guarda a receita da Query 6 em um ficheiro de texto.
 *
 * Esta função converte e guarda a receita da Query 6 em um ficheiro de texto,
 * conforme especificado pelos parâmetros.
 *
 * @param[in] revenueTotal A receita total no intervalo de tempo definido.
 * @param[in] i O valor i é utilizado para definir o número do comando executado.
 */
#endif /* _QUERY6_ */