#include "list.h"

int main()
{
    int option = 0, size = 0, colisionlinear_count = 0, colisiondouble_count = 0;

    while (option != 4)
    {
        printf("\nDigite 1 para Hash Linear, 2 para Hash Duplo ou 3 para visualizar a quantidade colisões em cada Hash: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nInforme o tamanho da Hash Linear: ");
            scanf("%d", &size);

            size = FoldSize(size);

            colisionlinear_count = LinearHashing(size);

            break;
        case 2:

            printf("\nInforme o tamanho da Hash Dupla: ");
            scanf("%d", &size);

            size = FoldSize(size);

            colisiondouble_count = DoubleHashing(size);

            break;
        case 3:

            printf("\nO total de colisões na Hash Linear foi de %d", colisionlinear_count);

            printf("\nO total de colisões na Hash Dupla foi de %d\n", colisiondouble_count);
            option = 4;
            break;
        default:
            break;
        }
    }

    return 0;
}