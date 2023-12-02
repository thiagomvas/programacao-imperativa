#include <stdio.h>

int main() {
    int num;
    printf("Numero:\n");
    scanf("%d", &num);
    printf("Sucessor: %d\nAntecessor: %d", num + 1, num - 1);
}
