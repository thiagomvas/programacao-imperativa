#include <stdio.h>
#include <math.h>
#include <ctype.h>

int unidade(int num)
{
    return num % 10000 % 1000 % 100 % 10;
}

int dezena(int num)
{
    return num % 10000 % 1000 % 100 / 10;
}

int centena(int num)
{
    return num % 10000 % 1000 / 100;
}

int milhar(int num)
{
    return num % 10000 / 1000;
}

int dezenaMilhar(int num)
{
    return num / 10000;
}

int main() {
    int num;
    char escolha;
    printf("Escolha um numero de 0 a 99999\n");
    scanf("%d", &num);
    
    if(num < 0 || num > 99999)
    {
        printf("Numero invalido.");;
    }
    else
    {
        printf("ESCOLHA UMA DAS OPÇÕES\nU - Unidade\nD - Dezena\nC - Centena\nM - Unidade de Milhar\nZ - Dezena de Milhar\n");
        scanf(" %c", &escolha);
    
        switch(escolha)
        {
            case 'U':
                printf("%d", unidade(num));
                break;
            case 'D':
                printf("%d", dezena(num));
                break;
            case 'C':
                printf("%d", centena(num));
                break;
            case 'M':
                printf("%d", milhar(num));
                break;
            case 'Z':
                printf("%d", dezenaMilhar(num));
                break;
            default:
                printf("ESCOLHA INVALIDA");
                break;
        }
    }
    
    
}
