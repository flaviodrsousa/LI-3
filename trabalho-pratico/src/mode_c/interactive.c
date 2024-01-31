#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <sys/resource.h>
#include "../include/general_functions_h/general_functions.h"
#include "../include/parser_h/parser.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/interpreter_h/interpreter.h"
#include "../include/menu_h/interface.h"
#include "../include/structs_h/struct_users.h"

void interactive (Catalogs* catalog_s){
    char query[100];
    char args[100]; 
    char combined[1024];

    //printf("\n%s\n", getNome((Utilizador*)g_hash_table_lookup(get_users_hash(get_user_catalog(catalog_s)), "JéssiTavares910")));

    queries();
    scanf("%s", query);

    if(atoi(query) == 0){
        return;
    }

    sentence2();
    scanf(" %[^\n]%*c", args);
    
    strcpy(combined, query);
    strcat(combined, " ");
    strcat(combined, args);

    //printf("\nQuery: %s", query);
    //printf("\nArguments: %s\n", args);
    //printf("\nCombined: %s\n", combined);
    
    char *tokens[6];
    char *token = strtok(combined, " \t\n");

    int i = 0;
    while (token != NULL && i < 6) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }

   /* printf("Tokens:\n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", tokens[j]);
    } */

    interpreter(tokens, 0,0,catalog_s,1);

}