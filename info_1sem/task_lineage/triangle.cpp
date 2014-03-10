#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool eqz(double l)
{
	if ((l > -0.000001) && (l < 0.000001))
		return true;
	else
		return false;
}

void printm(double ** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%lg ", a[i][j]);
		};
		printf("\n");
	};
};

double ** mnr(double ** a, int n, int y)
{
	//printf("##########\n");
	//printm(a, n);
	double ** m = (double **)calloc(n-1, sizeof(double *));
	for (int i = 0; i < n; ++i)
		m[i] = (double *)calloc(n-1, sizeof(double));
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < y; ++j)
			m[i][j] = a[i+1][j];
		for (int j = y; j < n-1; ++j)
			m[i][j] = a[i+1][j+1];	
	};
	//printf("%d\n", y);
	//printm(m, n-1);

	return m;
}

double det(double ** a, int n)
{
	if (n <= 2)
		if (n == 2)
			return a[0][0]*a[1][1] - a[0][1]*a[1][0];
		else
			return a[0][0];
	else
	{
		double dt = 0;
		for (int i = 0; i < n; ++i)
			if (i%2 == 1)
				dt -= a[0][i]*det(mnr(a, n, i), n-1);
			else
				dt += a[0][i]*det(mnr(a, n, i), n-1);
		return dt;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	double ** a = (double **)calloc(n, sizeof(double *));
	for (int i = 0; i < n; ++i)
		a[i] = (double *)calloc(n, sizeof(double));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lg", &a[i][j]);

	if (eqz(det(a, n)))
		printf("NO\n");
	else
	{
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (!eqz(a[i][j]))
				{
					if (eqz(a[j][j]))
						for (int k = j; k < n; ++k)
						{
							double ch = -a[i][k];
							a[i][k] = a[j][k];
							a[j][k] = ch;
						}
					else
					{
						double mn = a[i][j]/a[j][j];
						a[i][j] = 0;
						for (int k = j+1; k < n; ++k)
						{
							a[i][k] -= mn*a[j][k];
						};
					};
				};
		printm(a, n);
	}

	return 0;
}