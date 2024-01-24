/*
 * 8.Escrever um programa em C para ler um valor V em reais, taxa de
câmbio fixa de dólar e taxa de câmbio fixa de euro e exibir em tela os
correspondentes a V em dólar e em euro. Para tanto, criar função F em que
dados valor e taxa de câmbio, retorna o valor convertido. Criar módulo com
aplicação de F, parâmetros de entrada e dois parâmetros de saída: valor em
dólar e valor em euro.
 */

#include <stdio.h>

void calcularCambio(float valor, float cambioDolar, float cambioEuro, float *dolar, float *euro)
{
    *dolar = valor / cambioDolar;
    *euro = valor / cambioEuro;
}

void main()
{
    float cambioDolar, cambioEuro, valor, dolar, euro;
    printf("Quantos reais voce tem?\n");
    scanf("%f", &valor);
    printf("Qual o valor do cambio do dolar para real? Isto e, quantos reais valem 1 dolar americano?\n");
    scanf("%f", &cambioDolar);
    printf("Qual o valor do cambio do euro para real? Isto e, quantos reais valem 1 euro?\n");
    scanf("%f", &cambioEuro);

    calcularCambio(valor, cambioDolar, cambioEuro, &dolar, &euro);

    printf("Valor em real: %0.2f BRL\n"
           "Valor em dolar: %0.2f USD\n"
           "Valor em euro: %0.2f EUR\n",
           valor, dolar, euro);
}
