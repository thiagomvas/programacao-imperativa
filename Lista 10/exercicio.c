#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MOTOS 50

// Definição da estrutura para armazenar os dados de uma moto
struct RegMoto {
    char Nome[20];
    char Modelo[10];
    char Placa[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    char Defeito[50];
    char Status;
    float Preco;
};

typedef struct RegMoto TpRegMoto;

TpRegMoto VZonda[MAX_MOTOS]; // Vetor para armazenar os dados das motos
int Quant = 0; // Contador para controlar o número de motos cadastradas
char placasUtilizadas[MAX_MOTOS][8]; // Vetor para armazenar as placas já utilizadas

// Função para verificar se uma placa já foi cadastrada
int PlacaValida(char placa[]) {
    for (int i = 0; i < Quant; i++) {
        if (strcmp(placasUtilizadas[i], placa) == 0) {
            return 1; // Placa encontrada, é válida
        }
    }
    return 0; // Placa não encontrada, é inválida
}

// Função para exibir informações de uma moto
void ExibeMoto(int index) {
    // Formata o nome do cliente para a primeira letra maiúscula e as demais minúsculas
    printf("Cliente: %c", toupper(VZonda[index].Nome[0]));
    for (int i = 1; VZonda[index].Nome[i] != '\0'; i++) {
        printf("%c", tolower(VZonda[index].Nome[i]));
    }
    printf("\nModelo: %s\n", VZonda[index].Modelo);
    printf("Placa: %s\n", VZonda[index].Placa);
    printf("Defeito: %s\n", VZonda[index].Defeito);
    printf("Status: %c\n", VZonda[index].Status);
    printf("Preço: %.2f\n", VZonda[index].Preco);
    printf("----------------------------\n");
}

// Função para solicitar um serviço
void SolicitaServico() {
    char Sair;
    // Loop para permitir a inserção contínua de serviços
    do {
        if (Quant < MAX_MOTOS) { // Verifica se ainda há espaço no vetor VZonda
            printf("\n\n >>> Motos Zonda <<< \n\n");
            printf("Qual o nome do cliente? ");
            scanf(" %[^\n]s", VZonda[Quant].Nome);
            printf("Qual o modelo da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Modelo);
            int placaRepetida;
            do {
                printf("Qual a placa da moto?(Os 7 digitos): ");
                scanf(" %[^\n]s", VZonda[Quant].Placa);
                placaRepetida = PlacaValida(VZonda[Quant].Placa); // Verifica se a placa já está em uso
                if (placaRepetida) {
                    printf("Placa já está em uso. Por favor, insira outra placa.\n");
                }
            } while (placaRepetida); // Repetir até que uma placa única seja inserida
            strcpy(placasUtilizadas[Quant], VZonda[Quant].Placa); // Armazenar a placa utilizada
            printf("Qual o defeito da moto? ");
            scanf(" %[^\n]s", VZonda[Quant].Defeito);
            VZonda[Quant].Status = '0';
            VZonda[Quant].Preco = 0;
            Quant++;
        } else {
            printf("Limite de solicitações atingido.\n");
            break;
        }
        printf("\n\n Deseja inserir novo servico? S|N ");
        scanf(" %c", &Sair);
        Sair = toupper(Sair);
    } while (Sair != 'N');
}

// Função para iniciar um serviço
void IniciaServico() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para iniciar serviço: ");
    scanf(" %[^\n]s", P);
    if (PlacaValida(P)) { // Verifica se a placa é válida
        for (int i = 0; i < Quant; i++) {
            if (strcmp(VZonda[i].Placa, P) == 0) {
                VZonda[i].Status = '1'; // Define o status como '1' indicando serviço iniciado
                printf("Serviço iniciado com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
                return;
            }
        }
    } else {
        printf("Placa não cadastrada ou inválida!\n");
    }
}

// Função para remover uma solicitação de serviço
void RemoverSolicitacao() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para remover solicitação: ");
    scanf(" %[^\n]s", P);
    if (PlacaValida(P)) { // Verifica se a placa é válida
        for (int i = 0; i < Quant; i++) {
            if (strcmp(VZonda[i].Placa, P) == 0) {
                if (VZonda[i].Status == '0') {
                    VZonda[i].Status = '2'; // Define o status como '2' (serviço removido)
                    printf("Solicitação removida com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
                    return;
                } else {
                    printf("Não é possível remover a solicitação. O serviço já foi iniciado.\n");
                    return;
                }
            }
        }
    } else {
        printf("Placa não cadastrada ou inválida!\n");
    }
}

// Função para consultar as solicitações de serviço cadastradas
void ConsultarSolicitacoes() {
    printf("\n\n >>> Motos Zonda <<< \n\n");
    int count = 0;
    for (int i = 0; i < Quant; i++) {
        if (VZonda[i].Status == '0') {
            ExibeMoto(i);
            count++;
        }
    }
    if (count == 0) {
        printf("Não há serviços não iniciados.\n");
    }
}

// Função para concluir um serviço
void ConcluirServico() {
    char P[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para concluir serviço: ");
    scanf(" %[^\n]s", P);
    if (PlacaValida(P)) { // Verifica se a placa é válida
        for (int i = 0; i < Quant; i++) {
            if (strcmp(VZonda[i].Placa, P) == 0) {
                if (VZonda[i].Status == '1') {
                    printf("Digite o preço final do serviço: ");
                    scanf("%f", &VZonda[i].Preco);
                    VZonda[i].Status = '3'; // Define o status como '3' (serviço concluído)
                    printf("Serviço concluído com sucesso para a moto de placa %s.\n", VZonda[i].Placa);
                    return;
                } else {
                    printf("Não é possível concluir o serviço. O serviço não foi iniciado.\n");
                    return;
                }
            }
        }
    } else {
        printf("Placa não cadastrada ou inválida!\n");
    }
}

// Função para encerrar o expediente
void EncerrarExpediente() {
    printf("\n\n >>> Serviços Efetuados <<< \n\n");
    float total = 0;
    int count = 0;
    for (int i = 0; i < Quant; i++) {
        if (VZonda[i].Status == '3') {
            ExibeMoto(i);
            total += VZonda[i].Preco;
            count++;
        }
    }
    if (count == 0) {
        printf("Não há serviços concluídos.\n");
    } else {
        printf("Valor Total Obtido: %.2f\n", total);
    }
}

int main() {
    int Opcao;
    // Loop principal do programa
    do {
        // Exibição do menu e leitura da opção escolhida pelo usuário
        printf("\n\n >>> Motos Zonda <<< \n\n");
        printf("1 - Solicitar Servico \n");
        printf("2 - Iniciar Servico \n");
        printf("3 - Remover Solicitacao \n");
        printf("4 - Consultar Solicitacoes \n");
        printf("5 - Concluir Servico \n");
        printf("6 - Encerrar Expediente \n");
        printf("7 - Sair \n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &Opcao);
        // Switch para executar a opção escolhida pelo usuário
        switch (Opcao) {
            case 1:
                SolicitaServico();
                break;
            case 2:
                IniciaServico();
                break;
            case 3:
                RemoverSolicitacao();
                break;
            case 4:
                ConsultarSolicitacoes();
                break;
            case 5:
                ConcluirServico();
                break;
            case 6:
                EncerrarExpediente();
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Por favor, tente novamente.\n");
        }
    } while (Opcao != 7); // Continua executando até que o usuário escolha sair
    return 0;
}
