/*Ajustar o módulo de entrada do cliente de forma a atualizar o
array auxiliar citado na questão anterior.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição das variáveis globais
char Estaciona[30][14]; // Array para armazenar informações sobre as vagas de estacionamento
float Valor; // Valor do estacionamento por hora
char Responsavel[21], Iniciou = 0; // Responsável pelo caixa e indicador se o caixa foi aberto
int QuantidadePorHora[15] = {0}; // Array auxiliar para armazenar a quantidade de carros por hora

// Função para abrir o caixa do estacionamento
void AbrirCaixa() {
    system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
    system("color 80"); // Define a cor do texto e do fundo do console (apenas para Windows)
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n     ABRINDO  CAIXA \n");

    // Inicializa todas as vagas como livres
    for (int i = 0; i < 30; i++)
        strcpy(Estaciona[i], "LIVRE");

    // Solicita ao usuário o valor do estacionamento por hora e o nome do responsável
    printf("\nQual o valor do estacionamento por hora de uso? ");
    scanf("%f", &Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    scanf("%20s", Responsavel);

    // Indica que o caixa foi aberto
    Iniciou = 1;
}

// Função para registrar a chegada de um cliente ao estacionamento
// Função para registrar a chegada de um cliente ao estacionamento
void ClienteChega() {
    int Vaga;
    char Placa[8], Hora[6], Entrada[14];
    int hora, minuto; // Variáveis para armazenar a hora e o minuto
    system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
    system("color 80"); // Define a cor do texto e do fundo do console (apenas para Windows)
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n   CHEGADA DE CLIENTE \n");
    // Verifica se o caixa está aberto
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        // Solicita ao usuário o número da vaga, a placa do veículo e a hora de entrada
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin); // Limpa o buffer do teclado

        // Verifica se a vaga está livre
        if (strcmp(Estaciona[Vaga - 1], "LIVRE") == 0) {
            printf("Qual a placa do veiculo [7 digitos]? ");
            scanf("%s", Placa);
            fflush(stdin); // Limpa o buffer do teclado
            printf("Qual a hora de entrada [formato hh:mm]? ");
            scanf("%s", Hora);

            // Extrai a hora e o minuto da entrada
            sscanf(Hora, "%d:%d", &hora, &minuto);

            // Verifica se a entrada está dentro do horário de funcionamento
            if (hora >= 6 && hora < 20) {
                // Atualiza o registro de entrada
                strcpy(Entrada, Placa);
                strcat(Entrada, "+");
                strcat(Entrada, Hora);
                strcpy(Estaciona[Vaga - 1], Entrada);

                // Atualiza o quantitativo de carros para a hora de entrada
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
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}

// Função para registrar a saída de um cliente do estacionamento
// Função para registrar a saída de um cliente do estacionamento
void ClienteSai() {
    int Vaga;
    char Entrada[14], Hora[6];
    int horaEntrada, minutoEntrada, horaSaida, minutoSaida; // Variáveis para armazenar a hora e o minuto
    float TotalPagar, Pago, Troco;
    system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
    system("color 80"); // Define a cor do texto e do fundo do console (apenas para Windows)
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n    SAIDA DE CLIENTE \n");

    // Verifica se o caixa está aberto
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);

        // Verifica se a vaga está ocupada
        if (strcmp(Estaciona[Vaga - 1], "LIVRE") != 0) {
            // Obtém os dados de entrada do cliente na vaga especificada
            strcpy(Entrada, Estaciona[Vaga - 1]);

            // Extrai a hora e o minuto da entrada
            sscanf(Entrada + 8, "%d:%d", &horaEntrada, &minutoEntrada);

            printf("\nHorario de entrada: %d:%d\n", horaEntrada, minutoEntrada);

            // Solicita ao usuário o horário de saída
            printf("Qual o horario de saida [formato hh:mm]? ");
            scanf("%d:%d", &horaSaida, &minutoSaida);

            // Verifica se o horário de saída está dentro do horário de funcionamento
            if (horaSaida >= 6 && horaSaida < 20) {
                // Calcula o tempo em minutos que o cliente permaneceu no estacionamento
                int tempoEstacionado = (horaSaida - horaEntrada) * 60 + (minutoSaida - minutoEntrada);

                // Calcula o número de horas completas e os minutos extras
                int horasCompletas = tempoEstacionado / 60;
                int minutosExtras = tempoEstacionado % 60;

                // Calcula o valor total a pagar, considerando horas completas e minutos extras
                TotalPagar = Valor * horasCompletas;
                if (minutosExtras > 0) {
                    TotalPagar += Valor; // Adiciona uma hora extra se houver minutos extras
                }

                printf("\nTotal a pagar: %.2f\n", TotalPagar);

                // Solicita ao cliente o valor pago e calcula o troco
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
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}


// Função para fechar o caixa do estacionamento e gerar um relatório
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

// Função principal
int main() {
    int Op;
    do {
        system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
        system("color 70"); // Define a cor do texto e do fundo do console (apenas para Windows)
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
