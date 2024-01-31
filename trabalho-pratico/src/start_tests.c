#include <stdlib.h>
#include <string.h>
#include "../include/mode_h/batch_tests.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/menu_h/menu.h"
#include "../include/menu_h/interface.h"
#include <stdio.h>


int compare_outputs(char* result_file, char *expected_file){
        FILE *result, *expected;

        result = fopen(result_file,"r");
        expected = fopen(expected_file,"r");

        if (result == NULL || expected == NULL) {
                if (result == NULL && expected == NULL) {
                        perror("Erro ao abrir ambos os ficheiros");
                } else if (result == NULL) {
                        perror("Erro ao abrir o ficheiro result");
                } else {
                        perror("Erro ao abrir o ficheiro expected");
                }

                if (result != NULL) fclose(result);
                if (expected != NULL) fclose(expected);

         return -1;
        }

        char line1[1024];
        char line2[1024]; 

        int errorLine = 0;
        int i = 0;

        while (fgets(line1, sizeof(line1), result) != NULL && fgets(line2, sizeof(line2), expected) != NULL) {
        i++;
        if (strcmp(line1, line2) != 0) {    
            errorLine = i;
            break;
        }
        
    }

    fclose(result);
    fclose(expected);

    return errorLine;
}

void execTest(char * path, double elapsed, int command){
        char result[1024];
        char expected[1024];

        snprintf(result, sizeof(result), "../../grupo-35/trabalho-pratico/Resultados/command%d_output.txt", command);
        snprintf(expected, sizeof(expected), "%s/command%d_output.txt", path, command);

        int errorLine = compare_outputs(result,expected);

        if (errorLine == 0) {
                printf("Command %d - Passed the test in %.8f seconds!\n", command, elapsed);
    } else {
        printf("Command %d - Did not pass the test because of an error in line %d\n", command, errorLine);
    }
}

int start_program_tests(int argc, char** argv) {

        Catalogs* catalog_s = create_catalogs(argv[1]);

        batch_tests(catalog_s, argv[2], NULL, argv[3]);

        free_catalogs(catalog_s);

return 0;

}