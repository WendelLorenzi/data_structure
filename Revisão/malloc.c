#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *vet;
	int i;
	vet= (int*) malloc(5 * sizeof(int));
	for(i=0; i<5; i++){
		scanf("%d", &vet[i]);
	}
	printf("\n");

	for(i=0; i<5; i++){
		printf("%d\n", vet[i]);
	}
	printf("\n");
	
	vet= (int*) realloc(vet, 8 * sizeof(int));

	for(i=0; i<8; i++){
		scanf("%d", &vet[i]);
	}
	printf("\n");
	for(i=0; i<8; i++){
		printf("%d\n", vet[i]);
	}

	free(vet);

	return 0;
}