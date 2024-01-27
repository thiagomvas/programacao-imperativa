/*
 * Ler notas de alunos e identificar se cada foi aprovado.
Considerar como sistema de avaliação: em princípio, 3
notas; são aprovados os alunos com média 7; para os
alunos com média acima de 3, é possibilitado fazer 4a
avaliação, então a média passa a ser 5 para obtenção da
aprovação. Após a identificação de que um aluno foi
aprovado, ou não; deve ser questionado se o usuário (do
programa) deseja verificar a situação de outro aluno.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float media(float array[], int length) {
    if (length == 0) {
        printf("Array nao pode ser vazia\n");
        return 0.0; // You can choose to handle the error differently
    }

    float sum = 0.0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    return sum / length;
}

void avaliarAluno()
{

    float nota1, nota2, nota3, nota4;
    float notas[4];
    printf("Insira a primeira nota: ");
    scanf("%f", &nota1);
    printf("Insira a segunda nota: ");
    scanf("%f", &nota2);
    printf("Insira a terceira nota: ");
    scanf("%f", &nota3);

    notas[0] = nota1;
    notas[1] = nota2;
    notas[2] = nota3;

    float med = media(notas, 3);
    if(med >= 7)
        printf("APROVADO");
    else if(med > 3)
    {
        printf("Aluno esta com media %.2f e tem direito a quarta prova. Insira a quarta nota: ", med);
        scanf("%f", &nota4);
        notas[3] = nota4;
        med = media(notas, 4);
        if(med > 5)
            printf("APROVADO\n");
        else
            printf("REPROVADO\n");
    }
    else
        printf("REPROVADO\n");


    char escolha;
    printf("\nGostaria de avaliar outro aluno? (S / N)");
    scanf(" %c", &escolha);
    if(toupper(escolha) == 'S')
        avaliarAluno();
    else return;
}


void main()
{
    avaliarAluno();
}