#include "../include/menu_h/menu.h"
#include "../include/menu_h/interface.h"
#include "../include/mode_h/batch.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/mode_h/interactive.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

void menu() {
    Catalogs *catalog_s = dataset();
    char *init;

    do {
        system("clear");
        interface();
        init = scan();

        if (strcmp(init, "c") == 0) {
            interactive(catalog_s);
        } else if (strcmp(init, "e") == 0) {
            system("clear");
            break;
        } else {
            printf("\nInvalid key!\n");
            invalidKey();
        }

        printf("\nDo you want to select another query? (y/n): ");
        char response[2];
        scanf("%1s", response);

        if (response[0] != 'y') {
            break;
        }

    } while (1);

    printf("Exiting the program. Goodbye!\n");
}

void invalidKey () {
    char init;
    scanf("%s", &init);
    switch(init) {
        case 'c': {interactive(NULL); init = 0; break;}

        case 'e': return;

        default: {printf ("\nInvalid key!\n"); invalidKey ();}
    } 
}

Catalogs* dataset() {
    system("clear");
    sentence1();
    char* d;
    char* path;
    Catalogs* catalog_s = NULL;

    do {
        d = scan();

        if (strcmp(d, "n") == 0) {
            catalog_s = create_catalogs("../../data_small/data/");
            break;
        } else if (strcmp(d, "y") == 0) {
            printf("Introduza o caminho desejado.\n");
            path = scan();
            catalog_s = create_catalogs(path);
            break;
        } else {
            printf("\nInvalid key!\n");

        }
    } while (1);

    free(d);
    return catalog_s;
}

char* scan() {
    char* s = malloc(256);

    if (s == NULL) {
        
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    scanf("%255s", s);

    return s;
}