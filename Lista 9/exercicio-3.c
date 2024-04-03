#include <stdio.h>
#include <string.h>

#define TOTAL_PALAVRAS 10
#define TAMANHO_PALAVRA 50

// Função para ordenar um array de strings usando o algoritmo de seleção
void selectionSort(char arr[][TAMANHO_PALAVRA], int n) {
    int i, j, min_idx;
    char temp[TAMANHO_PALAVRA];

    // Itera sobre o array até o penúltimo elemento
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        // Encontra o índice do menor elemento no restante do array
        for (j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        // Se o índice do menor elemento for diferente do índice atual, realiza a troca
        if (min_idx != i) {
            strcpy(temp, arr[min_idx]);
            strcpy(arr[min_idx], arr[i]);
            strcpy(arr[i], temp);
        }
    }
}

void printArray(char arr[][TAMANHO_PALAVRA], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%s", arr[i]);
        if(i < tamanho - 1)
            printf(", ");
        
    }
    printf("]");
}

int main() {
    char palavras[TOTAL_PALAVRAS][TAMANHO_PALAVRA];
    int n, i;


    printf("Digite %d palavras:\n", TOTAL_PALAVRAS);
    for (i = 0; i < TOTAL_PALAVRAS; i++) {
        printf("Palavra #%d: ", i + 1);
        scanf("%s", palavras[i]);
    }
    
    printf("\nArray de palavras não ordenado: \n");
    printArray(palavras, TOTAL_PALAVRAS);

    selectionSort(palavras, TOTAL_PALAVRAS);

    printf("\nArray de palavras ordenado: \n");
    printArray(palavras, TOTAL_PALAVRAS);
    
    return 0;
}
