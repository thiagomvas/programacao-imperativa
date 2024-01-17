#include <stdio.h>
/*
* Para conter o crescimento da quantidade de gatos
abandonados na UFS, e seus consequentes prejuízos, surgiu o
projeto "CastraçãoSolidária", a partir do qual 4 veterinários
experientes e 1 recém formado decidiram efetuar capturas e
castrações todos os dias úteis, sendo os animais capturados
divididos igualitariamente entre os veterinários experientes, e
havendo sobras (não sendo possível uma divisão exata), o
restante fica sob a responsabilidade do 5o veterinário – recém
formado. Por exemplo, se capturados 22 gatos, cada
veterinário experiente fica com 5 castrações, e o recém
formado fica com 2. Se capturados 19, os experientes ficam
com 4 e o formado recentemente fica com 3. Escrever
programa em C para ler número de gatos capturados e exibir a
distribuição das castrações entre os veterinários. Vale
esclarecer que se capturados 4 ou menos gatos, as castrações
ficam sob a responsabilidade de todos os veterinários, em
conjunto.
*/

int main() {
    int gatos;
    printf("Quantos gatos serão castrados?\n");
    scanf("%d", &gatos);
    if(gatos <= 4)
        printf("Todos os veterinarios serão responsabilizados por castrar os %d gatos", gatos);
    else if (gatos % 4 == 0)
        printf("Cada veterinario experiente sera responsavel por %d gatos, com o recem-formado não sendo responsavel por nenhum", gatos / 4);
    else
        printf("Cada veterinario experiente sera responsavel por %d gatos, e o recem-formado sera responsavel por %d gatos", gatos / 4, gatos % 4);
}
