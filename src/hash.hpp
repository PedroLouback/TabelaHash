#ifndef HASH_H 
#define HASH_H

#include <time.h>
#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Hash Hash;

struct Item{
	int val;
	int key;
};

struct Block{
	Item data;
	Block *prox;
};

struct Hash{
	Block *first;
	Block *last;
};

void EscritaArquivo();
void ManipulaMatriz(int i1, int j1, int i2, int j2);
void FHVazia(Hash *l);
void HInsert(Hash *l, Item d);
void HRemove(Hash *l, Item d);
void Swap(Block *a, Block *b);
void HImprime(Hash *l, int size);
int FoldSize(int vector_size);
void LinearHashing(int vector_size, int hash_size, int *input_vector);
int KeyCalculate1(int hash_value, int hash_size);

#endif