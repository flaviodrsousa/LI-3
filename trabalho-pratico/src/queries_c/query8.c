#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalog_reservations_aux.h"
#include "../include/queries_h/query1_output.h"
#include "../include/queries_h/query8_output.h"
#include "../include/structs_h/struct_reservations.h"
#include "../include/general_functions_h/general_functions.h"

void query8 (GHashTable* reservation, char *id, char *begin, char *end, int numbe, int type, int l){
    GHashTableIter iter;
    gpointer key, value;
    int revenueTotal=0;
    char linha[100];

    g_hash_table_iter_init (&iter, reservation);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        char* idhotel = getIdHotel(value);

        if(strcmp(id,idhotel)==0){
            char* dataf = getDataFim(value);
            char* datai = getDataInicial(value);
            if(compare_date(datai, begin) == 1 && compare_date(end, datai) == 1 && compare_date(end,dataf) == 1 && compare_date(dataf, begin) == 1){
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n1\nbegin: %s\ndatai: %s\ndataf: %s\nend: %s",begin,datai,dataf,end);
                char* n = getPrecoNoite(value);
                int numRealNoites = calculate_n_noites(datai,dataf);
                int pn = atoi(n);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if (compare_date(dataf,end) == 1 && compare_date(end, datai) == 1 && compare_date(datai, begin) == 1){
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n2\nbegin: %s\ndatai: %s\ndataf: %s\nend: %s\n%d\n%d\n%d",begin,datai,dataf,end,compare_date(dataf,end),compare_date(end, datai), compare_date(datai, begin));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(datai,end);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if (compare_date(dataf, begin) == 1 && compare_date(begin,datai) ==1 && compare_date(end, dataf) == 1){
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n3\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(begin,dataf);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else  if(compare_date(datai, begin) == 2 && compare_date(dataf, end) == 2) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n4\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(datai,dataf);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if(compare_date(datai, begin)==2 && compare_date(dataf, end) == 1) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n5\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(datai,end);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if(compare_date(datai, begin) == 2 && compare_date(end, dataf) == 1) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n6\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(datai,dataf);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if(compare_date(datai, begin) == 1 && compare_date(dataf, end) == 2) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n7\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(datai,dataf);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if(compare_date(begin, datai) == 1 && compare_date(end, dataf) == 2) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n8\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(begin,dataf);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else if(compare_date(begin,datai) == 1 && compare_date(dataf,end) == 1) {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\n9\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));
                char* n = getPrecoNoite(value);
                int pn = atoi(n);
                int numRealNoites = calculate_n_noites(begin, end);
                revenueTotal += pn*numRealNoites;
                free(n);
            } else {
                //if(strcmp(begin, "2023/05/02") ==  0 && strcmp(end, "2023/05/02") == 0)
                //printf("\nErro");
                //printf("\n10\nbegin: %s\ndatai: %s\nvalor: %d\ndataf: %s\nend: %s\nvalor: %d\n",begin,datai,!compare_date(begin,datai),dataf,end,compare_date(dataf, end));

            }
            free(dataf);
            free(datai);
        }
            free(idhotel);
     
        //Devolve 0 se a primeira data foi antes da segunda e 1 se a segunda foi antes
        // 2003  2005 = 0
        // 2005 2003 = 1

        

        }
        snprintf(linha, sizeof(linha),"%d\n",revenueTotal);
        if(type == 0) {
            to_txt_0(numbe, linha);
        } else {
            to_txt_8F(numbe, linha);
        }
}
