#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	freopen("input.txt", "r", stdin);

	char c; int a[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i] = scanf("%c", &c);
	};

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	};

	return 0;
}