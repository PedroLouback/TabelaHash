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
	for (int i = 0; i < size; i++)
	{
		printf("Chave:%d - Valor: %d\n", l[i].first->data.key, l[i].first->data.val);
	}
}

// Faz com que o tamanho da hash passado dobre e seja o número primo proximo desse dobro
int FoldSize(int vector_size)
{

	int i = 0, cont = 0;

	vector_size = vector_size * 2; // dobra

	// vai transformar em número primo
	while (1)
	{
		for (i = 1; i <= vector_size; i++)
		{
			if (vector_size % i == 0)
			{
				cont++;
			}
		}
		if (cont == 2)
		{
			return vector_size;
		}
		else
		{
			vector_size++;
			cont = 0;
		}
	}
}

int LinearHashing(int vector_size, int hash_size, int *input_vector)
{

	Lista LinearHashing[hash_size];
	Item aux;
	int i = 0;
	int key = 0, colision_count = 0;

	for (i = 0; i < hash_size; i++)
	{
		FLVazia(&LinearHashing[i]);
	}

	for (i = 0; i < vector_size; i++)
	{
		aux.val = input_vector[i];
		key = KeyCalculate1(aux.val, hash_size); // primeiro calcula a chave com mod, depois verifica se tem valor dentro dela e ai insere
			aux.key = key;
			if (LinearHashing[key].first == LinearHashing[key].last)
			{
				/*verifica se vai haver colisão, se houver vai inserir mais uma posição da hash e somar um no contador de colisão */
				LInsert(&LinearHashing[key], aux);
			}
			else
			{
				colision_count++;
				LInsert(&LinearHashing[key], aux);
			}
	}
	
	return colision_count;
}

int DoubleHashing(int vector_size, int hash_size, int *input_vector)
{
	Lista DoubleHashing[hash_size + 1];
	Item aux;
	int i = 0, cont = 0;
	int key = 0, colision_count = 0;

	for (i = 0; i <= hash_size; i++)
	{
		FLVazia(&DoubleHashing[i]);
	}

	for (i = 0; i < vector_size; i++)
	{
		aux.val = input_vector[i];
		key = KeyCalculate1(aux.val, hash_size); // primeiro calcula a chave com mod, depois verifica se tem valor dentro dela e ai insere
		aux.key = key;
		if (key == hash_size && cont == 0)
		{
			LInsert(&DoubleHashing[key], aux);
			cont++;
		}
		else if (DoubleHashing[key].first == DoubleHashing[key].last)
		{
			/*verifica se vai haver colisão, se houver vai inserir mais uma posição da hash e somar um no contador de colisão */
			LInsert(&DoubleHashing[key], aux);
		}
		else
		{
			colision_count++;
			key = KeyCalculate2(aux.val, hash_size, key);
			aux.key = key;
			if (DoubleHashing[key].first == DoubleHashing[key].last)
			{
				/*verifica se vai haver colisão novamente */
				LInsert(&DoubleHashing[key], aux);
			}
			else
			{
				colision_count++;
				LInsert(&DoubleHashing[key], aux);
			}
		}
	}
	return colision_count;
}

// Vai achar a chave atraves da função mod
int KeyCalculate1(int hash_value, int hash_size)
{

	int key = 0;

	key = hash_value % (hash_size);

	return key;
}

// Segundo calculo para a Hash Dupla
int KeyCalculate2(int hash_value, int hash_size, int key)
{

	int calculation1 = 0;

	key = hash_value % (hash_size);

	calculation1 = (hash_value * (key)) + (hash_size - 1);

	key = (key + calculation1) % hash_size;

	return key;
}
