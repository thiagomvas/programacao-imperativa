#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct TpFarma{
    char Nome[21];
    float Preco;
    int QEstoque;
    int Ativo; // Novo campo para exclusão lógica
};

typedef struct TpFarma TpFARMA;

FILE *ArqFarma; 

long int Tamanho=21*sizeof(char)+sizeof(float)+sizeof(int)*2; // Alterado para incluir o novo campo Ativo

// Função para formatar o nome do medicamento (primeira letra de cada palavra maiúscula, restante minúscula)
void FormatarNome(char *nome) {
    int i = 0;
    while (nome[i] != '\0') {
        nome[i] = tolower(nome[i]); 
        if (i == 0 || (i > 0 && nome[i - 1] == ' ')) {
            nome[i] = toupper(nome[i]); // Capitaliza a primeira letra de cada palavra
        }
        i++;
    }
}

// Função para verificar se um medicamento já está cadastrado
int FarmacoExiste(const char *nome) {
    TpFARMA RgFarma; 

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, nome) == 0 && RgFarma.Ativo) {
            return 1; // Já existe
        }
    }
    return 0; // Não existe
}

// Função para incluir um novo medicamento
void Incluir() {
    TpFARMA RgFarma; 
    char R;
    do {
        printf("*** inclusao ***\n\n");
        printf("Nome: ");
        scanf("%s",RgFarma.Nome);

        // Formatando o nome do medicamento
        FormatarNome(RgFarma.Nome);

        if (FarmacoExiste(RgFarma.Nome)) {
            printf("Este fármaco já está cadastrado!\n");
        } else {
            printf("Preco: ");
            scanf("%f",&RgFarma.Preco);
            printf("Estoque: ");
            scanf("%d",&RgFarma.QEstoque);
            RgFarma.Ativo = 1; // Define como ativo
            fseek(ArqFarma,0,2);
            fwrite(&RgFarma,Tamanho,1,ArqFarma);
        }

        printf("\nNova inclusao? S/N ");
        scanf(" %c",&R);
        R=toupper(R);
    } while (R!='N');
}

// Função para marcar um medicamento como inativo (exclusão lógica)
void Excluir() {
    TpFARMA RgFarma; 
    printf("*** exclusao ***\n\n");
    printf("Nome do fármaco a excluir: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Formatando o nome do medicamento
    FormatarNome(Farmaco);

    FILE *ArqTemp = fopen("temp.dat", "w+b"); // Arquivo temporário para escrever os medicamentos ativos
    if (ArqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    fseek(ArqFarma, 0, SEEK_SET);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && RgFarma.Ativo) {
            RgFarma.Ativo = 0; // Marca como inativo
            Achou = 1;
        }
        fwrite(&RgFarma, Tamanho, 1, ArqTemp); // Escreve os dados no arquivo temporário
    }

    fclose(ArqFarma);
    fclose(ArqTemp);

    remove("Farmacos.dat"); // Remove o arquivo original
    rename("temp.dat", "Farmacos.dat"); // Renomeia o arquivo temporário para o nome original

    if (Achou) {
        printf("Fármaco excluído com sucesso!\n");
    } else {
        printf("Fármaco não encontrado ou já está excluído.\n");
    }

    ArqFarma = fopen("Farmacos.dat", "a+b"); // Reabre o arquivo principal em modo de adição
}

// Função para consultar os detalhes de um medicamento
void Consultar() {
    TpFARMA RgFarma; // Variável local
    printf("*** consulta ***\n\n");
    printf("Nome do fármaco: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Formatando o nome do medicamento
    FormatarNome(Farmaco);

    fseek(ArqFarma, 0, SEEK_SET);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && RgFarma.Ativo) {
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Preço: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
            Achou = 1;
            break;
        }
    }

    if (!Achou) {
        printf("Fármaco não encontrado ou já está excluído.\n");
    }
}

// Função para listar todos os medicamentos ativos
void ListarTodos() {
    TpFARMA RgFarma; // Variável local
    printf("*** lista todos ***\n\n");

    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (RgFarma.Ativo) { // Verifica se o medicamento está ativo
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Preço: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
            printf("***\n\n");
        }
    }
}

void Vender() {
    TpFARMA RgFarma; 
    printf("*** Compra ***\n\n");
    printf("Nome do fármaco a comprar: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Formatando o nome do medicamento
    FormatarNome(Farmaco);

    FILE *ArqTemp = fopen("temp.dat", "w+b"); // Arquivo temporário para escrever os medicamentos ativos
    if (ArqTemp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    fseek(ArqFarma, 0, SEEK_SET);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && RgFarma.Ativo) {
            
            int quantia;
            float pago;
            
            printf("Comprar quantos medicamentos? ");
            scanf("%d", &quantia);
            
            if(quantia > RgFarma.QEstoque)
            {
                printf("Não há medicamentos suficientes no estoque, apenas %d registrados.", RgFarma.QEstoque);
                return;
            }
            
            float custo = (float) quantia * RgFarma.Preco;
            
            printf("CUSTO: %f\nVALOR PAGO: ", custo);
            scanf("%f", &pago);
            
            
            if(pago >= custo)
            {
                printf("TROCO: %f", pago - custo);
                
                RgFarma.QEstoque -= quantia;
            }
            else
            {
                printf("VALOR PAGO INSUFICIENTE");
            }
            
            
            Achou = 1;
        }
        fwrite(&RgFarma, Tamanho, 1, ArqTemp); // Escreve os dados no arquivo temporário
    }

    fclose(ArqFarma);
    fclose(ArqTemp);

    remove("Farmacos.dat"); // Remove o arquivo original
    rename("temp.dat", "Farmacos.dat"); // Renomeia o arquivo temporário para o nome original

    if (Achou) {
        printf("Fármaco comprado com sucesso!\n");
    } else {
        printf("Fármaco não encontrado ou está excluído.\n");
    }

    ArqFarma = fopen("Farmacos.dat", "a+b"); // Reabre o arquivo principal em modo de adição
}

// Função principal
int main() {
    ArqFarma=fopen("Farmacos.dat","a+b");
    char Opcao;
    do{
        printf("\n\n> > > Pague Pouco < < < \n\n");
        printf("Que deseja fazer? \n\n");
        printf("I - Incluir \n");  
        printf("E - Excluir \n");
        printf("C - Consultar \n");
        printf("T - Listar Todos \n");
        printf("V - Vender \n");
        printf("S - Sair \n\n");
        scanf(" %c", &Opcao);
        Opcao=toupper(Opcao);
        switch (Opcao){
            case 'I': Incluir(); break; 
            case 'E': Excluir(); break; 
            case 'C': Consultar(); break; 
            case 'T': ListarTodos(); break; 
            case 'V': Vender(); break;
        } 
    } while (Opcao != 'S');
    fclose(ArqFarma);
    return 0;
}
