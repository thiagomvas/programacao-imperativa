#include <stdio.h>
#include <ctype.h>
int pedirCandidato()
{
    int port, mat;
    float red;
    printf("Acertos em portugues: ");
    scanf("%d", &port);

    printf("Acertos em matematica: ");
    scanf("%d", &mat);
    printf("Nota em redacao: ");
    scanf("%f", &red);

    float mediaPort = (float) port / 50 * 100;
    float mediaMat = (float) mat / 35 * 100;

    char escolha;
    printf("Deseja continuar? (S / N)");
    scanf(" %c", &escolha);

    if(toupper(escolha) == 'S')
    {
        if(mediaPort > 80 && mediaMat > 60 && red > 7)
            return 1 + pedirCandidato();
        else
            return pedirCandidato();
    }
    else return 0;

}

void main()
{
    int aprovados = pedirCandidato();
    printf("Aprovados: %d", aprovados);
}