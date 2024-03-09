#include <stdio.h>
#include <ctype.h>

#define MAX_CARACTERES 20

void tornarMaiuscula(char palavra[MAX_CARACTERES + 1]) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = toupper(palavra[i]);
    }
}

int main() {
    char palavra[21];

    printf("Digite uma palavra com até 20 caracteres: ");
    scanf("%s", palavra);
    
    if (strlen(palavra) <= MAX_CARACTERES) {
        tornarMaiuscula(palavra);
        printf("Palavra em maiúsculas: %s\n", palavra);
    } else {
        printf("A palavra deve ter no máximo 20 caracteres.\n");
    }

    return 0;
}
