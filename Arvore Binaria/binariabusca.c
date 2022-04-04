#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	int info;
	struct arv* sae;
	struct arv* sad;
} ARV;

void imprime(ARV* a){
	if(a != NULL){
		printf("%d \n", a->info);
		imprime(a->sae);
		imprime(a->sad);
	}
}

ARV* cria_nos(ARV *sae, ARV *sad, int valor){
	ARV *novo= (ARV*) malloc(sizeof(ARV));

	novo->info= valor;
	novo->sae= sae;
	novo->sad= sad;

	return novo;
}

Arv* abb_insere (Arv* a, int v)
{
if (a==NULL) {
a = (Arv*)malloc(sizeof(Arv));
a->info = v;
a->esq = a->dir = NULL;
}
else if (v < a->info)
a->esq = abb_insere(a->esq,v);
else /* v > a->info */
a->dir = abb_insere(a->dir,v);
return a;
}

int maiorNo(Arv* r){
int valor=0;
if(r==NULL){
return -1;
}else if(r->dir!=NULL){
valor= maiorNo(r->dir);
}else{
return r->info;
}
return valor;
}

ARV* inserelistaOrd(ARV* a, int valor){
	if(a == NULL){
	a= (ARV*) malloc(sizeof(ARV));
	a->info= valor;
	a->sae= a->sad = NULL;
	} else if(valor < a->info){
		a->sae= inserelistaOrd(a->sae, valor);
	} else{
		a->sad= inserelistaOrd(a->sad, valor);
	}
	return a;
}


int main(int argc, char const *argv[])
{
	ARV *a= (ARV*) malloc(sizeof(ARV));
	
	imprime(a);

	free(a);

	return 0;
}