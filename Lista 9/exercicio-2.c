#include <stdio.h>
#include <string.h>

// Busca uma chave numa lista de palavras e retorna o indice
int bbinaria(char chave[], int inicio, int fim, char vetor[][30]) {
    // Se o indice do fim for menor que o do começo, retorne que não foi encontrada
    if (fim < inicio)
        return -1; // Chave não encontrada
    else {
        
        int meio = (inicio + fim) / 2;
        
        int comparacao = strcmp(vetor[meio], chave);

        // Se a comparação resultar em 0, a chave foi encontrada no meio do intervalo
        if (comparacao == 0)
            return meio;
        // Se a comparação for menor que 0, a chave está na metade direita do intervalo
        else if (comparacao < 0)
            return bbinaria(chave, meio + 1, fim, vetor); // Busca recursivamente na metade direita
        else
            return bbinaria(chave, inicio, meio - 1, vetor); // Busca recursivamente na metade esquerda
    }
}

int main() {
    char vetor[6][30] = {"aluno","bloco","cozinha", "dado","elefante", "tomate"};
    char chave[] = "dado";
    int posicao = bbinaria(chave, 0, 5, vetor);

    if (posicao != -1)
        printf("A chave \"%s\" foi encontrada na posição %d.\n", chave, posicao);
    else
        printf("A chave \"%s\" não foi encontrada no vetor.\n", chave);

    return 0;
}
