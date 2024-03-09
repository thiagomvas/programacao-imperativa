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
    
    int meses = numMeses(pesoAtual, pesoMeta);
    printf("Atingirá sua meta em %d meses: \n", meses);
    for(int i = 1; i <= meses; i++)
        printf("Mes %d - Peso: %.2f\n", i, pesoAtual - 5 * i);
}
