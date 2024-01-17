/*
*Faça um programa para ler um número
inteiro, positivo de três dígitos, e gerar outro
número formado pelos dígitos invertidos do
número lido. (Ex: Numero Lido = 123;
Numero Gerado = 321) Em seguida informar:
NÚMERO GERADO MAIOR QUE NÚMERO LIDO ou
NÚMERO LIDO MAIOR QUE NÚMERO GERADO, ou
ainda, NÚMERO GERADO IGUAL AO NÚMERO
LIDO.
*/

#include <stdio.h>

int inverter3Digitos(int num)
{
    int centena = num / 100;
    int dezena = (num % 100) / 10;
    int unidade = (num % 100) % 10;
    
    return unidade * 100 + dezena * 10 + centena;
}

int main() {
    int num;
    printf("Escolha um numero de 3 digitos\n");
    scanf("%d", &num);
    if(num < 100 || num >= 1000)
        printf("Numero invalido! O valor deve ser maior que 99 e menor que 1000!");
    else
    {
        int invertido = inverter3Digitos(num);
        if(invertido > num)
            printf("NUMERO GERADO MAIOR QUE NUMERO LIDO (%d > %d)", invertido, num);
        else if(invertido == num)
            printf("NUMERO GERADO IGUAL AO NUMERO LIDO (%d = %d)", invertido, num);
        else
            printf("NUMERO GERADO MENOR QUE NUMERO LIDO (%d < %d)", invertido, num);
    }
}
