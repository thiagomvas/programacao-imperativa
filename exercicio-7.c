#include <stdio.h>
#include <stdlib.h>

void main() {
    float temperatura;
    printf("Qual a temperatura em graus celcius?\n");
    scanf("%f", &temperatura);
    printf("Temperatura em fahrenheit: %.2f°F", temperatura * 1.8 + 32); // para converter °C -> °F, basta utilizar a formula (C * 1.8) + 32.
}
