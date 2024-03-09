// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

float parcela(float valor, int meses)
{
    return (valor + meses * 100) / meses;
}

float total(float valor, int meses)
{
    return valor + meses * 100;
}

int main() {
    float compra;
    printf("Valor da compra: ");
    scanf("%f", &compra);
    
    for(int i = 1; i <= 10; i++)
    {
        printf("Pagamento em %d meses - Juros: R$100 - Total: %.2f - Parcela %d vezes R$ %.2f\n", i, total(compra, i), parcela(compra, i));
    }
}
