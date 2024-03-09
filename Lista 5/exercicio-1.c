#include <stdio.h>
#include <math.h>

int numMeses(float atual, float meta)
{
    return (int) ceil((atual - meta)/5);
}

int main() {
    float pesoAtual, pesoMeta;
    printf("Qual seu peso atual em kg?\n");
    scanf("%f", &pesoAtual);
    printf("Qual o peso que quer chegar em kg?\n");
    scanf("%f", &pesoMeta);
    
    if(pesoAtual < pesoMeta)
    {
        printf("Você ja esta abaixo do peso desejado!");
        return 0;
    }
    if(pesoAtual == pesoMeta)
    {
        printf("Você ja esta no peso desejado!");
        return 0;
    }
    
    printf("Será atingido o peso desejado em %d meses", numMeses(pesoAtual, pesoMeta));
}
