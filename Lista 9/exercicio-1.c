/*Escrever programa em C para ler nome, 3 notas e
frequência (em percetual) dos 80 alunos do projeto
AprendaProgramação, calcular a média destes (média da
turma) e emitir em tela a situação final de cada aluno.

São aprovados todos os que ficam com média (aritmética
simples) acima da média da turma e têm frequência acima
de 65%.

Deve ser exibido o nome de cada aluno, seguido das
notas, média e da situação final: APROVADO ou
REPROVADO. */

#include <stdio.h>

int main() {
    int num_alunos = 80;

    typedef struct {
        char nome[50];
        float notas[3];
        float frequencia;
    } Aluno;

    Aluno alunos[num_alunos];
    float mediaTurma = 0;

    for (int i = 0; i < num_alunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite as 3 notas do aluno %d separadas por espaços: ", i + 1);
        scanf("%f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]);

        printf("Digite a frequência do aluno %d (em percentual): ", i + 1);
        scanf("%f", &alunos[i].frequencia);

        // Calcula a média do aluno
        float somaNotas = alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2];
        float mediaAluno = somaNotas / 3;

        // Adiciona a média do aluno à média da turma
        mediaTurma += mediaAluno;
    }

    mediaTurma /= num_alunos;

    printf("====================================");
    printf("\nMedia da turma: %f\n\n", mediaTurma);
    // Verifica a situação final do aluno
    for (int i = 0; i < num_alunos; i++) {
        float mediaAluno = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
        if (mediaAluno > mediaTurma && alunos[i].frequencia > 65) {
            printf("%s - Notas: %.2f %.2f %.2f - Média: %.2f - APROVADO\n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], mediaAluno);
        } else {
            printf("%s - Notas: %.2f %.2f %.2f - Média: %.2f - REPROVADO\n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], mediaAluno);
        }
    }
    


    return 0;
}
