#include <stdio.h>
#include <stdlib.h>

int a[100][100], clr[100], n;

void dfs(int v, int color)
{
	clr[v] = color;
	for (int i = 0; i < n; ++i)
		if ((a[v][i] == 1) && (clr[v] == 0))
			dfs(i, 3-color);
		if ((a[v][i] == 1) && (clr[v] == color)
		{
			printf("NO\n");
			exit(0);
		};
}

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			a[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		clr[i] = 0;
	}



	int v1, v2, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &v1, &v2);
		a[v1][v2] = 1;
		a[v2][v1] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		if (used[i] == 0)
			dfs(i, 1);
	};

	

	return 0;
}