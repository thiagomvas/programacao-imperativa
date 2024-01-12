/*
 * Escrever um programa em C para ler peso em kg e altura em m. Calcular
e exibir o IMC da pessoa considerando IMC = peso / altura². Para cálculo
de IMC usar função, e nessa aplicar função de cálculo da potência (seja
definida pelo programação ou nativa).
 */

#include <math.h>
#include <stdio.h>

float imc(float peso, float alturaMetro)
{
    return peso / powf(alturaMetro, 2);
}

void main()
{
    float peso, altura;
    printf("Qual sua altura em metro?\n");
    scanf("%f", &altura);
    printf("Qual seu peso em KG?\n");
    scanf("%f", &peso);
    printf("Seu IMC eh %.2f", imc(peso, altura));
}