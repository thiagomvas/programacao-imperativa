/*
*Faça um programa para verificar se
determinado número inteiro lido N é divisível
por A ou B, mas não simultaneamente pelos
dois valores dados. São A e B, bem como N,
dados pelo usuário. Atendendo a condição
estabelecida, emitir mensagem “ATENDE
CONDIÇÃO”; caso contrário, exibir: “NÃO
ATENDE CONDIÇÃO”.
*/
  
#include <stdio.h>

int main() {
    int N, A, B;
    printf("Escolha um numero N\n");
    scanf("%d", &N);
    printf("Escolha um numero A\n");
    scanf("%d", &A);
    printf("Escolha um numero B\n");
    scanf("%d", &B);
    
    if(N % A == 0 && N % B == 0)
        printf("NÃO ATENDE CONDIÇÃO");
    else if(N % A == 0)
        printf("ATENDE CONDIÇÃO");
    else if(N % B == 0)
        printf("ATENDE CONDIÇÃO");
    else
        printf("NÃO ATENDE CONDIÇÃO");
    
}
