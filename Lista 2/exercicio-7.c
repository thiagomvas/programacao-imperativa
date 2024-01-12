/*
 * 7.Escrever um programa em C sobre investimento. Deve ser efetuada a
leitura do valor inicial investido, do valor investido mensalmente e do tempo
de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado
um módulo(função) com dois parâmetros de saída.
 */
#include <stdio.h>

void calcularInvestimento(double valorInicial, double valorMensal, int tempo, double *valorFinal, double *rendimento)
{
    *valorFinal = valorInicial + valorMensal * tempo;
    *rendimento = *valorFinal - valorInicial;
}


void main()
{
    double valorInicial, valorMensal, valorFinal, rendimento;
    int tempo;

    printf("Quanto foi investido inicialmente?\n");
    scanf("%lf", &valorInicial);

    printf("Quanto vai ser investido mensalmente?\n");
    scanf("%lf", &valorMensal);

    printf("Quantos meses passara investindo?\n");
    scanf("%d", &tempo);

    calcularInvestimento(valorInicial, valorMensal, tempo, &valorFinal, &rendimento);

    printf("Valor final investido: %.2lf\n"
           "Rendimento: %0.2lf",
           valorFinal, rendimento);
}