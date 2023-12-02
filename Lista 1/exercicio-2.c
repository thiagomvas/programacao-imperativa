#include <stdio.h>
#include <stdlib.h>

void main() {
    float pesoAtual, pesoIdeal, perdaMensal;
    printf("Qual seu peso atual em kg (quilogramas)?\n");
    scanf("%f",&pesoAtual);
    printf("Qual o seu peso ideal em kg(quilogramas)?\n");
    scanf("%f", &pesoIdeal);
    printf("Quantos quilos você perde ao mês?");
    scanf("%f", &perdaMensal);
    printf("Você vai chegar ao seu peso ideal em %.0f dias", abs(pesoAtual - pesoIdeal)/(perdaMensal/30));
}
