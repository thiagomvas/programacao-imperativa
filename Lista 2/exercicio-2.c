/*
 * No pré-escolar “Balão Mágico” o número máximo de alunos de uma
turma é definido anualmente, após as reformas de fim de ano e
evolução curricular. Escrever programa em C onde se lê o número
total de alunos matriculados, o número máximo de alunos por
turma e exibir o número de turmas a serem formadas.
 */

#include <math.h>
#include <stdio.h>

int totalTurmas(int totalAlunos, int alunosPorTurma)
{
    if(totalAlunos <= 0) return 0;
    if(alunosPorTurma <= 0) {
        printf("ERRO: Quantia de alunos por turma deve ser maior que 0\n");
        return -1;
    }
    int caixas = ceil((float) totalAlunos / alunosPorTurma);
    return caixas;
}

void main()
{

    int alunos, capacidade;
    printf("Quantos alunos no total?\n");
    scanf("%d", &alunos);
    printf("Quantos alunos por turma?\n");
    scanf("%d", &capacidade);
    int turmas = totalTurmas(alunos, capacidade);
    printf("Existira %d turmas nesse ano", turmas);
}

