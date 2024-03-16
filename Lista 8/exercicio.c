#include <stdio.h>
#include <stdlib.h>

float M[4][6]={{385,534,309,546,503,477},
        {12, 12, 12, 3, 24, 12},
        {35.9, 72.1, 46.2,74.3,78,90},
        {-28, -18, -18, -18, -22, -18}};
char *NomeFreezers[] = {"Deia", "Sul", "NSul", "Frio", "Fri", "Lux"};
int Frz, Crc;

void MaiorValorEmLinha(float Matriz[][6],int L,int C, float *maiorValor, int *index)
{
    *maiorValor = Matriz[L][0];
    *index = 0;
    
    for(int i = 1; i < C; i++)
    {
        if(Matriz[L][i] > *maiorValor)
        {
            *maiorValor = Matriz[L][i];
            *index = i;
        }
    }
}

void MenorValorEmLinha(float Matriz[][6],int L,int C, float *menorValor, int *index)
{
    *menorValor = Matriz[L][0];
    *index = 0;
    
    for(int i = 1; i < C; i++)
    {
        if(Matriz[L][i] < *menorValor)
        {
            *menorValor = Matriz[L][i];
            *index = i;
        }
    }
}

void ExibeMatriz(float Matriz[][6],int L,int C){
  printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) "); 
    for (int j=0; j<C; j++)
      printf("%6.1f",Matriz[i][j]);
    printf("\n");}};

void ExibeColuna(float Matriz[][6],int L,int C){
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) ");
    printf("%6.1f\n",Matriz[i][C]);}}

void ExibeLinha(float Matriz[][6],int L,int C){
  printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i=0;i<C;i++)
    printf("%.1f ",Matriz[L][i]);
  printf("\n");}

void SelecionaFreezer(float Matriz[][6],int *F){
  printf("Selecione o freezer desejado:\n");
  printf("1 - Deia\n");
  printf("2 - Sul\n");
  printf("3 - NSul\n");
  printf("4 - Frio\n");
  printf("5 - Fri\n");
  printf("6 - Lux\n\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *F=Op-1;};

void SelecionaCaracteristica(float Matriz[][6],int *C){
  system("cls");
  printf("Caracteristica desejado\n");
  printf("1 - Capacidade (litros)\n");
  printf("2 - Garantia (meses)\n");
  printf("3 - Economia(kWh/mes)\n");
  printf("4 - Temperatura Minima (Celsius)\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *C=Op-1;};
  
void AlterarValor(float Matriz[][6], int Freezer, int Caract)
{
    float NovoValor;
    printf("Digite o novo valor: ");
    scanf("%f", &NovoValor);
    
    Matriz[Caract][Freezer] = NovoValor;
}

void MelhorCapacidade(float Matriz[][6], int L, int C) {
    float max;
    int index;
    
    MaiorValorEmLinha(M, L, C, &max, &index);
    
    printf("Melhor capacidade: %.1f (%s)\n", max, NomeFreezers[index]);
}

void MelhorGarantia(float Matriz[][6], int L, int C) {
    float max;
    int index;
    
    MaiorValorEmLinha(M, L, C, &max, &index);
    
    printf("Melhor garantia: %.1f (%s)\n", max, NomeFreezers[index]);
}
void MelhorEconomia(float Matriz[][6], int L, int C) {
    float max;
    int index;
    
    MenorValorEmLinha(M, L, C, &max, &index);
    
    printf("Melhor economia: %.1f (%s)\n", max, NomeFreezers[index]);
}
void MelhorTemperatura(float Matriz[][6], int L, int C) {
    float max;
    int index;
    
    MenorValorEmLinha(M, L, C, &max, &index);
    
    printf("Melhor temperatura: %.1f (%s) \n", max, NomeFreezers[index]);
}
              
int main(){
    
    float a;
    int b;
    
    MaiorValorEmLinha(M, 1, 6, &a, &b);
    printf("%f %d", a, b);
    
  do{
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
    int Op;
    scanf("%d",&Op);
    switch (Op){
      case 1: ExibeMatriz(M,4,6);
              system("pause");
              break;
      case 2: SelecionaFreezer(M,&Frz);
              ExibeColuna(M,4,Frz);
              system("pause");
              break;
      case 3: SelecionaCaracteristica(M,&Crc);
              ExibeLinha(M,Crc,6);
              system("pause");
              break;
      case 4: SelecionaFreezer(M,&Frz);
              SelecionaCaracteristica(M,&Crc);
              AlterarValor(M, Frz, Crc);
              system("pause");
              break; 
      case 5: MelhorCapacidade(M, 0, 6);
              system("pause");
              break;
      case 6: MelhorGarantia(M, 1, 6);
              system("pause");
              break;
      case 7: MelhorEconomia(M, 2, 6);
              system("pause");
              break;
      case 8: MelhorTemperatura(M, 3, 6);
              system("pause");
              break;
      case 9: break;}
      if (Op==9)
        break;}
  while (1);
  return 0;
}
