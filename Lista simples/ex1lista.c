#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
		int info;
		struct lista* prox;
	} Lista;

	void imprimelista(Lista *);


int main(int argc, char const *argv[])
{
	Lista *a;
	 a = (Lista*) malloc(sizeof(Lista));
	// Lista *ab;
	 //a->prox= (Lista*) malloc(sizeof(Lista));

	a->info= 10;
	//ab->info= 20;
	a->prox= NULL;
	//a->prox= ab;
	//ab->prox= NULL;
	//printf("%d Lista end. 20: \n", ab->prox->info);
	a->prox= (Lista*) malloc(sizeof(Lista));
	a->prox->info= 20;
	a->prox->prox= NULL;
	imprimelista(a);
	printf("\n");

	free(a->prox);
	free(a);
	return 0;
}

void imprimelista(Lista *a){
	while(a != NULL){
		printf("\n %d", a->info);
		a= a->prox;
	}
}

