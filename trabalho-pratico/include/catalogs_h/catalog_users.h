#ifndef _CATALOG_USERS_H_
#define _CATALOG_USERS_H_

/**
 * @file parser_users_functions.h
 * @brief Documentação relacionada às funções do parser de utilizadores.
 */

#include <glib.h>

/**
 * @struct catalog_users
 * @brief Estrutura que representa um catálogo de utilizadores.
 */
typedef struct catalog_users Catalog_users;

/**
 * @brief Obtém a tabela hash de utilizadores do catálogo de utilizadores.
 *
 * @param[in] user_catalog O catálogo de utilizadores do qual se deseja obter a tabela hash.
 * @return A tabela hash contendo os dados dos utilizadores.
 */
GHashTable* get_users_hash(const struct catalog_users* user_catalog);

/**
 * @brief Liberta a memória alocada para o catálogo de utilizadores.
 *
 * @param[in] u O catálogo de utilizadores a ser libertado.
 */
void free_catalog_users(Catalog_users* u);


/**
 * @brief Função de processamento de linha para o parser de utilizadores.
 *
 * @param[in] nome O nome do arquivo a ser processado.
 * @param[in] tokens Os tokens extraídos da linha.
 * @param[in] linha A linha a ser processada.
 * @param[in] hash_recebe Hash table de destino para armazenar dados processados.
 * @param[in] hash1 Hash table auxiliar 1 para processamento de dados.
 * @param[in] hash2 Hash table auxiliar 2 para processamento de dados.
 */
void user_hash(char *nome, char **tokens, char *linha, GHashTable *hash_recebe, GHashTable *hash1);

/**
 * @brief Cria um catálogo de utilizadores a partir do caminho especificado.
 *
 * @param[in] path O caminho para o ficheiro de catálogo de utilizadores.
 * @return Um ponteiro para o catálogo de utilizadores criado.
 */
Catalog_users* create_users_catalog(char* path);

#endif /* _CATALOG_USERS_H_ */
