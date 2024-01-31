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


ListNode* createNode(char* id_flight, Voo* flight, char* id_reservation, Reserva* reservation) {
    ListNode* newNode = malloc(sizeof(ListNode));
    newNode->id_flight = id_flight;
    newNode->flight = flight;
    newNode->id_reservation = id_reservation;
    newNode->reservation = reservation;
    newNode->next = NULL;

    return newNode;
}

void freeListNode(ListNode* node) {
    if (node != NULL) {
        printf("ola\n");
        free(node->id_flight);
        printf("ola1\n");
        free(node->id_reservation);
        printf("ola2\n");
        //freeListNode(node->next);
        //free(node);
    }
}

void TreeToListV(TreeV * v, ListX* n) {
    
    if(v ==NULL) {
        return;
    }


    TreeToListV(v->left, n);
    ListNode* new_node = createNode(v->id_flight, v->flight, NULL, NULL);
    if (n->top==NULL){
        n->top = new_node;
        n->last = new_node;
    }
    else {
        n->last->next = new_node;
        n->last=new_node;
    }
    
    
    TreeToListV(v->right, n);

}


void TreeToListR(TreeR * r, ListX* n) {
    
    if(r == NULL) {
        return;
    }


    TreeToListR(r->right, n);
    ListNode* new_node = createNode(NULL, NULL, r->id_reservation, r->reservation);
    if (n->top==NULL){
        n->top = new_node;
        n->last = new_node;
    }
    else {
        n->last->next = new_node;
        n->last=new_node;
    }
    
    
    TreeToListR(r->left, n);

}


