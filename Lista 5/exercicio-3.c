// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define TARIFA 22

float montante(int passagens)
{
    return passagens * TARIFA;
}

float mediaPassagens(int passagens, int cargaHoraria)
{
    return (float) passagens / (float) cargaHoraria;
}

int main() {
    int horas, numPassageiros, maisPassageiros, melhorHorario, menosPassageiros, piorHorario, totalPassageiros;
    maisPassageiros = 0;
    totalPassageiros = 0;
    menosPassageiros = INT_MAX ;
    
    int inicioTurno = 8;
    int finalTurno = 18;
    
    for(horas = inicioTurno; horas <= finalTurno; horas++)
    {
        printf("Numero de passageiras do %d horas: ", horas);
        scanf("%d", &numPassageiros);
        totalPassageiros += numPassageiros;
        if(numPassageiros > maisPassageiros)
        {
            melhorHorario = horas;
            maisPassageiros = numPassageiros;
        }
        if(numPassageiros < menosPassageiros)
        {
            piorHorario = horas;
            menosPassageiros = numPassageiros;
        }
    }
        
        printf("Horario de maior procura: %d.\n", melhorHorario);
        printf("Horario de menor procura: %d.\n", piorHorario);
        printf("Montante: %.2f\n", montante(totalPassageiros));
        printf("Media de passagens: %.2f\n", mediaPassagens(totalPassageiros, finalTurno - inicioTurno));
}
