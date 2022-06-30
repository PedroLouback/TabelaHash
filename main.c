#include "list.h"

int main()
{
	Lista l;
	Item aux;
    int escolha = 0, tam = 0;   

	FLVazia(&l);

    printf("\nDigite 1 para Hashing Linear ou 2 para Hashing Duplo: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("\nInforme o tamanho da Hashing Linear: ");
        scanf("%d", &tam);

        HashLinear(tam);

        break;
    case 2:
        
        break;
    default:
        break;
    }
	
	printf("\n");
	LImprime(&l);

	return 0;
}