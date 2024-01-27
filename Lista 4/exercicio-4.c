#include <stdio.h>

int mesesAux(int dias, int sum)
{
    if(dias < 30)
        return sum;
    else return mesesAux(dias - 30, sum + 1);
}

int meses(int dias)
{
    return mesesAux(dias, 0);
}

void main()
{
    int dias;
    printf("Quantidade de dias: ");
    scanf("%d", &dias);
    printf("%d dias formam %d meses completos", dias, meses(dias));
}