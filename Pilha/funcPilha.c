#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
} Lista;
typedef struct pilha{
	Lista *topo;
} Pilha;

// Insere topo
void push(Pilha *P, int val){
	Lista *novo= (Lista*) malloc(sizeof(Lista));
	novo->info= val;
	novo->prox= P->topo;
	P->topo= novo;
}

// Imprime
void imprime(Pilha *p){
	Lista *aux= p->topo;
	while(aux != NULL){
		printf("\n Valor: %d", p->topo->info);
		aux= aux->prox;
	}
}

// Remove topo
void pop(Pilha *P){
	Lista *aux;
	aux= P->topo;
	if(P->topo != NULL){
		P->topo= aux->prox;
		free(aux);
	}
}

int main(int argc, char const *argv[])
{
	Pilha *P= (Pilha*) malloc(sizeof(Pilha));
	P->topo= NULL;

	free(P);
	
	return 0;
}