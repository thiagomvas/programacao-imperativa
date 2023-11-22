#include <stdio.h>
#include <stdlib.h>

void main() {
    int anoDose1, intervalo;
    printf("Em que ano foi tomada a primeira dose? \n");
    scanf("%d", &anoDose1);
    printf("Qual o intervalo de anos entre cada dose?\n");
    scanf("%d", &intervalo);
    printf("1° Dose: %d\n2° Dose: %d\n3° Dose: %d\n4° Dose: %d", anoDose1, anoDose1 + intervalo, anoDose1 + intervalo * 2, anoDose1 + intervalo * 3);
}
