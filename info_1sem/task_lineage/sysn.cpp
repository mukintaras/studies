#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool eqz(double l)
{
	if ((l > -0.001) && (l < 0.001))
		return true;
	else
		return false;
}

double zero(double l)
{
	if (eqz(l))
		return 0;
	else
		return l;
}

void printm(double ** a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%lg ", zero(a[i][j]));
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
};

// void swap(double * a, double * b)
// {
// 	double * c = a;
// 	a = b;
// 	b = c;
// }

int main()
{
	int n;
	scanf("%d", &n);

	double ** a = (double **)calloc(n, sizeof(double *));
	for (int i = 0; i < n; ++i)
		a[i] = (double *)calloc(n, sizeof(double));

	double * b = (double *)calloc(n, sizeof(double));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			scanf("%lg", &a[j][i]);
		scanf("%lg", &b[i]);
	};

	double delta = det(a, n);
	double * swap;

	if (eqz(delta))
		printf("NO\n");
	else 
	{
		for (int i = 0; i < n; ++i)
		{
			//printm(a,n);
			swap = a[i];
			a[i] = b;
			//printm(a,n);
			printf("%lg\n", det(a,n)/delta);
			a[i] = swap;
		};
	};

	//printm(a,n);

	return 0;
}