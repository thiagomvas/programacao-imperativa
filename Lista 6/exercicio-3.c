#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PALAVRA 20

int contarVogais(char palavra[MAX_PALAVRA]) {
    int vogais = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        char caractere = tolower(palavra[i]);

        switch(caractere)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vogais++;
                break;
        }
    }

    return vogais;
}

int main() {
    char palavra[MAX_PALAVRA];
    char continuar = 'S';

    while(toupper(continuar) == 'S')
    {
        printf("Digite uma palavra com até 20 caracteres: ");
        scanf("%s", palavra);

        int quantidadeVogais = contarVogais(palavra);

        printf("A palavra '%s' possui %d vogais.\n", palavra, quantidadeVogais);

        printf("Deseja contar as vogais de outra palavra? (S/N): ");
        scanf(" %c", &continuar);
    }

    return 0;
}

