#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOME_COMPLETO 100

void exibirNomeSobrenome(char nomeCompleto[MAX_NOME_COMPLETO]) {
    char nome[MAX_NOME_COMPLETO];
    char sobrenome[MAX_NOME_COMPLETO];

    sscanf(nomeCompleto, "%s %[^\n]", nome, sobrenome);

    for (int i = 0; sobrenome[i] != '\0'; i++) {
        sobrenome[i] = toupper(sobrenome[i]);
    }

    printf("Nome formatado: %s, %s\n", sobrenome, nome);
}

int main() {
    char nomeCompleto[MAX_NOME_COMPLETO];
    char continuar = 'S';

    while (toupper(continuar) == 'S')
    {
        printf("Digite o nome completo (nome sobrenome): ");
        fgets(nomeCompleto, sizeof(nomeCompleto), stdin);

        nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

        exibirNomeSobrenome(nomeCompleto);

        printf("Deseja verificar outro nome? (S/N): ");
        scanf(" %c", &continuar); 

        while (getchar() != '\n');

    } 

    return 0;
}

