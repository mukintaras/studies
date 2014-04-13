#include <stdio.h>
#include <stdlib.h>
#define size 16

//char a[size][size];
int main()
{
	char* x;
	x = (char*) malloc(size);
	printf("%lld", (long long int) x);
	free(x);
	return 0;
}