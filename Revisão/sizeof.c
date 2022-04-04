#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{
	int x;
	float y;
	double z;
	
} ponto;

int main(int argc, char const *argv[])
{
	printf("size char: %d\n", (int) sizeof(char));
	printf("size int: %d\n", (int) sizeof(int));
	printf("size float: %d\n", (int) sizeof(float));
	printf("size double: %d\n", (int) sizeof(double));
	printf("size ponto: %d\n", (int) sizeof(ponto));
	
	return 0;
}