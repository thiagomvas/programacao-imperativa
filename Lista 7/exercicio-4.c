/*O estacionamento funciona de 6 às 20 horas. Deve ser mantido
num array auxiliar o quantitativo de carros com entrada em cada horário. No
módulo FecharCaixa, exibir em tela relatório com esses quantitativos. E havendo
carros no estacionamento, exibir alerta ao utilizador.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Variáveis globais
char Estaciona[30][14]; // Matriz para armazenar informações sobre as vagas do estacionamento
float Valor; // Valor do estacionamento por hora de uso
char Responsavel[21], Iniciou = 0; // Responsável pelo estacionamento e flag indicando se o caixa foi aberto
int QuantidadePorHora[15] = {0}; // Array para armazenar a quantidade de carros por hora

// Função para abrir o caixa do estacionamento
void AbrirCaixa() {
    system("cls"); // Limpa a tela do console (apenas para Windows, para Linux use "clear")
    system("color 80"); // Define a cor do texto e do fundo do console (apenas para Windows)
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
        // Solicita ao usuário o número da vaga, a placa do veículo e a hora de entrada
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);
        fflush(stdin); // Limpa o buffer do teclado
        printf("Qual a placa do veiculo [7 digitos]? ");
        scanf("%s", Placa);
        strcpy(Entrada, Placa);
        fflush(stdin); // Limpa o buffer do teclado
        printf("Qual a hora de entrada [formato nn:nn]? ");
        scanf("%s", Hora);
        strcat(Entrada, "+");
        strcat(Entrada, Hora);
        strcpy(Estaciona[Vaga - 1], Entrada);

        // Atualizar o quantitativo de carros para a hora de entrada
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
        // Solicita ao usuário o número da vaga ocupada
        printf("Qual a vaga ocupada? ");
        scanf("%d", &Vaga);

        strcpy(Entrada, Estaciona[Vaga - 1]);

        Hora[0] = Entrada[8];
        Hora[1] = Entrada[9];
        Hora[2] = '\0';
        H = atoi(Hora);
        Min[0] = Entrada[11];
        Min[1] = Entrada[12];
        Min[2] = '\0';
        M = atoi(Min);

        printf("\nHorario de entrada: %d:%d\n", H, M);

        printf("Qual o horario de saida [formato nn:nn]? ");
        scanf("%d:%d", &HoraSaida, &MinSaida);

        int TempoEstacionado = (HoraSaida - H) * 60 + (MinSaida - M);

        int HorasCompletas = TempoEstacionado / 60;
        int MinutosExtras = TempoEstacionado % 60;

        TotalPagar = Valor * HorasCompletas;
        if (MinutosExtras > 0) {
            TotalPagar += Valor; // Adiciona uma hora extra se houver minutos extras
        }

        printf("\nTotal a pagar: %.2f\n", TotalPagar);

        printf("Qual o valor pago? ");
        scanf("%f", &Pago);

        Troco = Pago - TotalPagar;

        printf("\nTroco: %.2f\n", Troco);

        // Limpar os dados da vaga
        strcpy(Estaciona[Vaga - 1], "LIVRE");

    } else {
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");
    }
    system("pause");
}


// Função para fechar o caixa do estacionamento
void FecharCaixa() {
    printf("\n >>> Relatorio <<<\n");
    printf("Quantidade de carros por hora:\n");
    for (int i = 0; i < 15; i++) {
        printf("Hora %d: %d carros\n", i + 6, QuantidadePorHora[i]);
    }

    // Verificar se há carros no estacionamento
    int totalCarros = 0;
    for (int i = 0; i < 30; i++) {
        if (strcmp(Estaciona[i], "LIVRE") != 0) {
            totalCarros++;
        }
    }

    if (totalCarros > 0) {
        printf("\nALERTA: Ainda existem carros no estacionamento!\n");
    } else {
        printf("\nO estacionamento esta vazio.\n");
    }
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
