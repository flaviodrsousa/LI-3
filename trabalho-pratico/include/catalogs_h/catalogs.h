#ifndef _CATALOGS_H_
#define _CATALOGS_H_

#include <glib.h>
#include "../include/catalogs_h/catalog_users.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_passengers.h"

/**
 * @file catalogs.h
 * @brief Documentação para o programa que gerencia catálogos de utilizadores, voos, reservas e passageiros.
 */

/**
 * @struct catalogs
 * @brief Estrutura que representa um conjunto de catálogos.
 */
typedef struct catalogs Catalogs;

/**
 * @brief Cria um conjunto de catálogos a partir do caminho especificado.
 *
 * @param[in] path O caminho para o arquivo de configuração.
 * @return Um ponteiro para a estrutura de catálogos criada.
 */
Catalogs* create_catalogs(char* path);

/**
 * @brief Obtém o catálogo de utilizadores do conjunto de catálogos.
 *
 * @param[in] catalogs O conjunto de catálogos do qual se deseja obter o catálogo de utilizadores.
 * @return O catálogo de utilizadores contido no conjunto de catálogos.
 */
Catalog_users* get_user_catalog(const struct catalogs* catalogs);

/**
 * @brief Obtém o catálogo de voos do conjunto de catálogos.
 *
 * @param[in] catalogs O conjunto de catálogos do qual se deseja obter o catálogo de voos.
 * @return O catálogo de voos contido no conjunto de catálogos.
 */
Catalog_flights* get_flight_catalog(const struct catalogs* catalogs);

/**
 * @brief Obtém o catálogo de reservas do conjunto de catálogos.
 *
 * @param[in] catalogs O conjunto de catálogos do qual se deseja obter o catálogo de reservas.
 * @return O catálogo de reservas contido no conjunto de catálogos.
 */
Catalog_reservations* get_reservation_catalog(const struct catalogs* catalogs);

/**
 * @brief Liberta a memória alocada para o conjunto de catálogos.
 *
 * @param[in] cata O conjunto de catálogos a ser libertado.
 */
void free_catalogs(Catalogs* cata);


#endif