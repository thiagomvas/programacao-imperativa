// JK faz vaquinha para proteção animal

#include <stdio.h>

int main(){
    float Meta, Doacao, Soma = 0;
    printf("Meta da vaquinha: ");
    scanf("%f",&Meta);
    do{
        printf("Valor da doacao: ");
        scanf("%f",&Doacao);
        Soma = Soma + Doacao;
        printf("Total arrecadado ate o momento: %.2f\n", Soma);
    }
    while (Soma<Meta);
    printf("A meta da vaquinha foi alcancada!\n");
    printf("Ultrapassamos o valor em %.2f reais!", Soma - Meta);
    return 0;
}