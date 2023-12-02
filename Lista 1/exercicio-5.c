#include <stdio.h>
#include <stdlib.h>

void main() {
    float distancia, velocidade;
    printf("Qual a distancia em metros que vai percorrer?\n");
    scanf("%f", &distancia);
    printf("Qual sua velocidade media em m/s enquanto corre?\n");
    scanf("%f", &velocidade);
    int tempoSegundos = (distancia / velocidade);
    printf("Tempo de corrida estimado: %dh %dm %ds", tempoSegundos / 3600, (tempoSegundos / 60) % 60, tempoSegundos % 60);
}
