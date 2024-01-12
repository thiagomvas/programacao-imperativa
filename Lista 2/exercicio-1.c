/*
 * Há pessoas que precisam fazer tratamento de saúde contínuo (em
comprimidos), a exemplo de reposição hormonal. Sabendo que uma
pessoa deve fazer uso de X comprimidos ao mês e que em cada caixa
desse há N unidades (comprimidos); escrever um programa em C
onde se lê X e N e é exibido o número de caixas a serem adquiridas.
 */

#include <math.h>
#include <stdio.h>

int NumCaixas(int comprimidosPorMes, int comprimidosPorCaixa)
{
    if(comprimidosPorMes <= 0) return 0;
    if(comprimidosPorCaixa <= 0) {
        printf("ERRO: Quantia de comprimidos por caixa deve ser maior que 0\n");
        return -1;
    }
    int caixas = ceil((float) comprimidosPorMes / comprimidosPorCaixa);
    return caixas;
}

void main()
{
    int comprimidosMes, comprimidosCaixa;
    printf("Quantos comprimidos deve-se tomar no mês?\n");
    scanf("%d", &comprimidosMes);
    printf("Quantos comprimidos tem em uma caixa?\n");
    scanf("%d", &comprimidosCaixa);
    int caixas = NumCaixas(comprimidosMes, comprimidosCaixa);
    printf("Será necessária comprar %d caixas", caixas);
}
