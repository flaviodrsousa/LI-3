#include "../include/structs_h/struct_passengers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista
struct passageiro {
    char* data;                     ///< Passenger data        
    struct passageiro* next;        ///< Next Passenger Struct
};

// Função para criar um novo nó
Passageiro* set_passageiro(const char* data) {
    Passageiro* newNode = (Passageiro*)malloc(sizeof(struct passageiro));
    if (newNode == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    // Alocar memória para a string e copiar os dados
    newNode->data = strdup(data);

    // Inicializar o próximo nó como NULL
    newNode->next = NULL;

    return newNode;
}

void setNext(Passageiro* pass, Passageiro* nex) {
    pass->next = nex;
}

void free_passageiro(Passageiro* head) {
    Passageiro* current = head;
    Passageiro* next;

    while (current->next != NULL) {
        next = current->next;
        free(current->data);  
        current = next;
    }
    free(current->data);
}

void free_hash_tableP(gpointer key, gpointer value, gpointer user_data) {
    free_passageiro((struct passageiro*)value);
}

char *getUser(const Passageiro* passenger) {
    return strdup(passenger->data);
}

Passageiro* getNext(const Passageiro* passenger) {
    return passenger->next;
}