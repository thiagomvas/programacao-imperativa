#include <stdio.h>
#include <stdlib.h>

void main() {
    float reais, cambio;
    printf("Quantos reais deseja converter?\n");
    scanf("%f", &reais);
    printf("Qual a taxa de cambio do real-dolar?\n");
    scanf("%f", &cambio);
    printf("No final, terá US$ %.2f", reais * cambio);
}
