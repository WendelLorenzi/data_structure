#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lista{
		int info;
		struct lista* prox;
	} Lista;


void imprimelista(Lista *a){
	Lista* aux= a;
	if(aux != NULL){
		printf("%d \n", aux->info);
		imprimelista(aux->prox);
	}
}

Lista* inserelista(Lista* ref, int valor){
	Lista* novo= (Lista*) malloc(sizeof(Lista));
	novo->info= valor;
	novo->prox= ref;
	return novo;
}

Lista* inserefinal(Lista *L, int valor){
	Lista* novo= (Lista*) malloc(sizeof(Lista));
	novo->info= valor;
	if(L == NULL){
		novo->prox= NULL;
		return novo;
	}
	Lista* aux= L;
	if(aux != NULL){
	L->prox= inserefinal(L->prox, valor);
	}
	return L;
}

Lista* removeValor(Lista *L, int val){
	Lista *aux= NULL, *auxx= NULL;
	aux= L;

	if((aux != NULL) && (aux->info != val)){
	auxx= aux;
}
	if(auxx == NULL){
		L= aux->prox;
		free(aux);
	} else{
		auxx->prox=aux->prox;
		free(aux);
		aux->prox= removeValor(aux->prox, val);
	}
	return L;
}

int achaMaior(Lista *L){
	if(L == NULL){
		return INT_MIN;
	} else {
		int maior;
		maior= achaMaior(L->prox);
		if(maior > L->info){
			return maior;
		} else{
			return L->info;
		}
	}
}

int main(int argc, char const *argv[])
{
	Lista *L= (Lista*) malloc(sizeof(Lista));
	L= NULL;

	L= inserelista(L, 10);
	L= inserelista(L, 20);
	L= inserefinal(L, 30);
	//L= removeValor(L, 10);
	imprimelista(L);
	printf("\n");
	int a= achaMaior(L);
	printf("Maior elemento: %d \n", a);

	free(L);

	return 0;
}