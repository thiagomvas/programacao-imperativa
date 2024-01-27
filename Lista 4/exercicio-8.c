#include <stdio.h>

void escadaN(int n)
{
    if(n < 1 || n > 40)
    {
        printf("NUMERO FORA DO ALCANCE, DEVE ESTAR INCLUSIVAMENTE ENTRE 1 E 40");
        return;
    }
    printf("\n\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void main()
{
    int n;
    printf("Escolha um numero inclusivamente entre 1 e 40: ");
    scanf("%d", &n);
    escadaN(n);
}