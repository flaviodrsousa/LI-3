#include "../include/structs_h/struct_reservations.h"

struct reserva {
    char* id_user;            ///< User identifier who made the reservation.
    char* id_hotel;           ///< Identifier of the reserved hotel.
    char* nome_hotel;         ///< Name of the reserved hotel.
    char* estrelas_hotel;     ///< Hotel star rating.
    char* data_inicial;       ///< Start date of the reservation.
    char* data_fim;           ///< End date of the reservation.
    char* pequeno_almoco;     ///< Information about the inclusion of breakfast.
    double preco_total;       ///< Total price of the reservation.
    char* preco_noite;        ///< Price per night of the stay.
    char* classificacao;      ///< Rating assigned to the reservation.
};

void set_reserva(Reserva* reserva, char* id_user, char* id_hotel,char* nome_hotel, char* estrelas_hotel, char* data_inicial, char* data_fim, char* pequeno_almoco, double preco_total, char* preco_noite, char* classificacao) {
    reserva->id_user = strdup(id_user);
    reserva->id_hotel = strdup(id_hotel);
    reserva->nome_hotel = strdup(nome_hotel);
    reserva->estrelas_hotel = strdup(estrelas_hotel);
    reserva->data_inicial = strdup(data_inicial);
    reserva->data_fim = strdup(data_fim);
    reserva->pequeno_almoco = strdup(pequeno_almoco);
    reserva->preco_total = preco_total;
    reserva->preco_noite = strdup(preco_noite);
    reserva->classificacao = strdup(classificacao);
}

void free_reserva(Reserva* reserva) {
    free(reserva->id_user);
    free(reserva->id_hotel);
    free(reserva->nome_hotel);
    free(reserva->estrelas_hotel);
    free(reserva->data_inicial);
    free(reserva->data_fim);
    free(reserva->pequeno_almoco);
    free(reserva->preco_noite);
    free(reserva->classificacao);
}

Reserva* create_res() {
    Reserva* reservation = (Reserva*)malloc(sizeof(Reserva));
    return reservation;
}

void free_hash_tableR(gpointer key, gpointer value, gpointer user_data) {
    free_reserva((Reserva*)value);
}

// Getters

char *getIdUser(const Reserva *reservation) {
    return strdup(reservation->id_user);
}

char *getIdHotel(const Reserva *reservation) {
    return strdup(reservation->id_hotel);
}

char *getNomeHotel(const Reserva *reservation) {
    return strdup(reservation->nome_hotel);
}

char *getEstrelasHotel(const Reserva *reservation) {
    return strdup(reservation->estrelas_hotel);
}

char *getDataInicial(const Reserva *reservation) {
    return strdup(reservation->data_inicial);
}

char *getDataFim(const Reserva *reservation) {
    return strdup(reservation->data_fim);
}

char *getPequenoAlmoco(const Reserva *reservation) {
    return strdup(reservation->pequeno_almoco);
}

double getPrecoTotal(const Reserva *reservation) {
    return reservation->preco_total;
}

char *getPrecoNoite(const Reserva *reservation) {
    return strdup(reservation->preco_noite);
}
char *getClassificacao(const Reserva *reservation) {
    return strdup(reservation->classificacao);
}