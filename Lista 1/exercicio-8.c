#include <stdio.h>

void main()
{
    float comprimento, largura;
    printf("Qual o comprimento do retangulo?");
    scanf("%f", &comprimento);
    printf("Qual a largura do retangulo?");
    scanf("%f", &largura);
    printf("A area do retangulo eh %f", comprimento * largura);
}