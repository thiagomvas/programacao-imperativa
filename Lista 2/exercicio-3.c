/*
 * Escrever programa em C para ler um
número N e retornar N³(N ao cubo),
aplicando função (que calcula cubo).
 */

#include <stdio.h>
double cubo(double n)
{
    return n * n * n;
}

void main()
{
    double n;
    printf("Escolha um numero\n");
    scanf("%lf", &n);
    printf("%lf ao cubo é %lf", n, cubo(n));
}