#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista* prox;
		struct lista* ant;
	} ListaD;

	void imprime(ListaD *L){
		while(L != NULL){
			printf("%d \n", L->info);
			L= L->prox;
		}
	}

	void free_func(ListaD *aa){
	while(aa != NULL){
		free(aa->prox);
		aa= aa->prox;
		}
	}

	ListaD* inserelista(ListaD *L, int valor){
		ListaD* novo= (ListaD*) malloc(sizeof(ListaD));
		novo->info= valor;
		novo->prox= L;
		novo->ant= NULL;
	return novo;
	}

ListaD* insereIni(ListaD* L, int valor){ 
	ListaD* novo; 
	novo = (ListaD*) malloc(sizeof(ListaD)); 
	novo->info=valor; 
	novo->prox=L; 
	novo->ant=NULL; 
	if(L!=NULL){ 
	L->ant=novo; 
	}
	return novo; 
}

	ListaD* insereFim(ListaD *L,int info) { 
		ListaD *novo,*aux; 
		novo=(ListaD*)malloc(sizeof(ListaD)); 
		novo->ant=NULL; 
		novo->prox=NULL; 
		novo->info=info; 
		if(L==NULL) 
		return novo; 
		else { 
		aux=L; 
		while(aux->prox!=NULL) {
		aux=aux->prox; 
		aux->prox=novo; 
		novo->ant=aux; 
		}
	} 
	return L; 
}

	ListaD* removeval(ListaD *ref, int val){
	ListaD *aux;
	aux= ref;
	while((aux != NULL) && (aux->info != val)){
		aux= aux->prox;
		if(aux == NULL){
			return ref;
		}
			if(aux->ant == NULL){
				ref= ref->prox;
				ref->ant= NULL;
				free(aux);
			} else if(aux->prox == NULL){
				aux->ant->prox= NULL;
				free(aux);
			} else {
				aux->prox->ant= aux->ant;
				aux->ant->prox= aux->prox;
				free(aux);
			}
			return aux;
	}
}

ListaD* Movemenor(ListaD *L){
	ListaD *aux= L;
	ListaD *menor= L;
	if(L == NULL){
		return L;
	}
	while(aux != NULL){
		if((menor->info) > (aux->info)){
			menor= aux;
		}
		aux= aux->prox;
	}
	if(L->info == menor->info){
		return L;
	}
	menor->ant->prox= menor->prox;
	if(menor->prox != NULL){
		menor->prox->ant= menor->ant;
		menor->prox= L;
		L->ant= menor;
		menor->ant= NULL;
		return menor;
	}
}

	int main(int argc, char const *argv[])
	{
		ListaD *aa= NULL;

		aa= inserelista(aa, 10);
		aa= inserelista(aa, 5);
		aa= inserelista(aa, 2);
		aa= inserelista(aa, 20);
		//aa= removeval(aa, 5);
		aa= Movemenor(aa);

		imprime(aa);
		printf("\n");

		free_func(aa);

		return 0;
	}