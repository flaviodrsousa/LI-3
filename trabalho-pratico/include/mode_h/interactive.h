/**
 * @file interactive.h
 * @brief Arquivo de cabeçalho para funções de processamento interativo.
 *
 * Este arquivo contém a declaração de funções responsáveis pelo processamento interativo de dados.
 * As funções incluem a escrita de dados em um arquivo de texto com formatos específicos para usuários, voos e reservas,
 * além de uma função de processamento em lote que recebe arquivos de dados de entrada e os processa em GHashTables.
 *
 * @author [Grupo35]
 */

#ifndef _INTERACTIVE_H_
#define _INTERACTIVE_H_

#include <glib.h>
#include "../include/catalogs_h/catalogs.h"
#include "../include/interpreter_h/interpreter.h"

/**
 * @brief Processamento interativo de dados em GHashTables.
 *
 * Esta função realiza o processamento interativo de dados, interagindo com o usuário e atualizando GHashTables para usuários, voos, reservas e passageiros.
 *
 * @param catalog_c O conjunto de catálogos a ser atualizado durante o processamento interativo.
 */
void interactive (Catalogs* catalog_c);

#endif