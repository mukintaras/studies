#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, curn, rez = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &curn);
			rez += curn;
		};

	printf("%d\n", rez/2);

	return 0;
}