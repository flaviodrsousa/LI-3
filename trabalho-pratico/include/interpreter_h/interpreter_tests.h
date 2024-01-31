/**
 * @file batsh.h
 * @brief Arquivo de cabeçalho para funções de processamento em lote.
 *
 * Este arquivo contém a declaração de funções responsáveis pelo processamento em lote de dados.
 * As funções incluem a escrita de dados em um arquivo de texto com formatos específicos para usuários, voos e reservas,
 * além de uma função de processamento em lote que recebe arquivos de dados de entrada e os processa em GHashTables.
 *
 * @author [Grupo35]
 */

#ifndef _BATSH_H_
#define _BATSH_H_

#include <glib.h>
#include "../include/catalogs_h/catalogs.h"

/**
 * @brief Escreve uma linha em um arquivo de texto com um formato específico (Formato 0).
 *
 * @param i O número da linha.
 * @param linha A linha de dados.
 */
void to_txt_0(int i, const char *linha);

/**
 * @brief Escreve dados de usuário em um arquivo de texto com um formato específico (Formato 1 para usuários).
 *
 * @param i O número da linha.
 * @param name O nome do usuário.
 * @param sex O gênero do usuário.
 * @param idade A idade do usuário.
 * @param country O país do usuário.
 * @param passport O número do passaporte do usuário.
 * @param nf O número de voos feitos pelo usuário.
 * @param nr O número de reservas feitas pelo usuário.
 * @param t O montante total gasto pelo usuário em reservas.
 */
void to_txt_1_u(int i, char* name, char* sex, int idade, char* country, char* passport, int nf, int nr, double t);

/**
 * @brief Escreve dados de voo em um arquivo de texto com um formato específico (Formato 1 para voos).
 *
 * @param i O número da linha.
 * @param airline A companhia aérea associada ao voo.
 * @param plane O modelo de avião associado ao voo.
 * @param origem O local de partida do voo.
 * @param destino O destino do voo.
 * @param sdd O horário estimado de partida do voo.
 * @param sad O horário estimado de chegada do voo.
 * @param p O número de passageiros no voo.
 * @param delay A informação de atraso associada ao voo.
 */
void to_txt_1_f(int i, char* airline, char* plane, char* origem, char* destino, char* sdd, char* sad, int p, char* delay);

/**
 * @brief Escreve dados de reserva em um arquivo de texto com um formato específico (Formato 1 para reservas).
 *
 * @param i O número da linha.
 * @param hotel_i O ID do hotel associado à reserva.
 * @param hotel_n O nome do hotel associado à reserva.
 * @param stars A classificação de estrelas do hotel associado à reserva.
 * @param bd A data de início da reserva.
 * @param ed A data de término da reserva.
 * @param ib A inclusão de café da manhã na reserva.
 * @param n O número de noites na reserva.
 * @param t O montante total gasto na reserva.
 */
void to_txt_1_r(int i, char* hotel_i, char* hotel_n, char* stars, char* bd, char* ed, char* ib, int n, double t);

/**
 * @brief Função de interpretação de testes.
 *
 * @param tokens A matriz de ponteiros de caracteres contendo os tokens.
 * @param j O índice do token.
 * @param i O número da linha.
 * @param catalog_s O conjunto de catálogos a ser utilizado durante a interpretação.
 * @param l O número máximo de tokens.
 * @param path O caminho para o arquivo de configuração.
 */
void interpreter_tests(char** tokens, int j, int i, Catalogs* catalog_s, int l, char * path);


#endif /* _BATSH_H_ */
