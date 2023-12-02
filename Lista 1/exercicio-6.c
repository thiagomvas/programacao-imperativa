#include <stdio.h>
#include <stdlib.h>

void main() {
    int numero;
    printf("Qual numero deseja saber a tabuada?\n");
    scanf("%d", &numero);
    printf("Tabuada:\n");
    for(int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", numero, i, numero * i);
    }
}
