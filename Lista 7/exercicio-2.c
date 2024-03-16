/*Ajustar o módulo de saída do cliente, calculando e exibindo o valor
a pagar, lendo o valor pago e calculando o troco. Vocês podem fazer uma proposta
de cálculo de valor a pagar considerando horas completas e minutos extras (inferior
a 1 hora)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declaração de variáveis globais
char Estaciona[30][14]; // Matriz para armazenar informações sobre as vagas do estacionamento
float Valor; // Valor do estacionamento por hora de uso
char Responsavel[21], Iniciou = 0; // Responsável pelo estacionamento e flag indicando se o caixa foi aberto

// Função para abrir o caixa do estacionamento
void AbrirCaixa() {
  
    system("cls"); 
    system("color 80");
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>>  Largas Vagas  <<< \n");
    printf("\n     ABRINDO  CAIXA \n");
  
    // Inicializa todas as vagas como "LIVRE"
    for (int i = 0; i < 30; i++)
        strcpy(Estaciona[i], "LIVRE");
  
    // Solicita ao usuário o valor do estacionamento por hora e o nome do responsável
    printf("\nQual o valor do estacionamento por hora de uso? ");
    scanf("%f", &Valor);
    fflush(stdin); // Limpa o buffer do teclado
    printf("Qual o nome do responsavel? ");
    scanf("%20s", Responsavel);
    Iniciou = 1; // Define a flag de caixa aberto como verdadeira
}
// Função para registrar a chegada de um cliente ao estacionamento
void ClienteChega() {
    int Vaga;
    char Placa[8], Hora[6], Entrada[14];
    system("cls");
    system("color 80"); 
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

            // Solicita e verifica o formato do horário de entrada
            do {
                printf("Qual a hora de entrada [formato hh:mm]? ");
                scanf("%5s", Hora);
                fflush(stdin); // Limpa o buffer do teclado

                // Verifica se o formato do horário está correto
                if (strlen(Hora) == 5 && Hora[2] == ':' && isdigit(Hora[0]) && isdigit(Hora[1]) && isdigit(Hora[3]) && isdigit(Hora[4])) {
                    break;
                } else {
                    printf("Formato de hora inválido. Por favor, insira novamente.\n");
                }
            } while (1);

            // Registra a chegada do cliente na vaga especificada
            strcpy(Entrada, Placa);
            strcat(Entrada, "+");
            strcat(Entrada, Hora);
            strcpy(Estaciona[Vaga - 1], Entrada);

            printf("Chegada registrada com sucesso!\n");
        } else {
            printf("Essa vaga já está ocupada. Por favor, escolha outra vaga.\n");
        }
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}

// Função para registrar a saída de um cliente do estacionamento
void ClienteSai() {
    int Vaga;
    char Entrada[14], Hora[3], Min[3];
    int H, M, HoraSaida, MinSaida; // Variáveis para armazenar hora, minuto
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
        // Solicita ao usuário o número da vaga ocupada
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);

        // Verifica se a vaga está ocupada
        if (strcmp(Estaciona[Vaga - 1], "LIVRE") != 0) {
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

            // Exibe o horário de entrada do cliente
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

            // Exibe o total a pagar ao cliente
            printf("\nTotal a pagar: %.2f\n", TotalPagar);

            // Solicita ao cliente o valor pago e calcula o troco
            printf("Qual o valor pago? ");
            scanf("%f", &Pago);
            Troco = Pago - TotalPagar;
            printf("\nTroco: %.2f\n", Troco);

            // Limpar os dados da vaga
            strcpy(Estaciona[Vaga - 1], "LIVRE"); // Define a vaga como livre novamente
        } else {
            printf("Essa vaga está livre. Não há nenhum veículo estacionado aqui.\n");
        }
    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause"); // Pausa a execução até que o usuário pressione uma tecla (apenas para Windows)
}

// Função para fechar o caixa do estacionamento
void FecharCaixa() {

}

// Função principal
int main() {
    int Op;
    do {
        // Exibe o menu de opções
        system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
        system("color 70"); // Define a cor do texto e do fundo do console (apenas para Windows)
        printf("\n >>> Estacionamento <<< \n");
        printf(" >>>  Largas Vagas  <<< \n");
        printf("\n 1 - Abrir Caixa");
        printf("\n 2 - Chegada de Cliente");
        printf("\n 3 - Saida de Cliente");
        printf("\n 4 - Fechar Caixa");
        printf("\n\n Qual a opcao desejada? ");
        // Solicita ao usuário a escolha da opção do menu
        do {
            scanf("%d", &Op);
            if ((Op < 1) || (Op > 4)) {
                printf("\n ERRO: Opcao invalida!");
                printf("\n Qual a opcao desejada? ");
            } else {
                break;
            }
        } while (1);
        // Executa a ação correspondente à opção escolhida
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
    } while (Op != 4); // Repete o loop até que a opção escolhida seja 4 (Fechar Caixa)

    return 0;
}