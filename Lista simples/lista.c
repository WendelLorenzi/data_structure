#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista* prox;
	} Lista;

	void imprimelista(Lista *);
	Lista* inserelista(Lista *, int valor);
	void free_func(Lista *);
	Lista* inserefinal(Lista *, int valor);
	Lista* insereOrd(Lista *, int val);
	Lista* removeval(Lista *, int val);
	Lista* invertelista(Lista *);
	Lista* removepares(Lista *);
	Lista* insereIni(Lista *, int valor);
	Lista* Movemaior(Lista *);


int main(int argc, char const *argv[])
{
	Lista *a = NULL;
	/*
	 a = (Lista*) malloc(sizeof(Lista));
	 a->info= 10;
	 a->prox= NULL;
	 a->prox= (Lista*) malloc(sizeof(Lista));
	 a->prox->info= 20;
	a->prox->prox= NULL;
	*/
	a= inserelista(a, 30);
	a= inserelista(a, 10);
	a= inserelista(a, 20);
	printf("\n");

	a= insereOrd(a, 5);
	imprimelista(a);
	printf("\n");

	a= invertelista(a);
	imprimelista(a);
	printf("\n");

	a= removepares(a);
	imprimelista(a);
	printf("\n");

	a= Movemaior(a);
	imprimelista(a);
	printf("\n");
	//a= inserefinal(a, 40);
	//imprimelista(a);
	//printf("\n");
	//removeval(a, 20);
	//imprimelista(a);
	//printf("\n");

	free_func(a);

	return 0;
}

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
	Lista *aux= L;
	Lista *auxx= NULL;
	int maior= 0, compara= 0;

	while(aux != NULL){
		compara= aux->info;
		aux= aux->prox;
		if(compara > maior){
			maior= aux->info;
			auxx->info = aux->info;
			auxx= aux;
		}
	}
	while(aux == NULL){
		aux->info= auxx->info;
	}
	while(){
		aux->
	}
}



