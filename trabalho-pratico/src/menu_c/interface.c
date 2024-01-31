#include "../include/menu_h/interface.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    void interface () {
 printf("\n");
            printf("                               ._\n");
        printf("                              |* ;\n");
        printf("            `*-.              |\"\":\n");
        printf("             \\  \\             |\"\" \n");
        printf("              .  \\            |   :\n");
        printf("              `   \\           |\n");
        printf("               \\   \\          |    ;               +.\n");
        printf("                .   \\         |                   *._`-.\n");
        printf("                `    \\        |     :          .-*'  `. `.\n");
        printf("                _\\    \\.__..--**--...L_   _.-*'      .'`*'\n");
        printf("               /  `*-._\\   -.       .-*\"*+._       .'\n");
        printf("              :        ``*-._*.     \\      _J.   .'\n");
        printf("          .-*'`*-.       ;     `.    \\    /   `.'\n");
        printf("      .-*'  _.-*'.     .-'       `-.  `-.:   _.'`-.\n");
        printf("   +*' _.-*'      `..-'             `*-. `**'      `-\n");
        printf("    `*'          .-'      ._            `*-._         `.\n");
        printf("              .-'         `.`-.____..+-**\"\"'         .*\"`.\n");
        printf("         ._.-'          _.-*'':$$$;._$              /     `.\n");
        printf("      .-'  `.      _.-*' `*-.__T$P   `\"**--..__    :        `.\n");
        printf(".'..-'       \\_.-*'                            `\"**--..___.-*'\n");
        printf("`. `.    _.-*'\n");
        printf("  `. `:*'\n");
        printf("    `. `.\n");
        printf("      `*\n");
        printf("----------------------------------------------------------------------\n");
        printf("                               Welcome                    \n");
        printf("----------------------------------------------------------------------\n");
        printf("                                                        \n");
        printf("                      Press c key to continue!               \n");
        printf("                      Press e key to to exit!                \n");
        printf("                                                        \n");
        printf("----------------------------------------------------------------------\n");
    }


    void queries () {
        printf("\n                             ");
        printf("\n What queries do you want to run?");
        printf("\n                             ");
        printf("\n 1  | Listar o resumo de um utilizador, voo, ou reserva, consoante o identificador recebido por argumento");
        printf("\n 2  | Listar os voos ou reservas de um utilizador");
        printf("\n 3  | presentar a classificação média de um hotel, a partir do seu identificador");
        printf("\n 4  | Listar as reservas de um hotel, ordenadas por data de início ");
        printf("\n 5  | Listar os voos com origem num dado aeroporto, entre duas datas, ordenados por data de partida estimada");
        printf("\n 6  | Listar o top N aeroportos com mais passageiros, para um dado ano");
        printf("\n 7  | Listar o top N aeroportos com a maior mediana de atrasos");
        printf("\n 8  | Apresentar a receita total de um hotel entre duas datas (inclusive), a partir do seu identificador.");
        printf("\n 9  | Listar todos os utilizadores cujo nome começa com o prefixo passado por argumento, ordenados por nome (de forma crescente)");
        printf("\n 10 | Apresentar várias métricas gerais da aplicação");
        printf("\n 0  | Back\n");
        printf("\n");
    }                      
   
    void pageBar(){
    printf("---------------------------------------------------------------------------------------------\n");
    printf("                        [n] Next Page | [p] Previous Page | [q] Quit        \n");
    printf("---------------------------------------------------------------------------------------------\n");
   }

    void pageN(int i){
    printf("---------------------------------------------------------------------------------------------\n");
    printf("                                         Page %d       \n",i);
    printf("---------------------------------------------------------------------------------------------\n");
   }

   void sentence1(){
    printf("\n-----------------------------------------");
    printf("\n  Do you want to select a different dataset?");
    printf("\n-----------------------------------------");
    printf("\n         [Y] Yes      [N] No");
    printf("\n-----------------------------------------\n");
   }

   void sentence2(){
    printf("\n-----------------------------------------------");
    printf("\n  Please enter the arguments for your query");
    printf("\n  Please separate them with a space");
    printf("\n-----------------------------------------------\n");
   }