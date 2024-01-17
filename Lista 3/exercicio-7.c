/*
* Escrever programa para: (a) exibir menu: 1 –
area, 2 – perímetro e 3 – diagonal; (d) ler
medida de lado de um quadrado; (c) exibir
a informação solicitada pelo usuário
conforme opção de menu selecionada.
Deve haver mensagem de erro para o caso do
usuário selecionar opção não existente.
Deve ser modularizado.
*/

#include <stdio.h>
#include <math.h>

float area(float lado)
{
    return lado * lado;
}

float perimetro(float lado)
{
    return 4 * lado;
}

float diagonal(float lado)
{
    return sqrt(lado * lado * 2);
}

int main() {
    
    float lado;
    printf("Qual o lado do quadrado?\n");
    scanf("%f", &lado);
    
    
    int escolha;
    printf("\n\nESCOLHA UMA DAS OPÇÕES\n"
    "1 - Área\n"
    "2 - Perimetro\n"
    "3 - Diagonal\n");
    scanf("%d", &escolha);
    
    float resultado;
    
    switch(escolha)
    {
        case 1:
            resultado = area(lado);
            printf("Area: %f", resultado);
            break;
        case 2: 
            resultado = perimetro(lado);
            printf("Perimetro: %f", resultado);
            break;
        case 3:
            resultado = diagonal(lado);
            printf("Diagonal: %f", resultado);
            break;
        default:
            printf("OPÇÃO INVALIDA");
    }
}
