#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RegMoto{
	char Nome[20];
	char Modelo[10];
	char Placa[8]; // FIX: Aumentar placa para 8 caracteres para considerar caractere de escape
	char Defeito[50];
	char Status;
	float Preco;};
typedef struct RegMoto TpRegMoto;
TpRegMoto VZonda[50];

int Quant=-1;//Controla o preenchimento do vetor

// MELHORIA: Modularizar a impressão dos dados da moto

void imprimeMoto(int index)
{
      printf("\n Cliente %d: %s", index+1, VZonda[index].Nome);
      printf("\n Modelo: %s", VZonda[index].Modelo);
      printf("\n Placa: %s", VZonda[index].Placa);
      printf("\n Defeito: %s", VZonda[index].Defeito);
      imprimeStatus(VZonda[index].Status);
    if (VZonda[index].Preco==0)
      printf("\n Preco: NAO DEFINIDO");       
    else
      printf("\n Preco: %.2f",VZonda[index].Preco);
    printf("\n --------------------- \n\n");
}

void imprimeStatus(char status)
{
    printf("\n Status: ");
    status = toupper(status);
    switch(status)
    {
        case '0':
            printf("Não iniciado");
            break;
        case '1':
            printf("Iniciado");
            break;
        case '2':
            printf("Cancelado");
            break;
        case '3':
            printf("Finalizado");
            break;
        default:
            printf("Status invalido");
            break;
    }
}

// MELHORIA: Checar se a placa ja está em uso.
int PlacaEmUso(char placa[]) {
    for (int i = 0; i < Quant; i++) {
        if (strcmp(VZonda[i].Placa, placa) == 0) {
            return 1; // Placa encontrada, é válida
        }
    }
    return 0; // Placa não encontrada, é inválida
}

void SolicitaServico(){
/* (1) Solicitar Serviço – quando se insere os dados supracitados, e também os campos status com valor zero sinalizando que o serviço ainda não foi feito, preço, também iniciado com zero.  Este deve estar em loop. */
  char Sair='S';
  do{
    printf("\n\n >>> Motos Zonda <<< \n\n");
    Quant=Quant+1;
    printf("Qual o nome do cliente? ");
    scanf(" %[^\n]s",VZonda[Quant].Nome);
    printf("Qual o modelo da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Modelo);
    printf("Qual a placa da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Placa);
    
    if(PlacaEmUso(VZonda[Quant].Placa))
    {
	printf("Placa ja está em uso");
        return; // MELHORIA: Se a placa estiver em uso, não criar solicitação nova
    }
	  
    printf("Qual o defeito da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Defeito);
    VZonda[Quant].Status='0';
    VZonda[Quant].Preco=0;
    printf("\n\n Deseja inserir novo servico? S|N ");
    scanf(" %c",&Sair);
    Sair=toupper(Sair);}
  while (Sair!='N');
}

void IniciaServico(){
/*(2) Iniciar Serviço – quando o status de uma dada moto (placa) é iniciado pelo mecânico e o status para a ser um.*/
  char P[7]; 
  printf("Placa da moto para iniciar serviço: ");
  scanf(" %[^\n]s",P);
  int Pos=-1; //posição da moto P no vetor
  //busca da moto para iniciar serviço
  for (int Cont=0; Cont<=Quant; Cont++)
    if (strcmp(VZonda[Cont].Placa,P)==0)
      Pos=Cont;
  if (Pos==-1)
    printf("Moto não cadastrada!");
  else{
        VZonda[Pos].Status='1';
        imprimeMoto(Pos);
  }
}

void RemoverSolicitacao() {
    char Placa[8]; 
    printf("Placa da moto para remover solicitação: ");
    scanf(" %[^\n]s", Placa);
    if (PlacaEmUso(Placa)) { 
        for (int i = 0; i < Quant; i++) {
            if (strcmp(VZonda[i].Placa, Placa) == 0) {
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

void ConsultarSolicitacoes(){
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant==-1)
    printf("Não há serviços cadastrados.");
  else{
    for (int Cont=0; Cont<=Quant; Cont++){
        imprimeMoto(Cont);
    }}} 
  
void ConcluirServico() {
    char Placa[8]; // Corrigido para 8 para acomodar os 7 caracteres da placa e o caractere nulo '\0'
    printf("Placa da moto para concluir serviço: ");
    scanf(" %[^\n]s", Placa);
    if (PlacaEmUso(Placa)) { // Verifica se a placa é válida
        for (int i = 0; i < Quant; i++) {
            if (strcmp(VZonda[i].Placa, Placa) == 0) {
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

void EncerrarExpediente() {
    printf("\n\n >>> Serviços Efetuados <<< \n\n");
    float total = 0;
    int efetuados = 0;
    for (int i = 0; i < Quant; i++) {
        if (VZonda[i].Status == '3') {
            imprimeMoto(i);
            total += VZonda[i].Preco;
            efetuados++;
        }
    }
    if (efetuados == 0) {
        printf("Não há serviços concluídos.\n");
    } else {
        printf("Valor Total Obtido: %.2f\n", total);
    }
}

int main(){
  int Opcao;
  system("clear"); //limpa tela no ReplIt
  do{
    //Exibicao de menu e leitura da opcao. 	
	printf("\n\n >>> Motos Zonda <<< \n\n");
	printf("1 - Solicitar Servico \n");
	printf("2 - Iniciar Servico \n");
	printf("3 - Remover Solicitacao \n");
	printf("4 - Consultar Solicitacoes \n");
	printf("5 - Concluir Servico \n");
	printf("6 - Encerrar Expediente \n");
	printf("7 - Sair \n\n");
	printf("Digite a opcao desejada: ");
	scanf("%d",&Opcao);	
    switch (Opcao){
    case 1: SolicitaServico(); break;
	  case 2: IniciaServico(); break;
	  case 3: RemoverSolicitacao(); break;
	  case 4: ConsultarSolicitacoes(); break;
	  case 5: ConcluirServico(); break;
	  case 6: EncerrarExpediente(); break;
	  case 7: break;}}	  	
	while (Opcao!=7);
  return 0;}
