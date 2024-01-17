#include <stdio.h>
/*
* Escrever programa para ler as três notas de
um aluno, calcular a média deste (média
ponderada: primeira nota com peso 1,
segunda nota com peso 2 e terceira nota com
peso 3) e determinar a situação do aluno:
APROVADO – se média igual ou superior a 7;
EM RECUPERAÇÃO – se não aprovado e com
média igual ou superior a 5; REPROVADO –
quando média inferior a 5.
*/

float mediaPonderada(int* notas)
{
    float sum = 0;
    for(int i = 0; i < 3; i++)
    {
        sum += notas[i] * (i + 1);
    }
    return sum / 6;
}

int main() {
    int notas[3];
    int length = sizeof(notas) / sizeof(notas[0]);
    for(int i = 1; i < length + 1; i++)
    {
        printf("Qual sua %d° nota?\n", i);
        scanf("%d", &notas[i - 1]);
    }
    
    float media = mediaPonderada(notas);
    if(media >= 7)
        printf("APROVADO");
    else if(media >= 5)
        printf("EM RECUPERAÇÃO");
    else
        printf("REPROVADO");
    
    printf("\nMedia ponderada: %f ", mediaPonderada(notas));
    
}
