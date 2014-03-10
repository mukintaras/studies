#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 7; i >= 0 ; --i)
		printf("%d", (n&(1<<i))>>i);

	printf("\n");
	return 0;
}