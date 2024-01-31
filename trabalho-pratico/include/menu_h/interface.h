#ifndef _INTERFACE_H_
#define _INTERFACE_H_

/**
 * @file interface.h
 * @brief Documentação relacionada à interface.
 */

/**
 * @brief Realiza a análise e processamento de dados a partir de um ficheiro.
 *
 * Esta função realiza a análise e processamento de dados a partir de um ficheiro,
 * chamando a função fornecida para cada linha do ficheiro.
 *
 * @param[in] nome O nome do ficheiro a ser processado.
 * @param[in] tamanho O número de componentes de cada ficheiro.
 * @param[in] function Pointer para a função de processamento de linha.
 * @param[in] hash_recebe Hash table de destino para armazenar dados processados.
 * @param[in] hash1 Hash table auxiliar 1 para processamento de dados.
 * @param[in] hash2 Hash table auxiliar 2 para processamento de dados.
 * @return Pointer para a hash table contendo os dados processados.
 */
void interface ();

/**
 * @brief Função principal para realizar consultas.
 *
 * Esta função é responsável por chamar as funções específicas para realizar consultas e apresentar os resultados.
 */
void queries ();

/**
 * @brief Exibe a barra de navegação da página.
 */
void pageBar();

/**
 * @brief Exibe a página especificada.
 *
 * @param[in] i O número da página a ser exibida.
 */
void pageN(int i);

/**
 * @brief Exibe a sentença 1 da interface.
 */
void sentence1();

/**
 * @brief Exibe a sentença 2 da interface.
 */
void sentence2();

#endif /* _PARSER_USERS_H_ */
