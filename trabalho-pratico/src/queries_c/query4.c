#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_flights_aux.h"
#include "../include/catalogs_h/catalog_passengers_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/queries_h/query1_output.h"
#include "../include/queries_h/query2.h"
#include "../include/queries_h/query4.h"
#include "../include/queries_h/query4_output.h"
#include "../include/menu_h/interface.h"

#define LINES_PER_PAGE 15

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

void query4 (GHashTable* reservations, char *input, int i, int j, int l){
        TreeR* r = hotelReservations(reservations, input);
        int k = contaNosR (r);
        if(l == 0){
        percorrerEmOrdemH(r,i,j,k,l);
        } else if (l ==1){
            char choice;
            int p = 1;
            printf("Press N to go to the first page.\n");
            while (1) {
            pageBar();
            scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            system("clear");
            pageN(p);
            printPage(r, i, j, k, l, p);
            p++;
        }else if (choice == 'P' || choice == 'p') {
            system("clear");
            pageN(p);
            printPage(r, i, j, k, l, p);
            p--;
        } else if (choice == 'Q' || choice == 'q') {
            system("clear");
            printf("Quitting...\n");
            break; 
        } else {
            printf("Invalid choice. Please enter 'N' or 'Q'.\n");
        }
    }
        }
        libertarArvoreH(r);
}



TreeR* criarNoH(char* id_r, Reserva* reservation) {
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

TreeR* inserirH(TreeR* raiz, char* id_r, Reserva* r) {

    if (raiz == NULL) {
        return criarNoR(id_r, r);
    }
    
    char* dataInicial1 = getDataInicial(raiz->reservation);
    char* dataInicial2 = getDataInicial(r);
    int data = compare_date(dataInicial1, dataInicial2);
    free(dataInicial1);
    free(dataInicial2);

    int comparacao = strcmp(id_r, raiz->id_reservation);

    if (data == 1 || (comparacao > 0 && data == 2)) {
        raiz->left = inserirH(raiz->left, id_r, r);
    } else if (data == 0 || (comparacao < 0 && data == 2)) {
        raiz->right = inserirH(raiz->right, id_r, r);
    }



    return raiz;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void percorrerEmOrdemH(TreeR* raiz,int i,int j, int k, int l) {
    if(l == 0){
    char linha[100];
    if (raiz != NULL) {
        char* idUser = getIdUser(raiz->reservation);
        char* dataInicial = getDataInicial(raiz->reservation);
        char* dataFim = getDataFim(raiz->reservation);
        char* classificacao = getClassificacao(raiz->reservation);
        double precoTotal = getPrecoTotal(raiz->reservation);
        percorrerEmOrdemH(raiz->right,i,j,k,l);
        snprintf(linha, sizeof(linha),"%s;%s;%s;%s;%s;%.3f\n", raiz->id_reservation, dataInicial, dataFim, idUser, classificacao, precoTotal);
        if(j == 0){to_txt_0(i,linha);} 
        else {to_txt_4(raiz->id_reservation, dataInicial, dataFim, idUser, classificacao, precoTotal, i, k);}
        percorrerEmOrdemH(raiz->left,i,j,k,l);
        free(idUser);
        free(dataInicial);
        free(dataFim);
        free(classificacao);
        }
    }
}
void printNode(TreeR* node) {
    char* idUser = getIdUser(node->reservation);
    char* dataInicial = getDataInicial(node->reservation);
    char* dataFim = getDataFim(node->reservation);
    char* classificacao = getClassificacao(node->reservation);
    double precoTotal = getPrecoTotal(node->reservation);

    printf("%s;%s;%s;%s;%s;%.3f\n", node->id_reservation, dataInicial, dataFim, idUser, classificacao, precoTotal);

    free(idUser);
    free(dataInicial);
    free(dataFim);
    free(classificacao);
}

void printPage(struct TreeR* raiz, int i, int j, int k, int l, int pageNumber) {    
    int totalNodes = contaNosR(raiz);

    struct TreeR* nodesArray[totalNodes];
    int currentIndex = 0;

    storeNodesInArray(raiz, nodesArray, &currentIndex);

    int linesPerPage = 15;
    int startLine = (pageNumber - 1) * linesPerPage;
    int endLine = startLine + linesPerPage;

    for (int line = startLine; line < endLine && line < totalNodes; ++line) {
        printf("Line %d: ", line + 1);
        printNode(nodesArray[line]);
    }
}

void storeNodesInArray(TreeR* raiz, TreeR* nodesArray[], int* currentIndex) {
    if (raiz != NULL) {
        storeNodesInArray(raiz->left, nodesArray, currentIndex);

        nodesArray[*currentIndex] = raiz;
        (*currentIndex)++;

        storeNodesInArray(raiz->right, nodesArray, currentIndex);
    }
}

int contaNosR(TreeR* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return contaNosR(raiz->left) + contaNosR(raiz->right) + 1;
    }
}

// Função para liberar a memória ocupada pela árvore
void libertarArvoreH(TreeR* raiz) {
    if (raiz != NULL) {
        libertarArvoreH(raiz->left);
        libertarArvoreH(raiz->right);
        free(raiz->id_reservation);
        free(raiz);
    }
}



TreeR* hotelReservations(GHashTable* reservations, char* input) {
    GHashTableIter iter;
    gpointer key, value;

    TreeR* arvore = NULL;

    g_hash_table_iter_init(&iter, reservations);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char* hotel = getIdHotel(value);
        if (strcmp(input, hotel) == 0) {
            arvore = inserirH(arvore, key, g_hash_table_lookup(reservations, key));
        }
        free(hotel);
    }

    return arvore;
}