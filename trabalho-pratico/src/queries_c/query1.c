#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users_aux.h"
#include "../include/catalogs_h/catalog_reservations_aux.h"
#include "../include/catalogs_h/catalog_flights_aux.h"
#include "../include/catalogs_h/catalog_passengers_aux.h"
#include "../include/general_functions_h/general_functions.h"
#include "../include/interpreter_h/interpreter.h"
#include "../include/structs_h/struct_flights.h"
#include "../include/structs_h/struct_reservations.h"
#include "../include/structs_h/struct_users.h"

void query1 (GHashTable* reservations, GHashTable* flights, GHashTable* users, char *input, int i, int type, int l){
    char linha[100];
    if (strncmp(input, "0000", 4) == 0) {
        Voo*x = (Voo*)(g_hash_table_lookup(flights, input));
 
        if(x == NULL && l == 0) {
            to_txt_0(i, "");

        if(x == NULL && l == 1){
            printf("Voo Inexistente");
        }

        } else {
        char* company = getCompanhia(g_hash_table_lookup(flights, input));
        char* plane = getAviao(g_hash_table_lookup(flights, input));
        char* origin = getOrigem(g_hash_table_lookup(flights, input));
        char* destiny = getDestino(g_hash_table_lookup(flights, input));
        char* departure = getPartidaEstimada(g_hash_table_lookup(flights, input));
        char* arrival = getChegadaEstimada(g_hash_table_lookup(flights, input));
        int numberPassengers = calculate_numeroPassageiros(flights, input);
        char* delay = getAtraso(g_hash_table_lookup(flights, input));

        if(type == 0 && l == 0) {
            snprintf(linha, sizeof(linha), "%s;%s;%s;%s;%s;%s;%d;%s\n", company, plane, origin, destiny, departure, arrival, numberPassengers, delay);
            to_txt_0(i, linha);
        } else if (type == 1 && l == 0){
            to_txt_1_f(i, company, plane, origin, destiny, departure, arrival, numberPassengers, delay);
        } else if (type == 0 && l == 1){
            printf("Voo: %s;%s;%s;%s;%s;%s;%d;%s\n", company, plane, origin, destiny, departure, arrival, numberPassengers, delay );
        }
        
        free(company);
        free(plane);
        free(origin);
        free(destiny);
        free(departure);
        free(arrival);
        free(delay);
    
        }

    } else if (strncmp(input, "Book", 4) == 0){
            Reserva*x = (Reserva*)(g_hash_table_lookup(reservations, input));
 
        if(x == NULL) {
            to_txt_0(i, "");

        } else {
            char* fim = getDataFim(g_hash_table_lookup(reservations,input));
            char* inicial = getDataInicial(g_hash_table_lookup(reservations, input));

        char* idHotel = getIdHotel(g_hash_table_lookup(reservations, input));
        char* nomeHotel = getNomeHotel(g_hash_table_lookup(reservations, input));
        char* estrelas_hotel = getEstrelasHotel(g_hash_table_lookup(reservations, input));
        char* data_inicio = getDataInicial(g_hash_table_lookup(reservations, input));
        char* data_fim = getDataFim(g_hash_table_lookup(reservations, input));
        char* pequeno_almoço = getPequenoAlmoco(g_hash_table_lookup(reservations, input));
        int numero_noites = calculate_n_noites(inicial, fim);
        double preco_Total = getPrecoTotal(g_hash_table_lookup(reservations, input));

        free(fim);
        free(inicial);

        if(type == 0 && l == 0) {
            snprintf(linha, sizeof(linha), "%s;%s;%s;%s;%s;%s;%d;%.3f\n", idHotel, nomeHotel,estrelas_hotel,data_inicio,data_fim,pequeno_almoço,numero_noites,preco_Total);
            to_txt_0(i, linha);
        } else if (type == 1 && l == 0){
            to_txt_1_r(i, idHotel, nomeHotel, estrelas_hotel, data_inicio, data_fim, pequeno_almoço, numero_noites, preco_Total);
        } else if (type == 0 && l == 1){
                printf("Reserva: %s;%s;%s;%s;%s;%s;%d;%.3f\n", idHotel, nomeHotel,estrelas_hotel,data_inicio,data_fim,pequeno_almoço,numero_noites,preco_Total);
            }


        free(idHotel);
        free(nomeHotel);
        free(estrelas_hotel);
        free(data_inicio);
        free(data_fim);
        free(pequeno_almoço);
    }
    
    
    } else {
        Utilizador*x = (Utilizador*)(g_hash_table_lookup(users, input));
        if(x == NULL || getStatus(x) == 0) {
            to_txt_0(i, "");

        } else {
        
            char* nome = getNome(g_hash_table_lookup(users, input));
            char* sexo = getSexo(g_hash_table_lookup(users, input));
            int idade = getIdade(g_hash_table_lookup(users, input));
            char* codigo_pais = getCodigoPais(g_hash_table_lookup(users, input));
            char* passaporte = getPassport(g_hash_table_lookup(users, input));
            int numero_voos = calculate_numeroVoos(users, input);
            int numero_reservas = calculate_numeroReservas(reservations, input);
            double total_gasto = calculate_totalGasto (reservations, input);
        
            
            if(type == 0 && l == 0) {
                snprintf(linha, sizeof(linha), "%s;%s;%d;%s;%s;%d;%d;%.3f\n", nome, sexo, idade, codigo_pais, passaporte, numero_voos, numero_reservas, total_gasto);
                to_txt_0(i, linha);
            } else if (type == 1 && l == 0){
                to_txt_1_u(i, nome, sexo, idade, codigo_pais, passaporte, numero_voos, numero_reservas, total_gasto);
            } else if (type == 0 && l == 1){
                printf("User: %s;%s;%d;%s;%s;%d;%d;%.3f\n", nome, sexo, idade, codigo_pais, passaporte, numero_voos, numero_reservas, total_gasto);
            }

            free(nome);
            free(sexo);
            free(codigo_pais);
            free(passaporte);
            }
        
        }
    }
