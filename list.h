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
void LImprime(Lista *l);
void HashLinear(int tam);
int CalculaChave(int valor_hash, int tam);

#endif