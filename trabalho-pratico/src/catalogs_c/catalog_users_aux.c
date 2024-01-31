#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//verfificar email
int check_email(char* email) {

    const char* at = strchr(email, '@'); // Procura a primeira ocorrência de '@'

    if (at == NULL || at == email) {
        return 1; // Não encontrou '@' ou está no início da string
    }

    const char* dot = strchr(at, '.'); // Procura a primeira ocorrência de '.' após o '@'

    if (dot == NULL || dot == at + 1 || dot[1] == '\0') {
        return 1; // Não encontrou '.' ou está imediatamente após o '@' ou é o último caractere
    }

    char *e1, *e2, *e3;

    e1 = strtok(email, "@");
    e2 = strtok(NULL, ".");
    e3 = strtok(NULL, "");

    if(strlen(e1) > 0 && strlen(e2) > 0 && strlen(e3) > 1) {
        return 0;
    } else {
        return 1;
    }
    
}


//verificar atividade
int check_status(char* active) {
    if(strncasecmp(active, "active", 6) == 0 || strncasecmp(active, "inactive", 8) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int check_is_active(char* active) {
    if(strncasecmp(active, "active", 6) == 0) {
        return 1;
    } else {
        return 1;
    }
}

//verifica country code
int check_country_code(char *cc) {
    if(strlen(cc) == 2) {
        return 0;
    } else {
    return 1;
    }
}


//verifica campo nulo
int check_null_camp_urs(char* tokens[]) {
    
    for (int j = 0; j < 12; j++) {
        if(strlen(tokens[j]) == 0) {
            return 1;
        }
    }
    return 0;
}

int calculate_age(char* date) {

    int anoNascimento, mesNascimento, diaNascimento;
    sscanf(date, "%d/%d/%d", &anoNascimento, &mesNascimento, &diaNascimento);

    int idade = 2023 - anoNascimento;

    if (mesNascimento > 10 || (10 == mesNascimento && diaNascimento > 1)) {
        idade--;
    }

    return idade;
}


//cria ficheiro se n existir e escreve uma linha nele
void write_user_error(char *linha) {
    FILE *arquivo = fopen("Resultados/users_errors.csv", "a"); // Abre o arquivo em modo "append" para acrescentar ao final

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo user_erros.csv.\n");
        return;
    }

    fprintf(arquivo, "%s", linha); // Escreve a linha no arquivo
    fclose(arquivo); // Fecha o arquivo
}