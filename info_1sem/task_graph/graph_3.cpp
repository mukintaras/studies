#include <stdio.h>
#include <stdlib.h>

int a[100][100];

int main()
{
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
		{
			a[i][j] = 0;
		}

	int n, m, v1, v2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &v1, &v2);
			a[v1][v2] = 1;
			a[v2][v1] = 1;
		}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}