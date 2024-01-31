#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/catalogs_h/catalog_reservations_aux.h"
#include "../include/catalogs_h/catalog_flights_aux.h"
#include "../include/catalogs_h/catalog_passengers_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/queries_h/query2.h"
#include "../include/queries_h/query2_output.h"
#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_list.h"
#include "../include/structs_h/struct_passengers.h"

struct TreeV {
    char* id_flight;       ///< The ID associated with the flight.
    Voo* flight;           ///< A pointer to the flight information.
    struct TreeV* left;    ///< A pointer to the left child of the node.
    struct TreeV* right;   ///< A pointer to the right child of the node.
};


struct TreeR {
    char* id_reservation;   ///< The ID associated with the reservation.
    Reserva* reservation;   ///< A pointer to the reservation information.
    struct TreeR* left;     ///< A pointer to the left child of the node.
    struct TreeR* right;    ///< A pointer to the right child of the node.
};

struct ListNode {
    char* id_flight;        ///< The ID associated with the flight.
    Voo* flight;            ///< A pointer to the flight information.
    char* id_reservation;   ///< The ID associated with the reservation.
    Reserva* reservation;   ///< A pointer to the reservation information.
    struct ListNode* next;  ///< A pointer to the next node in the linked list.
};


struct ListX {
    ListNode* top;   ///< A pointer to the top (first) node in the linked list.
    ListNode* last;  ///< A pointer to the last node in the linked list.
};


void query2(GHashTable* reservations, GHashTable* flights, GHashTable* users, char* input, char* type, int t, int j, int l) {
    Utilizador* usr = (Utilizador*)(g_hash_table_lookup(users, input));
    if (usr == NULL || getStatus(usr) == 0) {
        FILE *arquivo;
        char file[40]; // Ajuste o tamanho conforme necessário

        // Cria o nome do arquivo com o número i
        snprintf(file, sizeof(file), "Resultados/command%d_output.txt", j);


        arquivo = fopen(file, "a+");
        fprintf(arquivo, "");
    return;
    }

    if (strncasecmp(type, "flights", 7) == 0) {
        TreeV* v = userFlights(users, flights, input);
        ListX* list = malloc(sizeof(ListX));
        list->top=NULL;
        list->last=NULL;
        TreeToListV(v, list);
        ImprimirListaV(list, t, j, l);
        freeTreeV(v);
        free(list);

    } else if (strncasecmp(type, "reservations", 12) == 0) {
        TreeR* r = useReservations(reservations, input);
        ListX* list = malloc(sizeof(ListX));
        list->top=NULL;
        list->last=NULL;
        TreeToListR(r, list);
        ImprimirListaR(list, t, j, l);
        freeTreeR(r);
        free(list);

    } else {
        TreeV* v = userFlights(users, flights, input);
        ListX* v_list = malloc(sizeof(ListX));
        v_list->top=NULL;
        v_list->last=NULL;
        TreeToListV(v, v_list);
        TreeR* r = useReservations(reservations, input);
        ListX* r_list = malloc(sizeof(ListX));
        r_list->top=NULL;
        r_list->last=NULL;
        TreeToListR(r, r_list);
        ImprimirListaVeR(v_list, r_list, t, j, l);
        freeTreeV(v);
        freeTreeR(r);
        free(v_list);
        free(r_list);
    }
}



TreeV* criarNoV(char* id_f, Voo* flight) {
    TreeV* novoNo = (TreeV*)malloc(sizeof(TreeV));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }

    novoNo->id_flight = strdup(id_f);
    novoNo->flight = flight;
    novoNo->left = NULL;
    novoNo->right = NULL;

    return novoNo;
}

TreeV* inserirV(TreeV* raiz, char* id_f, Voo* f) {
    if (raiz == NULL) {
        return criarNoV(id_f, f);
    }

    int comparacao = compare_date(getPartidaEstimada(f), getPartidaEstimada(raiz->flight));

    if (comparacao == 1 || (comparacao == 2 && atoi(id_f) < atoi(raiz->id_flight))) {
        raiz->left = inserirV(raiz->left, id_f, f);
    } else if (comparacao == 0 || (comparacao == 2 && atoi(id_f) > atoi(raiz->id_flight))) {
        raiz->right = inserirV(raiz->right, id_f, f);
    }

    return raiz;
}

TreeV* userFlights(GHashTable* users, GHashTable* flights, char* input) {
    TreeV* arvore = NULL;

    List* lista = getListUser(g_hash_table_lookup(users, input));
    List* temp = lista;

    while(temp != NULL){
        char* id_flight = getDataList(temp);
        arvore = inserirV(arvore, id_flight, g_hash_table_lookup(flights, id_flight));
        free(id_flight);
        temp = getNextList(temp);
    }
    free(temp);
    return arvore;
}

//-------- Para a reserva ---------------

TreeR* criarNoR(char* id_r, Reserva* reservation) {
    TreeR* novoNo = (TreeR*)malloc(sizeof(TreeR));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }

    novoNo->id_reservation = strdup(id_r);
    novoNo->reservation = reservation;
    novoNo->left = NULL;
    novoNo->right = NULL;

    return novoNo;
}

TreeR* inserirR(TreeR* raiz, char* id_r, Reserva* r) {
    int data, data_raiz;

    if (raiz == NULL) {
        return criarNoR(id_r, r);
    }
    char* dataInicial = getDataInicial(r);
    char* dataInicial2 = getDataInicial(raiz->reservation);
    char* dataFim = getDataFim(raiz->reservation);
    
    int i = strlen(dataInicial) - 1;
    int j = strlen(dataInicial2);

    // Enquanto o caractere atual for um dígito
    while (i >= 0 && isdigit(dataInicial[i])) {
        data = data * 10 + (dataInicial[i] - '0');
        i--;
    }

    while (j >= 0 && isdigit(dataInicial2[j])) {
        data_raiz = data_raiz * 10 + (dataInicial2[j] - '0');
        j--;
    }


    int comparacao = strcmp(dataInicial, dataFim);

    if (comparacao < 0 || (comparacao == 0 && data < data_raiz)) {
        raiz->left = inserirR(raiz->left, id_r, r);
    } else if (comparacao > 0 || (comparacao == 0 && data > data_raiz)) {
        raiz->right = inserirR(raiz->right, id_r, r);
    }

    free(dataInicial);
    free(dataInicial2);
    free(dataFim);

    return raiz;
}

TreeR* useReservations(GHashTable* reservations, char* input) {
    GHashTableIter iter;
    gpointer key, value;

    TreeR* arvore = NULL;

    g_hash_table_iter_init(&iter, reservations);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char* user = getIdUser(value);
        if (strcmp(input, user) == 0) {
            arvore = inserirR(arvore, key, g_hash_table_lookup(reservations, key));
        }
        free (user);
    }

    return arvore;
}
