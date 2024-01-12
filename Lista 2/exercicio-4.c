/*
 * Escrever um programa em C para ler uma temperatura em Celsius C e
a retornar em Fahrenheit e em Kelvin. Fórmulas de conversão para
Fahrenheit: F = (C * 9/5) + 32; para Kelvin: K = C + 273,5.
Criar uma função para cada conversão.
 */
#include <stdio.h>

float cParaF(float c)
{
    return c * 9/5 + 32;
}

float cParaK(float c)
{
    return c + 273.15; // Na verdade, a conversão para kelvin é C + 273,15 (Fonte: Google)
}

void main()
{
    float temperatura;
    printf("Quantos graus sera necessario converter?\n");
    scanf("%f", &temperatura);;
    printf("Temperatura em Graus Celsius: %f"
           "\nTemperatura em Graus Fahrenheit: %f"
           "\nTemperatura em Graus Kelvin: %f\n",
           temperatura, cParaF(temperatura), cParaK(temperatura));
}