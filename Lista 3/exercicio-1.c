/*
* Os colegas do filho de Sr. Zé estão sentindo dificuldade para
alugar um ônibus para levá-los ao “Museu da Gente
Sergipana”. Então Sr. Zé resolveu disponibilizar sua Kombi,
mas a depender do número de inscritos, serão necessárias
muitas viagens, e alguns passageiros deverão ir de coletivo.
Considerando que a Kombi tem capacidade para transportar 11
pessoas (fora o motorista – Sr. Zé), escrever um programa em
C, para, dado o número de inscritos no passeio ao Museu,
exibir o número de viagens que devem ser necessárias e o
número de passagens de coletivo. Exemplos: se 22 pessoas –
2 viagens de kombi e 0 passagem em coletivo; se 37 pessoas
– 3 viagens e 4 passagens em coletivo. Vale esclarecer que se
o número de passageiros for inferior a 11, Sr. Zé os levará de
Kombi.
*/
#include <stdio.h>
#include <math.h>

int main() {
    int passagens;
    printf("Quantas pessoas vão para o museu?\n");
    scanf("%d", &passagens);
    if(passagens < 11)
        printf("Sr. Ze levara todo mundo em uma viagem so");
    else if(passagens % 11 == 0)
        printf("Sera necessario fazer %d viagens de kombi, e nenhuma passagem no coletivo", passagens / 11);
    else 
        printf("Sera necessaria fazer %d viagens de kombi e %d passagens em coletivo", passagens / 11, passagens % 11);
}
