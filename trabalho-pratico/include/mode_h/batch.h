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
 * @brief Processamento em lote de arquivos de dados em GHashTables.
 *
 * Esta função recebe arquivos de dados de entrada, os processa e preenche GHashTables para usuários, voos, reservas e passageiros.
 *
 * @param catalogo_s O conjunto de catálogos a ser atualizado durante o processamento em lote.
 * @param file O arquivo de dados de entrada a ser processado.
 */
void batch(Catalogs* catalogo_s, char *file);

#endif