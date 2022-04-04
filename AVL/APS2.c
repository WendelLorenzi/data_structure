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

int conta(ARV *a, int b){
	int cont= 0;
	if(a == NULL){
		return cont;
	} else if(b == 0){
		return (cont + 1);
	} else{
		cont= cont + conta(a->sae, (b- 1));
		cont= cont + conta(a->sad, (b - 1));
		return(cont + 1);
	}
}

int main(){
	ARV *a= NULL;
	a= inserelistaOrd(a, 10);
	a= inserelistaOrd(a, 15);
	a= inserelistaOrd(a, 5);
	a= inserelistaOrd(a, 2);
	a= inserelistaOrd(a, 7);
	a= inserelistaOrd(a, 9);
	a= inserelistaOrd(a, 20);

	int aa= 0;
	aa= conta(a, 2);
	printf(" %d \n", aa);
}