#include "list.h"

int main()
{
    int hash_size = 0, vector_size = 0, colisionlinear_count = 0, colisiondouble_count = 0, *input_vector;

    printf("\nInforme a quantidade de valores que deseja inserir no vetor de entradas: ");
    scanf("%d", &vector_size);

    input_vector = malloc(vector_size*sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < vector_size; i++){
        input_vector[i] = (rand() % 100);
        printf("\n%dº Valor aleatorio: %d", i+1, input_vector[i]);
    }
    printf("\n");

    hash_size = FoldSize(vector_size);

    colisionlinear_count = LinearHashing(vector_size, hash_size, input_vector);
    colisiondouble_count = DoubleHashing(vector_size, hash_size, input_vector);

    printf("\nOcorreu um total de %d colisões na Hash Linear", colisionlinear_count);
    printf("\nOcorreu um total de %d colisões na Hash Dupla\n\n", colisiondouble_count);

    return 0;
}