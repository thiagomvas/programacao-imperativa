/*Ajustar o módulo de entrada do cliente de forma a atualizar o
array auxiliar citado na questão anterior.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14]; 
float Valor; 
char Responsavel[21], Iniciou = 0; 
int QuantidadePorHora[15] = {0}; 

void AbrirCaixa() {
    system("cls"); 
    system("color 80"); 
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n     ABRINDO  CAIXA \n");

    // Inicializa todas as vagas como livres
    for (int i = 0; i < 30; i++)
        strcpy(Estaciona[i], "LIVRE");

    printf("\nQual o valor do estacionamento por hora de uso? ");
    scanf("%f", &Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    scanf("%20s", Responsavel);

    Iniciou = 1;
}

void ClienteChega() {
    int Vaga;
    char Placa[8], Hora[6], Entrada[14];
    int hora, minuto; 
    system("cls"); 
    system("color 80"); 
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n   CHEGADA DE CLIENTE \n");
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin); // Limpa o buffer do teclado

        if (strcmp(Estaciona[Vaga - 1], "LIVRE") == 0) {
            printf("Qual a placa do veiculo [7 digitos]? ");
            scanf("%s", Placa);
            fflush(stdin); // Limpa o buffer do teclado
            printf("Qual a hora de entrada [formato hh:mm]? ");
            scanf("%s", Hora);

            // Extrai a hora e o minuto da entrada
            sscanf(Hora, "%d:%d", &hora, &minuto);

            if (hora >= 6 && hora < 20) {
                strcpy(Entrada, Placa);
                strcat(Entrada, "+");
                strcat(Entrada, Hora);
                strcpy(Estaciona[Vaga - 1], Entrada);

                QuantidadePorHora[hora - 6]++;

                printf("Chegada registrada com sucesso!\n");
            } else {
                printf("O estacionamento está fechado neste horário.\n");
            }
        } else {
            printf("Essa vaga já está ocupada. Por favor, escolha outra vaga.\n");
        }
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); 
}

void ClienteSai() {
    int Vaga;
    char Entrada[14], Hora[6];
    int horaEntrada, minutoEntrada, horaSaida, minutoSaida; // Variáveis para armazenar a hora e o minuto
    float TotalPagar, Pago, Troco;
    system("cls"); 
    system("color 80"); 
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n    SAIDA DE CLIENTE \n");

    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);

        // Verifica se a vaga está ocupada
        if (strcmp(Estaciona[Vaga - 1], "LIVRE") != 0) {
            strcpy(Entrada, Estaciona[Vaga - 1]);

            sscanf(Entrada + 8, "%d:%d", &horaEntrada, &minutoEntrada);

            printf("\nHorario de entrada: %d:%d\n", horaEntrada, minutoEntrada);

            printf("Qual o horario de saida [formato hh:mm]? ");
            scanf("%d:%d", &horaSaida, &minutoSaida);

            if (horaSaida >= 6 && horaSaida < 20) {
                int tempoEstacionado = (horaSaida - horaEntrada) * 60 + (minutoSaida - minutoEntrada);

                int horasCompletas = tempoEstacionado / 60;
                int minutosExtras = tempoEstacionado % 60;

                TotalPagar = Valor * horasCompletas;
                if (minutosExtras > 0) {
                    TotalPagar += Valor; // Adiciona uma hora extra se houver minutos extras
                }

                printf("\nTotal a pagar: %.2f\n", TotalPagar);

                printf("Qual o valor pago? ");
                scanf("%f", &Pago);
                Troco = Pago - TotalPagar;
                printf("\nTroco: %.2f\n", Troco);

                // Limpar os dados da vaga
                strcpy(Estaciona[Vaga - 1], "LIVRE"); // Define a vaga como livre novamente
            } else {
                printf("O estacionamento está fechado neste horário.\n");
            }
        } else {
            printf("Essa vaga está livre. Não há nenhum veículo estacionado aqui.\n");
        }
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); 
}


void FecharCaixa() {
    int carrosNoEstacionamento = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(Estaciona[i], "LIVRE") != 0) {
            carrosNoEstacionamento++;
        }
    }

    if (carrosNoEstacionamento > 0) {
        printf("\nALERTA: Ainda há carros estacionados no estacionamento!\n");
        printf("Por favor, verifique antes de fechar o caixa.\n");
    } else {
        printf("\n >>> Relatorio <<<\n");
        printf("Quantidade de carros por hora:\n");
        int maxEntradas = 0;
        int horaMaisCheia = 6;
        for (int i = 0; i < 15; i++) {
            printf("Hora %d: %d carros\n", i + 6, QuantidadePorHora[i]);
            if (QuantidadePorHora[i] > maxEntradas) {
                maxEntradas = QuantidadePorHora[i];
                horaMaisCheia = i + 6;
            }
        }
        printf("Horário com mais entradas: %d\n", horaMaisCheia);
    }
}

int main() {
    int Op;
    do {
        system("cls"); 
        system("color 70"); 
        printf("\n >>> Estacionamento <<< \n");
        printf(" >>>  Largas Vagas  <<< \n");
        printf("\n 1 - Abrir Caixa");
        printf("\n 2 - Chegada de Cliente");
        printf("\n 3 - Saida de Cliente");
        printf("\n 4 - Fechar Caixa");
        printf("\n\n Qual a opcao desejada? ");
        do {
            scanf("%d", &Op);
            if ((Op < 1) || (Op > 4)) {
                printf("\n ERRO: Opcao invalida!");
                printf("\n Qual a opcao desejada? ");
            } else {
                break;
            }
        } while (1);
        switch (Op) {
            case 1:
                AbrirCaixa();
                break;
            case 2:
                ClienteChega();
                break;
            case 3:
                ClienteSai();
                break;
            case 4:
                FecharCaixa();
                break;
        }
    } while (Op != 4);

    return 0;
}
