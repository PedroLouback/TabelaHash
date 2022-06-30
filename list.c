#include "list.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
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

void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}

}

void HashLinear(int tam){

    Lista l[tam];
    Item aux;
    int stop = 0;
    int i = 0;


    for (i = 0; i < tam; i++){
        FLVazia(&l[i]);
    }

    // vai inserir até quando o usuario querer, colocando -1 ele para a inserção
    for(i = 0; i < tam; i++){
        printf("\nInforme o %dº valor da Hash ou insira '-1' para interroper a inserção: ", i+1);
        scanf("%d", &aux.val);
        if(aux.val == -1){
            return;
        }else if(aux.val > 0){
            aux.key = CalculaChave(aux.val, tam); //primeiro calcula a chave, verifica se tem valor dentro dela e ai insere
            if (VerificaHashCheia(aux.key) == 1){
                /*verifica se vai haver colisão, se houver vai inserir mais uma posição da lista */
            }
            LInsert(&l[i], aux);
        }
    }
}

//Vai achar a chave atraves da função mod
int CalculaChave(int valor_hash, int tam){

    int chave;

    chave = valor_hash % tam;

    return chave;
}

