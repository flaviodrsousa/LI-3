#ifndef _PARSER_USERS_H_
#define _PARSER_USERS_H_

/**
 * @file parser_users.h
 * @brief Documentação para funções de análise de dados de utilizadores.
 */

#include <glib.h>

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
void parser(char *nome, int tamanho, void (*function)(char *nome1, char **tokens, char *linha, GHashTable *hash_recebe, GHashTable *hash1), GHashTable *hash, GHashTable *hash_01);

#endif /* _PARSER_USERS_H_ */
