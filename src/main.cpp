#include "hash.hpp"

int main()
{
    // int hash_size = 0, vector_size = 0, *input_vector;
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;

    EscritaArquivo();

    cout << "\nInforme o 'i' do 1º ponto: ";
    cin >> i1;
    cout << "\nInforme o 'j' do 1º ponto: ";
    cin >> j1;
    cout << "\nInforme o 'i' do 2º ponto: ";
    cin >> i2;
    cout << "\nInforme o 'j' do 2º ponto: ";
    cin >> j2;

    ManipulaMatriz(i1, j1, i2, j2);

    // printf("\nInforme a quantidade de valores que deseja inserir no vetor de entradas: ");
    // scanf("%d", &vector_size);

    // input_vector = (int *)malloc(vector_size*sizeof(int));

    // srand(time(NULL));
    // for(int i = 0; i < vector_size; i++){
    //     input_vector[i] = (rand() % 100);
    //     printf("\n%dº Valor aleatorio: %d", i+1, input_vector[i]);
    // }
    // printf("\n");

    // hash_size = FoldSize(vector_size);

    // LinearHashing(vector_size, hash_size, input_vector);

    return 0;
}