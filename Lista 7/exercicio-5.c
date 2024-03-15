/*No relatório emitido a partir do FecharCaixa exibir o horário
com maior número de entradas e a soma dos valores recebidos ao longo do dia.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14]; // Array para armazenar informações sobre as vagas de estacionamento
//Mantem placa com 7 caracteres, sinal de + e 5 caracteres para hora

float Valor; // Valor do estacionamento por hora
char Responsavel[21], Iniciou = 0; // Responsável pelo caixa e indicador se o caixa foi aberto
int QuantidadePorHora[15] = {0}; 
float TotalLucro = 0;

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
void ClienteChega() {
    int Vaga;
    char Placa[8], Hora[5], Entrada[14];
    system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
    system("color 80"); // Define a cor do texto e do fundo do console (apenas para Windows)
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n   CHEGADA DE CLIENTE \n");

    // Verifica se o caixa está aberto
    if (Iniciou) {
        printf("\n CAIXA ABERTO   Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);

        // Solicita ao usuário a vaga ocupada e os detalhes do veículo
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin);
        printf("Qual a placa do veiculo [7 digitos]? ");
        scanf("%s", Placa);
        strcpy(Entrada, Placa);
        fflush(stdin);
        printf("Qual a hora de entrada [formato nn:nn]? ");
        scanf("%s", Hora);
        strcat(Entrada, "+");
        strcat(Entrada, Hora);
        strcpy(Estaciona[Vaga - 1], Entrada);

        // Atualiza o quantitativo de carros para a hora de entrada
        int hora = atoi(Hora);
        if (hora >= 6 && hora <= 20) {
            QuantidadePorHora[hora - 6]++;
        }

        printf("Chegada registrada com sucesso!\n");
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}

// Função para registrar a saída de um cliente do estacionamento
void ClienteSai() {
    int Vaga;
    char Placa[8], Entrada[14], Hora[3], Min[3];
    int H, M, HoraSaida, MinSaida; // Variáveis para armazenar hora, minuto e segundo
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

        // Obtém os dados de entrada do cliente na vaga especificada
        strcpy(Entrada, Estaciona[Vaga - 1]);

        // Extrai a hora e o minuto da entrada
        Hora[0] = Entrada[8];
        Hora[1] = Entrada[9];
        Hora[2] = '\0';
        H = atoi(Hora);
        Min[0] = Entrada[11];
        Min[1] = Entrada[12];
        Min[2] = '\0';
        M = atoi(Min);

        printf("\nHorario de entrada: %d:%d\n", H, M);

        // Solicita ao usuário o horário de saída
        printf("Qual o horario de saida [formato nn:nn]? ");
        scanf("%d:%d", &HoraSaida, &MinSaida);

        // Calcula o tempo em minutos que o cliente permaneceu no estacionamento
        int TempoEstacionado = (HoraSaida - H) * 60 + (MinSaida - M);

        // Calcula o número de horas completas e os minutos extras
        int HorasCompletas = TempoEstacionado / 60;
        int MinutosExtras = TempoEstacionado % 60;

        // Calcula o valor total a pagar, considerando horas completas e minutos extras
        TotalPagar = Valor * HorasCompletas;
        if (MinutosExtras > 0) {
            TotalPagar += Valor; // Adiciona uma hora extra se houver minutos extras
        }

        printf("\nTotal a pagar: %.2f\n", TotalPagar);

        // Solicita ao cliente o valor pago e calcula o troco
        printf("Qual o valor pago? ");
        scanf("%f", &Pago);
        Troco = Pago - TotalPagar;
        printf("\nTroco: %.2f\n", Troco);
        
        // Adicionar o total a pagar ao lucro total do dia
        TotalLucro += TotalPagar;
        
        // Limpar os dados da vaga
        strcpy(Estaciona[Vaga - 1], "LIVRE"); // Define a vaga como livre novamente

    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}

// Função para fechar o caixa do estacionamento e gerar um relatório
void FecharCaixa() {
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
    printf("Total de lucro: %d\n", TotalLucro);
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