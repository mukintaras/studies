#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, curn;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &curn);
			if ((curn == 1) && (i >= j))
			{
				printf("%d %d\n", i, j);
			};
		};

	return 0;
}