#include "../include/catalogs_h/catalog_users.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_passengers.h"
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_reservations.h"
#include "../include/structs_h/struct_passengers.h"
#include "../include/structs_h/struct_list.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/catalogs_h/catalog_passengers_aux.h"
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
struct catalogs {
    Catalog_users* u_catalog;
    Catalog_flights* f_catalog;
    Catalog_reservations* r_catalog; 
};

Catalog_users* get_user_catalog(const struct catalogs* catalogs) {
    return catalogs->u_catalog;
}

Catalog_flights* get_flight_catalog(const struct catalogs* catalogs) {
    return catalogs->f_catalog;
}

Catalog_reservations* get_reservation_catalog(const struct catalogs* catalogs) {
    return catalogs->r_catalog;
}


Catalogs* create_catalogs(char* path) {

    Catalogs* catalog_s = (Catalogs*)malloc(sizeof(Catalogs));

    char *users_file;
    char *reservations_file;
    char *flights_file;
    char *passengers_file;

    // Aloca memória para os nomes dos arquivos
    users_file = (char *)malloc(strlen(path) + strlen("/users.csv") + 1);
    reservations_file = (char *)malloc(strlen(path) + strlen("/reservations.csv") + 1);
    flights_file = (char *)malloc(strlen(path) + strlen("/flights.csv") + 1);
    passengers_file = (char *)malloc(strlen(path) + strlen("/passengers.csv") + 1);

    if (users_file == NULL || reservations_file == NULL || flights_file == NULL || passengers_file == NULL) {
        perror("Falha na alocação de memória dos nomes dos arquivos");
    }

    // Construir os caminhos dos arquivos
    strcpy(users_file, path);
    strcat(users_file, "/users.csv");

    strcpy(reservations_file, path);
    strcat(reservations_file, "/reservations.csv");

    strcpy(flights_file, path);
    strcat(flights_file, "/flights.csv");

    strcpy(passengers_file, path);
    strcat(passengers_file, "/passengers.csv");

    printf("\nA CRIAR CATÁLOGOS DOS USERS");
    catalog_s->u_catalog = create_users_catalog(users_file);
    printf("\nA CRIAR CATÁLOGOS DOS FLIGHTS");
    catalog_s->f_catalog = create_flights_catalog(flights_file);
    printf("\nA CRIAR CATÁLOGOS DAS RESERVATIONS");
    catalog_s->r_catalog = create_reservations_catalog(reservations_file, get_users_hash(catalog_s->u_catalog));
    printf("\nA CRIAR CATÁLOGOS DOS PASSENGERS");
    create_passengers_catalog(passengers_file, get_users_hash(catalog_s->u_catalog), get_flights_hash(catalog_s->f_catalog));
    printf("\nA CORRIGIR CATÁLOGO DOS FLIGHTS");
    check_sits_flight(flights_file, get_flights_hash(catalog_s->f_catalog));
    printf("\nA CORRIGIR CATÁLOGO DOS PASSENGERS\n");

    free(users_file);
    free(reservations_file);
    free(flights_file);
    free(passengers_file);

    return catalog_s;
}

void free_catalogs(Catalogs* cata) {

    g_hash_table_foreach(get_reservations_hash(cata->r_catalog), free_hash_tableR, NULL);
    g_hash_table_foreach(get_users_hash(cata->u_catalog), free_hash_tableU, NULL);
    g_hash_table_foreach(get_flights_hash(cata->f_catalog), free_hash_tableV, NULL);

    g_hash_table_destroy(get_users_hash(cata->u_catalog));
    g_hash_table_destroy(get_flights_hash(cata->f_catalog));
    g_hash_table_destroy(get_users_hash(cata->r_catalog));
    free(cata);
}