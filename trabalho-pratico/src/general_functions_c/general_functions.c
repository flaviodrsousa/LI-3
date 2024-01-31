#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_users.h"
#include "../include/catalogs_h/catalog_reservations.h"
#include "../include/catalogs_h/catalog_flights.h"
#include "../include/catalogs_h/catalog_passengers.h"

//Verifica se uma data está no formato correto
int check_date(char* date) {
    if(strlen(date) == 0) return 1;
    int yn; int mn; int dn;
    sscanf(date, "%d/%d/%d", &yn, &mn, &dn);

    if(yn > 1900 && mn < 13 && mn > 0 && dn < 32 && dn > 0) {
        return 0;
    } else { 
        return 1;
    }
}


//Verifica se uma data com horas está no formato correto
int check_date_time(char* date) {
    if(strlen(date) == 0) return 1;

    int yn; int mn; int dn; int hn; int minn; int sn;
    sscanf(date, "%d/%d/%d %d:%d:%d", &yn, &mn, &dn, &hn, &minn, &sn);

    if(yn > 1900  && mn < 13 && mn > 0 && dn < 32 && dn > 0 && hn >= 0 && hn < 24 &&  minn < 60 && minn >= 0 && sn < 60 && sn >= 0) {
        return 0;
    } else { 
        return 1;
    }
}


//compara 2 datas 
int compare_date(char* date1, char* date2) {
    if(strlen(date1) == 0 || strlen(date2) == 0) return 1;
    
    int yn1; int mn1;  int dn1;
    sscanf(date1, "%d/%d/%d", &yn1, &mn1, &dn1);

    int yn2; int mn2; int dn2;
    sscanf(date2, "%d/%d/%d", &yn2, &mn2, &dn2);

    if(yn1 == yn2 && mn1 == mn2 && dn1 == dn2) {
        return 2;
    }

    if(yn1 > yn2) {
        return 1;
    }

    if(yn1 < yn2) {
        return 0;
    }

    if(mn1 < mn2) {
        return 0;
    }

    if(mn1 > mn2) {
        return 1;
    }

    if(dn1 < dn2) {
        return 0;

    } else {
        return 1;
    }
    //Devolve 0 se a primeira data foi antes da segunda e 1 se a segunda foi antes
    //20-02-2023
    //19/03-2024
}

int compare_year(char* date1, char* date2) {
    
    int yn1; int mn1;  int dn1;
    sscanf(date1, "%d/%d/%d", &yn1, &mn1, &dn1);

    int yn2; int mn2; int dn2;
    sscanf(date2, "%d/%d/%d", &yn2, &mn2, &dn2);

    if(yn1 == yn2) {
        return 1;
    }

}

//compara 2 datas 
int compare_date_time(char* date1, char* date2) {

    int yn1, mn1, dn1, hn1, minn1, sn1;
    sscanf(date1, "%d/%d/%d %d:%d:%d", &yn1, &mn1, &dn1, &hn1, &minn1, &sn1);

     int yn2, mn2, dn2, hn2, minn2, sn2;
    sscanf(date2, "%d/%d/%d %d:%d:%d", &yn2, &mn2, &dn2, &hn2, &minn2, &sn2);
    //Devolve 0 se a primeira data foi antes da segunda e 1 se a segunda foi antes

    if(yn1 < yn2) {
        return 0;
    } else {
        if(yn1 == yn2 && mn1 < mn2) {
            return 0;
        } else {
            if(yn1 == yn2 && mn1 == mn2 && dn1 < dn2) {
                return 0;
            } else {
                if(yn1 == yn2 && mn1 == mn2 && dn1 == dn2 && hn1 < hn2) {
                    return 0;
                } else {
                    if(yn1 == yn2 && mn1 == mn2 && dn1 == dn2 && hn1 == hn2 && minn1 < minn2) {
                        return 0;
                    } else {
                        if(yn1 == yn2 && mn1 == mn2 && dn1 == dn2 && hn1 == hn2 && mn1 == mn2 && sn1 < sn2) {
                            return 0;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}

int timeDifference(char* date1, char* date2){
    int yn1, mn1, dn1, hn1, minn1, sn1;
    sscanf(date1, "%d/%d/%d %d:%d:%d", &yn1, &mn1, &dn1, &hn1, &minn1, &sn1);

    int yn2, mn2, dn2, hn2, minn2, sn2;
    sscanf(date2, "%d/%d/%d %d:%d:%d", &yn2, &mn2, &dn2, &hn2, &minn2, &sn2);

    int sec1 = hn1 * 3600 + minn1 * 60 + sn1;
    int sec2 = hn2 * 3600 + minn2 * 60 + sn2;

    if(sec1 > sec2){
        sec2 += 24 * 3600;
    }

    return sec2 - sec1;
}

int atraso(char* date1, char* date2) {
    int a = timeDifference(date1, date2);
    return a;
}

char* removeChar(char *input, char remover) {

    char *original, *copia;
    for (original = copia = input; *original != '\0'; original++) {
        *copia = *original;
        if (*copia != remover) copia++;
    }
    *copia = '\0';
    return original;

}

// Função que liberta os nodes da HashTable individualmente

void free_key_value(gpointer data) {
    g_free(data);
}

//Função para libertar os tokens
void freeTokens(char** tokens, int max) {
    for(int i = 0; i < max; i++) {
        free(tokens[i]);
    }
}