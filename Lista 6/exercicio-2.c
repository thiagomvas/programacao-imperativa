#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOME 50

void formatarNome(char nome[MAX_NOME]);

int main() {
    char nome[MAX_NOME];

    printf("Digite um nome: ");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    formatarNome(nome);

    printf("Nome formatado: %s\n", nome);

    return 0;
}

void formatarNome(char nome[MAX_NOME]) {
    nome[0] = toupper(nome[0]);
    for (int i = 1; nome[i] != '\0'; i++) {
        nome[i] = tolower(nome[i]);
    }
}
