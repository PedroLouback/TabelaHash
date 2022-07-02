#include "list.h"

int main()
{
    int option = 0, size = 0;

    printf("\nDigite 1 para Hashing Linear ou 2 para Hashing Duplo: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nInforme o tamanho da Hashing Linear: ");
        scanf("%d", &size);

        size = FoldSize(size);

        LinearHash(size);

        break;
    case 2:
        
        break;
    default:
        break;
    }
	
	return 0;
}