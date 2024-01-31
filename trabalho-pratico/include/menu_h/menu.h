#ifndef _MENU_H_
#define _MENU_H_

/**
 * @file menu.h
 * @brief Documentação relacionada ao menu.
 */

#include "../include/catalogs_h/catalogs.h"

/**
 * @brief Realiza a análise e processamento de dados a partir de um ficheiro.
 *
 * Esta função realiza a análise e processamento de dados a partir de um ficheiro,
 * chamando a função fornecida para cada linha do ficheiro.
 *
 * @param[in] nome O nome do ficheiro a ser processado.
 * @param[in] tamanho O número de componentes de cada ficheiro.
 * @param[in] function Ponteiro para a função de processamento de linha.
 * @param[in] hash_recebe Hash table de destino para armazenar dados processados.
 * @param[in] hash1 Hash table auxiliar 1 para processamento de dados.
 * @param[in] hash2 Hash table auxiliar 2 para processamento de dados.
 * @return Ponteiro para a hash table contendo os dados processados.
 */
void menu ();

/**
 * @brief Cria e retorna um conjunto de catálogos a partir da análise de dados.
 *
 * @return Ponteiro para o conjunto de catálogos criado.
 */
Catalogs* dataset ();

/**
 * @brief Exibe uma mensagem de chave inválida no menu.
 */
void invalidKey ();

/**
 * @brief Lê uma string da entrada padrão.
 *
 * @return A string lida da entrada padrão.
 */
char* scan();

#endif /* _PARSER_USERS_H_ */