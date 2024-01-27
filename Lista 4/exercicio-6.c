#include <stdio.h>

int pedirCandidato()
{
    int port, mat;
    float red;
    printf("Acertos em portugues: ");
    scanf("%d", &port);

    if(port < 0)
        return 0;

    printf("Acertos em matematica: ");
    scanf("%d", &mat);
    printf("Nota em redacao: ");
    scanf("%f", &red);

    float mediaPort = (float) port / 50 * 100;
    float mediaMat = (float) mat / 35 * 100;

    if(mediaPort > 80 && mediaMat > 60 && red > 7)
        return 1 + pedirCandidato();
    else
        return pedirCandidato();
}

void main()
{
    int aprovados = pedirCandidato();
    printf("Aprovados: %d", aprovados);
}