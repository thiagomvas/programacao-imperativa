// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int main() {
    int numAlunos = 50;
    float media = 7;
    int minimoAcimaDaMedia = 5;
    
    for(int i = 1; i <= numAlunos; i++)
    {
        printf("AVALIAÇÕES DO ALUNO #%d\n", i);
        int acimaDaMedia = 0;
        for(int j = 1; j < 12; j++)
        {
            float nota;
            printf("Nota da #%d avaliação: ", j);
            scanf("%f", &nota);
            while(nota < 0)
            {
                printf("NOTA INVALIDA! Insira uma nota maior que 0 para a #%d avaliação: ", j);
                scanf("%f", &nota);
            }
            if(nota >= media)
                acimaDaMedia++;
        }
        printf("Total de notas acima de %.2f: %d\n", media, acimaDaMedia);
        if(acimaDaMedia >= minimoAcimaDaMedia)
            printf("APROVADO");
        else
            printf("REPROVADO");
            
        printf("\n========================================\n");
    }
}
