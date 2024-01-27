
void pedirPh()
{
    int ph;
    printf("ph: ");
    scanf("%d", &ph);

    if(ph > 7)
        printf("BASICO\n");
    else if(ph == 7)
        printf("NEUTRO\n");
    else if(ph == -1)
        return;
    else
        printf("ACIDO\n");

    pedirPh();
}

void main()
{
    pedirPh();
}