void ImprimirListaV(ListX* x, int type, int j, int l) {
if(l == 0) {
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", j);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }
    
    ListNode* iter = x->top;
    int i = 1;

    while(iter) {
        if(iter->next == NULL) {
            if(type == 1) {
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %.10s\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
            } else {
                fprintf(arquivo, "%s;%.10s\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
            }
        } else {
            if(type == 1) {
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %.10s\n\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
            } else {
                fprintf(arquivo, "%s;%.10s\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
            }
        }
    }

    fclose(arquivo);
} else {
    ListNode* iter = x->top;
    int i = 1;

    while(iter) {
        if(iter->next == NULL) {
                printf("%s;%.10s\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
        } else {
                printf("%s;%.10s\n", iter->id_flight, getPartidaEstimada(iter->flight));
                iter = iter->next;
        }
    }

    }
}


void ImprimirListaR(ListX* x, int type, int j, int l) {

if(l == 0) {
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", j);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    ListNode* iter = x->top;
    int i = 1;

    while(iter) {
        if(iter->next == NULL) {
            if(type == 1) {
                char* dataInicial = getDataInicial(iter->reservation);
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %s\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
                
            } else {
                char* dataInicial = getDataInicial(iter->reservation);
                fprintf(arquivo, "%s;%s\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
            }
        } else {
            if(type == 1) {
                char* dataInicial = getDataInicial(iter->reservation);
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %s\n\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
                
            } else {
                char* dataInicial = getDataInicial(iter->reservation);
                fprintf(arquivo, "%s;%s\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
            }
        
        }
    }

    fclose(arquivo);
    
} else {
    ListNode* iter = x->top;
    int i = 1;

    while(iter) {
        if(iter->next == NULL) {
                char* dataInicial = getDataInicial(iter->reservation);
                printf("%s;%s\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
        } else {
                char* dataInicial = getDataInicial(iter->reservation);
                printf("%s;%s\n", iter->id_reservation, dataInicial);
                free(dataInicial);
                iter = iter->next;
            }
        
        }
    }
}


void ImprimirListaVeR(ListX* v, ListX* r, int type, int j, int l) {
if(l == 0) {
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", j);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    
    ListNode* v_iter = v->top;
    ListNode* r_iter = r->top;

    int i = 1;


    while (v_iter != NULL && r_iter != NULL) {
        char* dataInicial = getDataInicial(r_iter->reservation);
        char* partidaEstimanda = getPartidaEstimada(v_iter->flight);
        if(compare_date(partidaEstimanda, dataInicial) == 2) {
            if(strcmp(v_iter->id_flight, r_iter->id_reservation) < 0) {
                if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                    if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    }
                } else {
                    if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    }
                }
            }
        } else if(compare_date(partidaEstimanda, dataInicial) == 0){
            if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %s\ntype: reservation\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%s;reservation\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
                    }
            } else {
                    if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %s\ntype: reservation\n\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%s;reservation\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
                    }
            }
        } else if (compare_date(partidaEstimanda, dataInicial) == 1) {
            if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    }
            } else {
                if(type == 1) {
                        fprintf(arquivo, "--- %d ---\n", i++);
                        fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    } else {
                        fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                    }
            }
        }
        free(dataInicial);
        free(partidaEstimanda);
    }



    while (v_iter != NULL) {
        if(v_iter->next == NULL) {
            char* partida = getPartidaEstimada(v_iter->flight);
            if(type == 1) {
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n", v_iter->id_flight, partida);
                    v_iter = v_iter->next;
            } else {
                fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partida);
                v_iter = v_iter->next;
            }
            free(partida);
        } else {
            char* partida = getPartidaEstimada(v_iter->flight);
            if(type == 1) {
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %.10s\ntype: flight\n\n", v_iter->id_flight, partida);
                    v_iter = v_iter->next;
            } else {
                fprintf(arquivo, "%s;%.10s;flight\n", v_iter->id_flight, partida);
                v_iter = v_iter->next;
            }
            free(partida);
        }
    }

    while (r_iter != NULL) {
        if(r_iter->next == NULL) {
            if(type == 1) {
                char* data = getDataInicial(r_iter->reservation);
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %s\ntype: reservation\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
            } else {
                char* data = getDataInicial(r_iter->reservation);
                fprintf(arquivo, "%s;%s;reservation\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
            }
        } else {
            if(type == 1) {
                char* data = getDataInicial(r_iter->reservation);
                fprintf(arquivo, "--- %d ---\n", i++);
                fprintf(arquivo, "id: %s\ndate: %s\ntype: reservation\n\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
            } else {
                char* data = getDataInicial(r_iter->reservation);
                fprintf(arquivo, "%s;%s;reservation\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
            }
        }
    }
} else {
    ListNode* v_iter = v->top;
    ListNode* r_iter = r->top;

    int i = 1;


    while (v_iter != NULL && r_iter != NULL) {
        char* dataInicial = getDataInicial(r_iter->reservation);
        char* partidaEstimanda = getPartidaEstimada(v_iter->flight);
        if(compare_date(partidaEstimanda, dataInicial) == 2) {
            if(strcmp(v_iter->id_flight, r_iter->id_reservation) < 0) {
                if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                        printf("%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                } else {
                        printf("%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
                }
            }
        } else if(compare_date(partidaEstimanda, dataInicial) == 0){
            if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                        printf("%s;%s;reservation\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
            } else {
                        printf("%s;%s;reservation\n", r_iter->id_reservation, dataInicial);
                        r_iter = r_iter->next;
            }
        } else if (compare_date(partidaEstimanda, dataInicial) == 1) {
            if((v_iter->next == NULL && r_iter == NULL) || (v_iter == NULL && r_iter->next == NULL)) {
                        printf("%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
            } else {
                        printf("%s;%.10s;flight\n", v_iter->id_flight, partidaEstimanda);
                        v_iter = v_iter->next;
            }
        }
        free(dataInicial);
        free(partidaEstimanda);
    }



    while (v_iter != NULL) {
        if(v_iter->next == NULL) {
            char* partida = getPartidaEstimada(v_iter->flight);
                printf("%s;%.10s;flight\n", v_iter->id_flight, partida);
                v_iter = v_iter->next;
                free(partida);
        } else {
            char* partida = getPartidaEstimada(v_iter->flight);
                printf("%s;%.10s;flight\n", v_iter->id_flight, partida);
                v_iter = v_iter->next;
                free(partida);
        }
    }

    while (r_iter != NULL) {
        if(r_iter->next == NULL) {
                char* data = getDataInicial(r_iter->reservation);
                printf("%s;%s;reservation\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
        } else {
                char* data = getDataInicial(r_iter->reservation);
                printf("%s;%s;reservation\n", r_iter->id_reservation, data);
                free(data);
                r_iter = r_iter->next;
        }
    }

    }
}


// Function to free memory for a TreeV
void freeTreeV(TreeV* raiz) {

    if (raiz != NULL) {
        freeTreeV(raiz->left);
        freeTreeV(raiz->right);
        free(raiz->id_flight);
        free(raiz);
    }
}

// Function to free memory for a TreeR
void freeTreeR(TreeR* raiz) {
     if (raiz != NULL) {
        freeTreeR(raiz->left);
        freeTreeR(raiz->right);
        free(raiz->id_reservation);
        free(raiz);
    }
}

