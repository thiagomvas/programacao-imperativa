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
        return; // MELHORIA: Se a placa estiver em uso, não criar solicitação nova
    
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
    printf("\n Cliente %d: %s", Pos+1, VZonda[Pos].Nome);
    printf("\n Modelo: %s", VZonda[Pos].Modelo);
    printf("\n Placa: %s", VZonda[Pos].Placa);
    printf("\n Defeito: %s", VZonda[Pos].Defeito);
    VZonda[Pos].Status='1';
    printf("\n Status: %c",VZonda[Pos].Status);
    if (VZonda[Pos].Preco==0)
      printf("\n Preco: NAO DEFINIDO");       
    else
      printf("\n Preco: %.2f",VZonda[Pos].Preco);}
}

void RemoverSolicitacao(){
}

void ConsultarSolicitacoes(){
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant==-1)
    printf("Não há serviços cadastrados.");
  else{
    for (int Cont=0; Cont<=Quant; Cont++){
      printf("\n Cliente %d: %s", Cont+1, VZonda[Cont].Nome);
      printf("\n Modelo: %s", VZonda[Cont].Modelo);
      printf("\n Placa: %s", VZonda[Cont].Placa);
      printf("\n Defeito: %s", VZonda[Cont].Defeito);
      printf("\n Status: %c",VZonda[Cont].Status);
    if (VZonda[Cont].Preco==0)
      printf("\n Preco: NAO DEFINIDO");       
    else
      printf("\n Preco: %.2f",VZonda[Cont].Preco);
    printf("\n --------------------- \n\n");}}} 
  
void ConcluirServico(){
}

void EncerrarExpediente(){
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
