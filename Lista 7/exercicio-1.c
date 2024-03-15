#include <stdio.h>

/*Implementar programa para ler total de vendas, de um
  determinado mês, dos 300 vendedores da “Matura”,
  calcular a média de vendas do grupo de vendedores, e
  exibir quantos vendedores apresentaram desempenho
  (vendas) abaixo da média. */

int main() {
    int num_vendedores = 300;
    int vendas[num_vendedores];
    int total_vendas = 0;

    // Ler as vendas de cada vendedor
    printf("Digite o total de vendas de cada vendedor da Matura:\n");
    for (int i = 0; i < num_vendedores; i++) {
        printf("Vendedor %d: ", i + 1);
        scanf("%d", &vendas[i]);
        total_vendas += vendas[i];
    }

    // Calcular a média de vendas
    float media_vendas = (float)total_vendas / num_vendedores;

    // Contar quantos vendedores tiveram vendas abaixo da média
    int abaixo_media = 0;
    for (int i = 0; i < num_vendedores; i++) {
        if (vendas[i] < media_vendas) {
            abaixo_media++;
        }
    }

    // Exibir os resultados
    printf("\nMédia de vendas do grupo de vendedores: %.2f\n", media_vendas);
    printf("Quantidade de vendedores com vendas abaixo da média: %d\n", abaixo_media);

    return 0;
}
