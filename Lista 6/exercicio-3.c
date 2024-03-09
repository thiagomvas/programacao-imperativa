#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PALAVRA 20

int contarVogais(char palavra[MAX_PALAVRA]) {
    int totalvogais = 0;

    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'á', 'é', 'í', 'ó', 'ú', 'â', 'ê', 'î', 'ô', 'û', 'ã', 'õ', 'Â', 'Ê', 'Î', 'Ô', 'Û', 'Ã', 'Õ', 'Á', 'É', 'Í', 'Ó', 'Ú'};

    for (int i = 0; palavra[i] != '\0'; i++) {
        char caractere = tolower(palavra[i]);
    
        for (int j = 0; j < sizeof(vogais) / sizeof(vogais[0]); j++) {
            if (caractere == vogais[j]) {
                totalvogais++;
                break;
            }
        }
    }

    return totalvogais;
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
