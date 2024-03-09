// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <limits.h>

int fatorial(int n)
{
        
    int total = 1;
    for(int i = 1; i <= n; i++)
    {
        total *= i;
    }
    return total;
}

int main() {
    int n = 0;
    printf("Escolha um N: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    printf("%d! = %d\n",i, fatorial(i));
}
