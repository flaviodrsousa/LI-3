#include "../include/structs_h/struct_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista
struct list {
    char* data;            
    struct list* next;     
};

List* set_list(const char* data) {
    List* newNode = (List*)malloc(sizeof(struct list));
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

void setNextList(List* pass, List* nex) {
    pass->next = nex;
}

char* getDataList(const struct list* lista) {
    return strdup(lista->data);
}

List* getNextList(const struct list* lista) {
    return lista->next;
}

void freeList(List* lista) {
    while (lista != NULL) {
        List* temp = lista;
        lista = lista->next;
        free(temp->data);   
        free(temp);      
    }
}