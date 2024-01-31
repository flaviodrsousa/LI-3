#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>

void to_txt_0(int i, const char *linha) {
    
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);


    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    if(strcmp(linha, "") != 0) {
        fprintf(arquivo, "%s", linha);
    }

    fclose(arquivo);
}

void to_txt_1_u(int i, char* name, char* sex, int idade, char* country, char* passport, int nf, int nr, double t) {
    
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- 1 ---\n");
    fprintf(arquivo, "name: %s\n", name);
    fprintf(arquivo, "sex: %s\n", sex);
    fprintf(arquivo, "age: %d\n", idade);
    fprintf(arquivo, "country_code: %s\n", country);
    fprintf(arquivo, "passport: %s\n", passport);
    fprintf(arquivo, "number_of_flights: %d\n", nf);
    fprintf(arquivo, "number_of_reservations: %d\n", nr);
    fprintf(arquivo, "total_spent: %.3f\n", t);

    fclose(arquivo);
}


void to_txt_1_f(int i, char* airline, char* plane, char* origem, char* destino, char* sdd, char* sad, int p, char* delay) {
    
    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- 1 ---\n");
    fprintf(arquivo, "airline: %s\n", airline);
    fprintf(arquivo, "plane_model: %s\n", plane);
    fprintf(arquivo, "origin: %s\n", origem);
    fprintf(arquivo, "destination: %s\n", destino);
    fprintf(arquivo, "schedule_departure_date: %s\n", sdd);
    fprintf(arquivo, "schedule_arrival_date: %s\n", sad);
    fprintf(arquivo, "passengers: %d\n", p);
    fprintf(arquivo, "delay: %s\n", delay);

    fclose(arquivo);
}

void to_txt_1_r(int i, char* hotel_i, char* hotel_n, char* stars, char* bd, char* ed, char* ib, int n, double t) {

    FILE *arquivo;
    char file[40]; // Ajuste o tamanho conforme necessário

    // Cria o nome do arquivo com o número i
    snprintf(file, sizeof(file), "Resultados/command%d_output.txt", i);

    arquivo = fopen(file, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo comando.txt");
        return;
    }

    fprintf(arquivo, "--- 1 ---\n");
    fprintf(arquivo, "hotel_id: %s\n", hotel_i);
    fprintf(arquivo, "hotel_name: %s\n", hotel_n);
    fprintf(arquivo, "hotel_stars: %s\n", stars);
    fprintf(arquivo, "begin_date: %s\n", bd);
    fprintf(arquivo, "end_date: %s\n", ed);
    fprintf(arquivo, "includes_breakfast: %s\n", ib);
    fprintf(arquivo, "nights: %d\n", n);
    fprintf(arquivo, "total_price: %.3f\n", t);

    fclose(arquivo);
}