#include "list.h"

void Swap(Block *a, Block *b)
{
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
}

void FLVazia(Lista *l)
{
	l->first = (Block *)malloc(sizeof(Block));
	l->last = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d)
{
	l->last->prox = (Block *)malloc(sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d)
{
	Block *aux, *tmp;

	if (l->first == l->last || l == NULL || l->first->prox == NULL)
	{
		printf("LISTA VAZIA!\n");
		return;
	}

	aux = l->first;
	while (aux->prox != NULL)
	{
		if (aux->prox->data.val == d.val)
		{
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last)
				l->last = tmp;
			free(aux);
			aux->prox = NULL;
		}
		else
			aux = aux->prox;
	}
}

void LImprime(Lista *l, int size)
{
	Block *aux;

	for(int i = 0; i < size; i++){
		aux = l[i].first->prox;
		while (aux != NULL)
		{
			printf("%d\n", aux->data.val);
			aux = aux->prox;
		}
	}

	
}

//Faz com que o tamanho da hash passado dobre e seja o número primo proximo desse dobro
int FoldSize(int size)
{

	int i = 0, cont = 0;

	size = size * 2; //dobra

	// vai transformar em número primo
	while (1)
	{
		for (i = 1; i <= size; i++)
		{
			if (size % i == 0)
			{
				cont++;
			}
		}
		if (cont == 2)
		{
			return size;
		}
		else
		{
			size++;
			cont = 0;
		}
	}
}

void LinearHash(int size){

    Lista l[size];
    Item aux;
    int i = 0;
	int key = 0, colision_count=0;

    for (i = 0; i < size; i++){
        FLVazia(&l[i]);
    }

	i = 0;
    // vai inserir até quando o usuario permitir, colocando -1 ele interrope a inserção
    while(1){
        printf("\nInforme o %dº valor da Hash ou insira '-1' para interroper a inserção: ", i+1);
        scanf("%d", &aux.val);
        if(aux.val == -1){
            break;
        }else if(aux.val >= 0){
            key = KeyCalculate(aux.val, size); //primeiro calcula a chave com mod, depois verifica se tem valor dentro dela e ai insere
            if (l[key].first == l[key].last){
                /*verifica se vai haver colisão, se houver vai inserir mais uma posição da hash e somar um no contador de colisão */
				LInsert(&l[key], aux);
            }else{
				colision_count++;
				printf("\nOcorreu uma colisão na chave %d!\nTotal de colisões até o momento: %d\n", key, colision_count);
            	LInsert(&l[key], aux);
			}
        }
		i++;
    }
	printf ("\nHouve um total de %d colisões utilizando a Hash Linear!\n", colision_count);
}

//Vai achar a chave atraves da função mod
int KeyCalculate(int hash_value, int size){

    int key;

    key = hash_value % size;

    return key;
}

