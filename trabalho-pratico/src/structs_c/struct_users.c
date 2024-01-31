#include "../include/structs_h/struct_users.h"
#include "../include/structs_h/struct_list.h"

struct utilizador {
    char *nome;            ///< The name of the user.
    char *sexo;            ///< The gender of the user.
    int idade;             ///< The age of the user.
    char *codigo_pais;     ///< The country code of the user.
    char *passport;        ///< The passport number of the user.
    int status;            ///< The status of the user.
    List* voos;            ///< A list of flights associated with the user.
};

void set_utilizador(Utilizador* usr, char* nome, char* sexo, int idade, char* codigo_pais, char* passport, int status) { 
   usr->nome = strdup(nome);
   usr->sexo = strdup(sexo);
   usr->idade = idade;
   usr->codigo_pais = strdup(codigo_pais);
   usr->passport = strdup(passport);
   usr->status = status;
   usr->voos = NULL;
}

Utilizador* create_usr() {
    Utilizador* usr = (Utilizador*)malloc(sizeof(Utilizador));
    return usr;
}

void free_user(Utilizador* usr) {
    free(usr->nome); 
    free(usr->sexo);
    free(usr->codigo_pais); 
    free(usr->passport);
    freeList(usr->voos);

}

void free_hash_tableU(gpointer key, gpointer value, gpointer user_data) {
    free_user((Utilizador*)value);
}

// Getters

char *getNome(const Utilizador *usr) {
    return strdup(usr->nome);
}

char *getSexo(const Utilizador *usr) {
    return strdup(usr->sexo);
}

int getIdade(const Utilizador *usr) {
    return usr->idade;
}

char *getCodigoPais(const Utilizador *usr) {
    return strdup(usr->codigo_pais);
}

char *getPassport(const Utilizador *usr) {
    return strdup(usr->passport);
}

int getStatus(const Utilizador *usr) {
    return usr->status;
}

List* getListUser(const Utilizador *usr) {
    return usr->voos;
}

void setListUser(Utilizador* usr, List* lista) {
    usr->voos = lista;
}