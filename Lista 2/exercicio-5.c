/*
 * Escrever um programa em C para ler o raio de um círculo e exibir em
tela a área desse (círculo) usando a fórmula: Área = π * raio². Usar um
módulo/função para cálculo da área, outro módulo/função para cálculo do
quadrado. E usar uma constante para definição de π. Recomenda-se o
uso de função e/ou constante nativa, se houver.
 */

#include <math.h>
#include <stdio.h>
double quadrado(double n)
{
    return n * n;
}

double areaCirculo(double r)
{
    return M_PI * quadrado(r);
}

void main()
{
    double raio;
    printf("Qual o raio do circulo?\n");
    scanf("%lf", &raio);
    printf("O circulo de raio %lf tem area %lf", raio, areaCirculo(raio));
}