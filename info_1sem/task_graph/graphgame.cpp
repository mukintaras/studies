#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int k;
		scanf("%d", &k);
		if ((k%4 == 0) || (k%4 == 1))
			printf("Alice\n");
		else
			if (k == 2)
				printf("Alice\n");
			else
				printf("Bob\n");			
	};

	return 0;
};	