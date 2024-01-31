#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_list.h"

struct voo {
    char* companhia;           ///< The airline company associated with the flight.
    char* aviao;               ///< The airplane model associated with the flight.
    char* origem;              ///< The departure location of the flight.
    char* destino;             ///< The destination of the flight.
    char* partida_estimada;    ///< The estimated departure time of the flight.
    char* chegada_estimada;    ///< The estimated arrival time of the flight.
    char* atraso;              ///< The delay information associated with the flight.
    int n_passageiros;         ///< The total passengers at the flight
};

struct lista {
    char *id_flight;
    int passengers;
    struct lista *next;
};

void set_voo(Voo* flight, char* companhia, char* aviao, char* origem, char* destino, char* p_e, char* c_e, char* atraso) {
    flight->companhia = strdup(companhia);
    flight->aviao = strdup(aviao);
    flight->origem = strdup(origem);
    flight->destino = strdup(destino);
    flight->partida_estimada = strdup(p_e);
    flight->chegada_estimada = strdup(c_e);
    flight->atraso = strdup(atraso);
    flight->n_passageiros = 0;
}

Voo* create_voo() {
    Voo* flight = (Voo*)malloc(sizeof(Voo));
    return flight;
}

void free_voo(Voo* flight) {
    free(flight->companhia);
    free(flight->aviao);
    free(flight->origem);
    free(flight->destino);
    free(flight->partida_estimada);
    free(flight->chegada_estimada);
    free(flight->atraso);
}

void free_hash_tableV(gpointer key, gpointer value, gpointer user_data) {
    free_voo((Voo*)value);
}

//Getters

char *getCompanhia(const Voo *flight) {
    return strdup(flight->companhia);
}

char *getAviao(const Voo *flight) {
    return strdup(flight->aviao);
}

char *getOrigem(const Voo *flight) {
    return strdup(flight->origem);
}

char *getDestino(const Voo *flight) {
    return strdup(flight->destino);
}

char *getPartidaEstimada(const Voo *flight) {
    return strdup(flight->partida_estimada);
}

char *getChegadaEstimada(const Voo *flight) {
    return strdup(flight->chegada_estimada);
}

char *getAtraso(const Voo *flight) {
    return strdup(flight->atraso);
}

int getN_Passageiros(const Voo *flight) {
    if (flight != NULL) {
        return flight->n_passageiros;
    }
    return 0;  // Ou algum valor padrão apropriado se o Voo for nulo
}

void incrementeN_Passageiros(Voo *flight) {
    flight->n_passageiros++;
};