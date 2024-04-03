/* Ajustar a principal estrutura de dados usada
no Projeto Freezers de forma a aplicar structs.
Selecionar um módulo que manipule os dados
e reescreva-o considerando a estrutura
proposta por você. É suficiente apresentar o trecho
de código (estrutura e módulo). Na
apresentação/avaliação não é preciso executá-lo. */

#include <stdio.h>
#include <stdlib.h>

#define NUM_FREEZERS 6
#define NUM_CARACTERISTICAS 4

// Definição da estrutura para representar um Freezer
typedef struct {
    float capacidade;
    int garantia;
    float economia;
    float temp_minima;
} Freezer;

// Array de Freezers
Freezer freezers[NUM_FREEZERS] = {
    {385, 12, 35.9, -28}, // Deia
    {534, 12, 72.1, -18}, // Sul
    {309, 12, 46.2, -18}, // NSul
    {546, 3, 74.3, -18},  // Frio
    {503, 24, 78, -22},   // Fri
    {477, 12, 90, -18}    // Lux
};

// Array de nomes dos freezers
char *nome_freezers[NUM_FREEZERS] = {"Deia", "Sul", "NSul", "Frio", "Fri", "Lux"};

// Enumeração para representar os critérios de classificação
typedef enum {
    CAPACIDADE,
    GARANTIA,
    ECONOMIA,
    TEMPERATURA
} CriterioClassificacao;

// Função para encontrar o melhor freezer com base no critério especificado
int encontrar_melhor_freezer(CriterioClassificacao criterio) {
    int melhor_index = 0;
    float melhor_valor;

    // Inicialização do valor inicial do melhor critério
    switch (criterio) {
        case CAPACIDADE:
            melhor_valor = freezers[0].capacidade;
            break;
        case GARANTIA:
            melhor_valor = freezers[0].garantia;
            break;
        case ECONOMIA:
            melhor_valor = freezers[0].economia;
            break;
        case TEMPERATURA:
            melhor_valor = freezers[0].temp_minima;
            break;
    }

    // Percorre os freezers para encontrar o melhor conforme o critério
    for (int i = 1; i < NUM_FREEZERS; i++) {
        switch (criterio) {
            case CAPACIDADE:
                if (freezers[i].capacidade > melhor_valor) {
                    melhor_valor = freezers[i].capacidade;
                    melhor_index = i;
                }
                break;
            case GARANTIA:
                if (freezers[i].garantia > melhor_valor) {
                    melhor_valor = freezers[i].garantia;
                    melhor_index = i;
                }
                break;
            case ECONOMIA:
                if (freezers[i].economia > melhor_valor) {
                    melhor_valor = freezers[i].economia;
                    melhor_index = i;
                }
                break;
            case TEMPERATURA:
                if (freezers[i].temp_minima < melhor_valor) {
                    melhor_valor = freezers[i].temp_minima;
                    melhor_index = i;
                }
                break;
        }
    }

    return melhor_index;
}

// Função para exibir os dados de todos os freezers
void exibir_levantamento() {
    printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
    printf("Capacidade (litros) ");
    for (int j = 0; j < NUM_FREEZERS; j++) {
        printf("%6.1f", freezers[j].capacidade);
    }
    printf("\nGarantia (meses)    ");
    for (int j = 0; j < NUM_FREEZERS; j++) {
        printf("%6d", freezers[j].garantia);
    }
    printf("\nEconomia (KWh/mes)  ");
    for (int j = 0; j < NUM_FREEZERS; j++) {
        printf("%6.1f", freezers[j].economia);
    }
    printf("\nTemperatura Min (C) ");
    for (int j = 0; j < NUM_FREEZERS; j++) {
        printf("%6.1f", freezers[j].temp_minima);
    }
    printf("\n");
}

// Função para exibir os dados de um freezer específico
void exibir_dados_freezer(int freezer_index) {
    printf("Dados do Freezer %s:\n", nome_freezers[freezer_index]);
    printf("Capacidade: %.1f\n", freezers[freezer_index].capacidade);
    printf("Garantia: %d meses\n", freezers[freezer_index].garantia);
    printf("Economia: %.1f KWh/mes\n", freezers[freezer_index].economia);
    printf("Temperatura Minima: %.1f Celsius\n", freezers[freezer_index].temp_minima);
}

