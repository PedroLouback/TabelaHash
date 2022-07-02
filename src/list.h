#ifndef LIST_H 
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
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
int FoldSize(int size);
int LinearHashing(int size);
int DoubleHashing(int size);
int KeyCalculate1(int hash_value, int size);
int KeyCalculate2(int hash_value, int size, int key);

#endif