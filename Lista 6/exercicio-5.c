#include <stdio.h>

#define TOTAL_ALUNOS 100
#define ANO_GERONTOLOGIA 99

int contarAlunosGerontologiaNoAno(int matriculas[TOTAL_ALUNOS], int ano, int curso);

int main() {
    int matriculas[TOTAL_ALUNOS];
    int ano, quantidadeAlunos;

    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &matriculas[i]);
    }

    printf("Digite o ano desejado para contar os alunos de gerontologia: ");
    scanf("%d", &ano);
    
    quantidadeAlunos = contarAlunosGerontologiaNoAno(matriculas, ano, ANO_GERONTOLOGIA);
    
    printf("Quantidade de alunos de Gerontologia no ano %d: %d\n", ano, quantidadeAlunos);

    return 0;
}

int contarAlunosGerontologiaNoAno(int matriculas[TOTAL_ALUNOS], int ano, int curso) {
    int contador = 0;

    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        int anoMatricula = matriculas[i] / 1000000; //  Obter ano
        int cursoMatricula = (matriculas[i] / 10000) % 100; // Obter curso

        if (anoMatricula == ano && cursoMatricula == curso) {
            contador++;
        }
    }

    return contador;
}
