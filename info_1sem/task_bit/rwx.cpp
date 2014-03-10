#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, b[9];

int main()
{
	char c;
	scanf("%o", &a);

	for (int i = 0; i < 9; ++i)
		b[i] = 2;

	for (int i = 8; i >= 0; --i)
	{
		b[i] = a%2;
		a = a/2;
	};

	for (int i = 0; i < 9; ++i)
	{
		c = (i%3 == 0)?'r':((i%3 == 1)?'w':'x');
		if (b[i])
			printf("%c", c);
		else
			printf("-");
	};

	printf("\n");

	return 0;
}