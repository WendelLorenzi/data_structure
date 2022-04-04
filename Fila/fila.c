#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
} Lista;
typedef struct fila{
	Lista *ini;
	Lista *fim;
} Fila;

void inserefila(Fila *F, int val){
	Lista *new= (Lista*) malloc(sizeof(Lista));
	new->info= val;
	new->prox= NULL;
	if(F->fim != NULL){
		F->fim->prox= new;
		F->fim= new;
	} else{
		F->ini= new;
		F->fim= new;
	}
}

void imprime(Fila *F){
	Lista *aux= F->ini;
	while(aux != NULL){
		printf("\n Valor: %d", aux->info);
		aux= aux->prox;
	}
}

void removeini(Fila *F){
	Lista *aux= F->ini;
	if(F->ini != NULL){
		F->ini= F->ini->prox;
		if(F->ini == NULL){ //Se existir apenas um elemento na fila
			F->fim= NULL;
		}
		free(aux);
	}
}

Lista* removeLista(Lista* L, int valor){
	Lista* aux=NULL, *ant=NULL;
	aux = L;
	if(aux==NULL)
		return NULL;

	while(aux!=NULL &&
		aux->info!=valor){
		ant=aux;
		aux=aux->prox;
	}
//Nao encontrou o elemento
	if(aux==NULL)
		return L;

//Remove o primeiro elemento
	if(ant==NULL){
		L=aux->prox;
		free(aux);
		return L;
	}else{
		ant->prox=aux->prox;
		free(aux);
//retorna a lista com as alterações
		return L;
	}
}

//remover fila e jogar em uma aux
//insere a aux no ponteiro referencia de forma invertida
void invertefila(Fila *F){
	Lista* L= NULL;
	int valor;

	while(F->ini != NULL){
		L= insereini(L, removeini(F));
	}
	while(L != NULL){
		valor = L->info;
		inserefila(F, valor);
		L= removeLista(L, valor);
	}
}

void removepar(Lista *L){
	Lista *aux= NULL;
	int par;

	while(F->ini != NULL){
		if(F->ini->info %2 != 0){
			//L= inserefim(L, removeini(F));
	} else{
		printf("\n Descartando: %d", removeini(F));
	}
}
	while(L != NULL){
		par= L->info;
		inserefila(F, par);
		L= removeini(L, par);
	}
}

int main(int argc, char const *argv[])
{
	Fila *f= (Fila*) malloc(sizeof(Fila));
	f->ini= NULL;
	f->fim= NULL;
	inserefila(f, 10);
	inserefila(f, 20);
	inserefila(f, 30);
	//removeini(f);
	imprime(f);

	free(f);
	
	return 0;
}