#include "../include/mode_h/batch.h"
#include "../include/catalogs_h/catalogs.h"
#include "../include/menu_h/menu.h"
#include "../include/menu_h/interface.h"
#include <stdio.h>

int start_program(int argc, char** argv) {

    if (argc <= 2/*Para iterativo, <1 */) {
        menu();
      }
    else {
        printf("\n\n      --- A INICIAR PROGRAMA ---\n");
        printf("\n\n --- A criar catálogos ---\n");
        Catalogs* catalog_s = create_catalogs(argv[1]);
        printf(" --- A iniciar Respostas ---\n");
        batch(catalog_s, argv[2]);
        printf(" --- Respostas concluídas ---\n\n");
        printf(" --- A libertar endereços dos arquivos .csv ---\n\n");
        free_catalogs(catalog_s);
        printf("\n      ---TERMINADO---\n\n\n");}

return 0;
}
    