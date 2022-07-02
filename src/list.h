#ifndef LIST_H 
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Lista Lista;

struct Item{
	int val;
	int key;
};

struct Block{
	Item data;
	Block *prox;
};

struct Lista{
	Block *first;
	Block *last;
};


void FLVazia(Lista *l);
void LInsert(Lista *l, Item d);
void LRemove(Lista *l, Item d);
void Swap(Block *a, Block *b);
void LImprime(Lista *l, int size);
int FoldSize(int vector_size);
int LinearHashing(int vector_size, int hash_size, int *input_vector);
int DoubleHashing(int vector_size, int hash_size, int *input_vector);
int KeyCalculate1(int hash_value, int hash_size);
int KeyCalculate2(int hash_value, int hash_size, int key);

#endif