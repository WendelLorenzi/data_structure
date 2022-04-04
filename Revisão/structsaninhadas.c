#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nota{
	float P1;
	float P2;
	float T;
	float APS;
} Nota;

	typedef struct aluno{
		char nome[40];
		int RA;
		Nota *nota;
	} aluno;
	void imprime(aluno*);

int main(int argc, char const *argv[])
{
	aluno* a= (aluno*) malloc(2 * sizeof(aluno));

	strcpy(a[0].nome, "Danilo");
	strcpy(a[1].nome, "Wendel");

	a[0].nota= (Nota*) malloc(sizeof(Nota));
	a[1].nota= (Nota*) malloc(sizeof(Nota));

	a[0].nota->P1= 5.0;
	a[0].nota->P2= 10.0;
	a[1].nota->P1= 7.0;
	a[1].nota->P2= 10.0;
	a[0].RA= 1725442;
	a[1].RA= 1997556;

		imprime(&a[0]);
		printf("\n");
		imprime(&a[1]);

		free(a[0].nota);
		free(a[1].nota);
		free(a);

	return 0;
}

void imprime(aluno *a1){
	printf("Nome: %s\n", a1->nome);
	printf("P1: %.2f\n", a1->nota->P1);
	printf("P2: %.2f\n", a1->nota->P2);
	printf("RA: %d\n", a1->RA);
}