// Função para exibir os dados de uma característica específica
void exibir_dados_caracteristica(int caracteristica_index) {
    printf("Dados da Caracteristica:\n");
    switch (caracteristica_index) {
        case 0:
            printf("Capacidade (litros):\n");
            for (int i = 0; i < NUM_FREEZERS; i++) {
                printf("%.1f\n", freezers[i].capacidade);
            }
            break;
        case 1:
            printf("Garantia (meses):\n");
            for (int i = 0; i < NUM_FREEZERS; i++) {
                printf("%d\n", freezers[i].garantia);
            }
            break;
        case 2:
            printf("Economia (KWh/mes):\n");
            for (int i = 0; i < NUM_FREEZERS; i++) {
                printf("%.1f\n", freezers[i].economia);
            }
            break;
        case 3:
            printf("Temperatura Minima (Celsius):\n");
            for (int i = 0; i < NUM_FREEZERS; i++) {
                printf("%.1f\n", freezers[i].temp_minima);
            }
            break;
    }
}

// Função para alterar um valor de um freezer específico
void alterar_valor(int freezer_index, int caracteristica_index) {
    switch (caracteristica_index) {
        case 0:
            printf("Digite a nova capacidade (litros): ");
            scanf("%f", &freezers[freezer_index].capacidade);
            break;
        case 1:
            printf("Digite a nova garantia (meses): ");
            scanf("%d", &freezers[freezer_index].garantia);
            break;
        case 2:
            printf("Digite a nova economia (KWh/mes): ");
            scanf("%f", &freezers[freezer_index].economia);
            break;
        case 3:
            printf("Digite a nova temperatura mínima (Celsius): ");
            scanf("%f", &freezers[freezer_index].temp_minima);
            break;
    }
    printf("Valor alterado com sucesso!\n");
}

// Função principal
int main() {
    int op;
    do {
        system("cls");
        printf(">>> Pesquisa Freezer <<<\n\n");
        printf("Selecione a opcao desejada:\n");
        printf("1 - Exibir Levantamento\n");
        printf("2 - Dados de um Freezer\n");
        printf("3 - Dados de uma Caracteristica\n");
        printf("4 - Alterar Dado\n");
        printf("5 - Melhor Freezer em Capacidade\n");
        printf("6 - Melhor Freezer em Garantia\n");
        printf("7 - Melhor Freezer em Economia\n");
        printf("8 - Melhor Freezer em Temperatura\n");
        printf("9 - Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                exibir_levantamento();
                system("pause");
                break;
            case 2:
                printf("Selecione o freezer desejado (0 a 5): ");
                scanf("%d", &op);
                if (op >= 0 && op < NUM_FREEZERS)
                    exibir_dados_freezer(op);
                else
                    printf("Freezer selecionado nao existe.\n");
                system("pause");
                break;
            case 3:
                printf("Selecione a caracteristica desejada (0 a 3):\n");
                printf("0 - Capacidade (litros)\n");
                printf("1 - Garantia (meses)\n");
                printf("2 - Economia (KWh/mes)\n");
                printf("3 - Temperatura Minima (Celsius)\n");
                scanf("%d", &op);
                if (op >= 0 && op < NUM_CARACTERISTICAS)
                    exibir_dados_caracteristica(op);
                else
                    printf("Caracteristica selecionada nao existe.\n");
                system("pause");
                break;
            case 4:
                printf("Selecione o freezer desejado (0 a 5): ");
                scanf("%d", &op);
                if (op >= 0 && op < NUM_FREEZERS) {
                    printf("Selecione a caracteristica desejada (0 a 3):\n");
                    printf("0 - Capacidade (litros)\n");
                    printf("1 - Garantia (meses)\n");
                    printf("2 - Economia (KWh/mes)\n");
                    printf("3 - Temperatura Minima (Celsius)\n");
                    int caracteristica;
                    scanf("%d", &caracteristica);
                    if (caracteristica >= 0 && caracteristica < NUM_CARACTERISTICAS)
                        alterar_valor(op, caracteristica);
                    else
                        printf("Caracteristica selecionada nao existe.\n");
                }
                else
                    printf("Freezer selecionado nao existe.\n");
                system("pause");
                break;
            case 5:
                printf("Melhor Freezer em Capacidade: ");
                printf("%s\n", nome_freezers[encontrar_melhor_freezer(CAPACIDADE)]);
                system("pause");
                break;
            case 6:
                printf("Melhor Freezer em Garantia: ");
                printf("%s\n", nome_freezers[encontrar_melhor_freezer(GARANTIA)]);
                system("pause");
                break;
            case 7:
                printf("Melhor Freezer em Economia: ");
                printf("%s\n", nome_freezers[encontrar_melhor_freezer(ECONOMIA)]);
                system("pause");
                break;
            case 8:
                printf("Melhor Freezer em Temperatura: ");
                printf("%s\n", nome_freezers[encontrar_melhor_freezer(TEMPERATURA)]);
                system("pause");
                break;
        }
    } while (op != 9);

    return 0;
}
