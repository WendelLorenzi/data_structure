#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
} Lista;
typedef struct pilha{
	Lista *topo;
} Pilha;

void push(Pilha *P, int val){
	Lista *novo= (Lista*) malloc(sizeof(Lista));
	novo->info= val;
	novo->prox= P->topo;
	P->topo= novo;
}
void imprime(Pilha *p){
	Lista *aux= p->topo;
	while(aux != NULL){
		printf("\n Valor: %d", p->topo->info);
		aux= aux->prox;
	}
}

void pop(Pilha *P){
	Lista *aux;
	aux= P->topo;
	if(P->topo != NULL){
		P->topo= aux->prox;
		free(aux);
	}
}
/*
void removepar(Pilha *P){
	Lista *aux= (Lista*) malloc(sizeof(Lista));
	aux->info= P->topo;
	while(aux != NULL){
		if((aux->info %2) == 0){
			free(P->topo);
		} else{
			free(P->topo);
			P->topo= aux->topo->info;
		}
	}
}
*/

int main(int argc, char const *argv[])
{
	Pilha *p= (Pilha*) malloc(sizeof(Pilha));

	p->topo= NULL;

	push(p, 10);
	push(p, 20);
	push(p, 30);
	pop(p);
	imprime(p);

	free(p);
	
	return 0;
}