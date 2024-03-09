#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOME 50

void formatarNome(char nome[MAX_NOME]) 
{
    nome[0] = toupper(nome[0]);

    for (int i = 1; nome[i] != '\0'; i++) 
    {
        if (nome[i - 1] == ' ') // Não entendi se queria dizer apenas a primeira letra do nome como um todo ou se era a primeira letra de cada sobrenome
            nome[i] = toupper(nome[i]);
        else 
            nome[i] = tolower(nome[i]);
        
    }
}

int main() 
{
    char nome[MAX_NOME];

    printf("Digite um nome: ");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    formatarNome(nome);

    printf("Nome formatado: %s\n", nome);

    return 0;
}
