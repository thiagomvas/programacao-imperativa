// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

#define JUROS 110

float total(float valor, int meses)
{
    return valor + meses * JUROS;
}

float parcela(float valor, int meses)
{
    return total(valor, meses) / meses;
}


int main() {
    float compra;
    printf("Valor da compra: ");
    scanf("%f", &compra);
    
    for(int i = 1; i <= 10; i++)
    {
        printf("Pagamento em %d meses - Juros: R$ %d - Total: %.2f - Parcela %d vezes R$ %.2f\n", i, JUROS, total(compra, i), i, parcela(compra, i));
    }
}
