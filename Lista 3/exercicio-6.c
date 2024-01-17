#include <stdio.h>

float calcularImc(float peso, float altura)
{
    return peso / (altura * altura);
}

int main() {
    float peso, altura;
    printf("Qual sua altura em metros?\n");
    scanf("%f", &altura);
    printf("Qual seu peso em quilogramas?\n");
    scanf("%f", &peso);
    
    float imc = calcularImc(peso, altura);
    
    printf("Classificação: ");
    if(imc < 18.5)
        printf("Magreza");
    else if(imc < 24.9)
        printf("Saudável");
    else if(imc < 29.9)
        printf("Sobrepeso");
    else if(imc < 34.9)
        printf("Obesidade Grau I");
    else if(imc < 39.9)
        printf("Obesidade Grau II ( Severa )");
    else 
        printf("Obesidade Grau III ( Morbida )");
    
}
