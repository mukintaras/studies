#include <stdio.h>
#include <stdlib.h>

//void mark(int v, int nm, int am, int cm);

int main()
{
	int n;
	scanf("%d", &n);
	int a[100][100], b[100];

	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{		
			scanf("%d", &a[i][j]);
			if (i == j)
			{
				a[i][j] = 0;
			};
			b[i] += a[i][j];
		};
	};

	//c[0] = 1; mark(0, n, a, c);

	int svj = 0, odd = 1;
	for (int i = 0; i < n; ++i)
	{
		//svj += c[i];
		if (b[i]%2 == 1)
			odd = 0;
	};

	printf("%s\n", (odd)?"YES":"NO");
};

// void mark(int v, int nm, int am, int cm)
// {
// 	int d[nm];
// 	for (int i = 0; i < nm; ++i)
// 	{
// 		d[nm] = 0;
// 	};

// 	for (int i = 0; i < nm; ++i)
// 	{
// 		if ((i != v) && (am[v][i]) && (cm[i] == 0)
// 		{
// 			cm[i] = 1; d[i] = 1
// 		};
// 	};

// 	for (int i = 0; i < nm; ++i)
// 	{
// 		if (d[i])
// 		{
// 			mark(i, nm, am, cm);
// 		};
// 	};
// }