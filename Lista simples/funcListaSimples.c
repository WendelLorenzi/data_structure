#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista* prox;
	} Lista;


void imprimelista(Lista *a){
	while(a != NULL){
		printf("\n %d", a->info);
		a= a->prox;
	}
}

Lista* inserelista(Lista* ref, int valor){
	Lista* novo= (Lista*) malloc(sizeof(Lista));
	novo->info= valor;
	novo->prox= ref;
	return novo;
}

void free_func(Lista *aa){
	while(aa != NULL){
		free(aa->prox);
		aa= aa->prox;
	}
}

Lista* inserefinal(Lista *ref, int valor){
	Lista* novo= (Lista*) malloc(sizeof(Lista));
	novo->info= valor;
	if(ref == NULL){
		novo->prox= ref;
		return novo;
	}
	Lista* aux= ref;
	while(aux->prox != NULL){
		aux= aux->prox;
		novo->prox= NULL;
		aux->prox=novo;
		return ref;
	}
}

Lista* insereIni(Lista* Ref, int valor){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = Ref;

	return novo;
}

Lista* insereOrd(Lista* ref, int elem){
	Lista* aux = ref;
	Lista* ant=NULL;
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = elem;

	if (ref==NULL){
		novo->prox=NULL;
		return novo;
	}

	while(aux->info < elem && aux->prox!=NULL){
		ant = aux;
		aux=aux->prox;
	}

	if (ant==NULL && aux->prox == NULL){
		novo->prox = NULL;
		aux->prox = novo;
		return ref;
	}else if (ant==NULL){
		novo->prox = aux;
		return novo;
	}

	if(aux->prox == NULL && aux->info < elem){
		novo->prox = NULL;
		aux->prox=novo;
	}else{
		novo->prox = aux;
		ant->prox = novo;
	}

	return ref;
}

Lista* removeval(Lista *ref, int val){
	Lista *aux= NULL, *auxx= NULL;
	aux= ref;

	 if(aux == NULL){
	 	return NULL;
	 }

	while((aux != NULL) && (aux->info != val)){
		auxx= aux;
		aux= aux->prox;
	}
	if(aux == NULL){
		printf("Valor não encontrado !\n");
		return ref;
	}
	if(auxx == NULL){
		ref= aux->prox;
		free(aux);
		return ref;
	} else{
		auxx->prox=aux->prox;
		free(aux);
		return ref; 
	}
}

Lista* invertelista(Lista *li){
	Lista *aux= NULL;
	Lista *temp= NULL;

	while(li != NULL){
		aux= insereIni(aux, li->info);
		temp= li;
		li= li->prox;
		free(temp);
	}
	return aux;
}

Lista* removepares(Lista *L){
	Lista* aux= L;
	int elem;

	while(aux != NULL){
		elem= aux->info;
		aux= aux->prox;
		if(elem % 2 == 0){
			L= removeval(L, elem);
		}
	}
	return L;
}

Lista* Movemaior(Lista *L){
	Lista* aux=L;
	Lista* ant=NULL;
	Lista* maior=L;
	int valor=L->info;

	if(aux==NULL)
	return NULL;
	if(aux->prox==NULL)
	return L;

	while(aux!=NULL){
	if(valor<aux->info){
	valor=aux->info;
	maior=aux;
	}
	aux=aux->prox;
	}

	/*
	* Encontra a posição anterior do menor elemento
	*/
	aux=L;
	while(aux->info!=valor){
	ant=aux;
	aux=aux->prox;
	}

	//Verifica se o maior nao eh o primeiro
	if(maior->info == L->info){
	return maior;
	}else{
	ant->prox= maior->prox;
	maior->prox=L;
	}

	return maior;
}

int main(int argc, char const *argv[])
{
	Lista *L= (Lista*) malloc(sizeof(Lista));
	L= NULL;

	
	return 0;
}
