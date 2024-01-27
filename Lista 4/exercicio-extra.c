
#include <stdio.h>

void diffQuadrados(int n)
{
    int a = 1, b = 1;
    int resultado = a * a - b * b;
    while(resultado != n)
    {
        resultado = a * a - b * b;
        if(resultado < n)
        {
            a += 1;
            continue;
        }
        else if(resultado > n)
        {
            b += 1;
            continue;
        }
    }
    printf("%d - %d = %d", a*a, b*b, n);
}

int pedirNumero()
{
    int n;
    printf("Escolha um numero: ");
    scanf("%d", &n);
    if(n % 2 == 1 && 1 <= n && n <= 10000)
        return n;
    else
    {
        printf("NUMERO INVALIDO, DEVE SER IMPAR E INCLUSIVAMENTE ENTRE 1 E 10000\n");
        return pedirNumero();
    }

}

void main()
{
    int n = pedirNumero();
    diffQuadrados(n);


}
