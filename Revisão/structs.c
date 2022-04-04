#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
		int RA;
		float P1;
		float P2;
		float T;
		float APS;
	}aluno;

	void imprime(aluno *);

int main(int argc, char const *argv[])
{

	aluno *paluno;
	paluno= (aluno*) malloc(sizeof(aluno));

	paluno->RA= 1997556;
	paluno->P1= 3.0;
	paluno->P2= 10.0;
	paluno->T= 5.0;
	paluno->APS= 10.0;

	imprime(paluno);

	free(paluno);

	return 0;
}
void imprime(aluno *ponteiro){
	printf("RA: %d\n", ponteiro->RA);
	printf("P1: %f\n", ponteiro->P1);
	printf("P2: %f\n", ponteiro->P2);
	printf("T: %f\n", ponteiro->T);
	printf("APS: %f\n", ponteiro->APS);
}