#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/catalogs_h/catalog_passengers.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/queries_h/query1_output.h"
#include "../include/queries_h/query2.h"
#include "../include/queries_h/query5.h"
#include "../include/queries_h/query5_output.h"
#include "../include/menu_h/interface.h"

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


void query5 (GHashTable* flights, char *input, char* data1, char* data2, int i, int j, int l){
        TreeV* r = voosOrigem(flights, input, data1, data2);
        int k = contaNos (r);
        if (l == 0){
        percorrerEmOrdemB(r, i,j,k,l);
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
            printPageV(r, i, j, k, l, p);
            p++;
        }else if (choice == 'P' || choice == 'p') {
            system("clear");
            pageN(p);
            printPageV(r, i, j, k, l, p);
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
        libertarArvoreB(r);
               
}

TreeV* criarNoB(char* id_f, Voo* flight) {
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

TreeV* inserirB(TreeV* raiz, char* id_f, Voo* f) {
    if (raiz == NULL) {
        return criarNoB(id_f, f);
    }

    char* partidaEstimada = getPartidaEstimada(f);
    char* partidaEstimadaF = getPartidaEstimada(raiz->flight);
    int comparacao = compare_date_time(partidaEstimada, partidaEstimadaF);

    if (comparacao == 1 || (comparacao == 2 && atoi(id_f) < atoi(raiz->id_flight))) {
        raiz->left = inserirB(raiz->left, id_f, f);
    } else if (comparacao == 0 || (comparacao == 2 && atoi(id_f) > atoi(raiz->id_flight))) {
        raiz->right = inserirB(raiz->right, id_f, f);
    }
    free(partidaEstimada);
    free(partidaEstimadaF);

    return raiz;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void percorrerEmOrdemB(TreeV* raiz, int i, int j, int k, int l) {
    char resultado[4];
    if(l == 0){
    char linha[100];
    if (raiz != NULL) {
        percorrerEmOrdemB(raiz->left,i,j,k,l);
    for (int l = 0; l < 4; l++) {
        if(l<3){
        char* dest = getDestino(raiz->flight);
        resultado[l] = toupper(dest[l]);
        free(dest);
        } else {resultado[l] = '\0';}
    }
        char* partidaEstimada = getPartidaEstimada(raiz->flight);
        char* aviao = getAviao(raiz->flight);
        char* companhia = getCompanhia(raiz->flight);
        snprintf(linha, sizeof(linha), "%s;%s;%s;%s;%s\n", raiz->id_flight, partidaEstimada, resultado, companhia, aviao);
       
        if(j == 0){to_txt_0(i, linha);}
        else{to_txt_5(raiz->id_flight, partidaEstimada, resultado, companhia, aviao, i,k);}
        percorrerEmOrdemB(raiz->right,i,j,k,l);
        free(partidaEstimada);
        free(aviao);
        free(companhia);
        }
    }
}
int contaNos(TreeV* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return contaNos(raiz->left) + contaNos(raiz->right) + 1;
    }
}

// Função para liberar a memória ocupada pela árvore
void libertarArvoreB(TreeV* raiz) {
    if (raiz != NULL) {
        libertarArvoreB(raiz->left);
        libertarArvoreB(raiz->right);
        free(raiz->id_flight);
        free(raiz);
    }
}

TreeV* voosOrigem(GHashTable* flights, char* input, char* date1, char* date2) {
    GHashTableIter iter;
    gpointer key, value;

    TreeV* arvore = NULL;

    g_hash_table_iter_init(&iter, flights);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char* origin = getOrigem(value);
        char* partida = getPartidaEstimada(value);

        if (strcasecmp(input, origin) == 0 && compare_date_time(partida, date1) == 1 && compare_date_time(partida, date2) == 0){
            char* id_flight = key;
            arvore = inserirB(arvore, id_flight, g_hash_table_lookup(flights, id_flight));
        }
        free(origin);
        free(partida);
    }

    return arvore;
}

void printNodeV(TreeV* raiz) {
    char resultado[4];
    char* partida = getPartidaEstimada(raiz->flight);
    char* aviao = getAviao(raiz->flight);
    char* companhia = getCompanhia(raiz->flight);
    char* dest = getDestino(raiz->flight);

    for (int l = 0; l < 3; l++) {
    resultado[l] = toupper(dest[l]);
    }
    resultado[3] = '\0';

    printf("%s;%s;%s;%s;%s\n", raiz->id_flight, partida, resultado, companhia, aviao);

    free(partida);
    free(aviao);
    free(companhia);
    free(dest);

}
void printPageV(struct TreeV* raiz, int i, int j, int k, int l, int pageNumber) {    
    int totalNodes = contaNos(raiz);

    struct TreeV* nodesArray[totalNodes];
    int currentIndex = 0;

    storeNodesInArrayV(raiz, nodesArray, &currentIndex);

    int linesPerPage = 15;
    int startLine = (pageNumber - 1) * linesPerPage;
    int endLine = startLine + linesPerPage;

    for (int line = startLine; line < endLine && line < totalNodes; ++line) {
        printf("Line %d: ", line + 1);
        printNodeV(nodesArray[line]);
    }
}

void storeNodesInArrayV(TreeV* raiz, TreeV* nodesArray[], int* currentIndex) {
    if (raiz != NULL) {
        storeNodesInArrayV(raiz->left, nodesArray, currentIndex);

        nodesArray[*currentIndex] = raiz;
        (*currentIndex)++;

        storeNodesInArrayV(raiz->right, nodesArray, currentIndex);
    }
}