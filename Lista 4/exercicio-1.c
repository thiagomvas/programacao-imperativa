#include <stdio.h>
void ValidaCompra(float *L){
    float D;
    printf("Debito: ");
    scanf("%f",&D);
    if (*L - D >= 0){
        printf("Compra possivel! \n");
        *L = *L - D;}
    else
        printf("Compra \"estourarah\" o cartao! \n");
    printf("Limite restante: %.2f \n\n",*L);}
int main(){
    float Limite;
    int id = 1;
    printf("Limite do cartao: ");
    scanf("%f",&Limite);
    while (Limite>0)
    {
        printf("Compra #%d - ", id);
        ValidaCompra(&Limite);

        id++;

    }
    printf("Seu limite de compras acabou!");
    return 0;}