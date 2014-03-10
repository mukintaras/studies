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
}

int main()
{
	int n;
	scanf("%d", &n);

	double ** a = (double **)calloc(n, sizeof(double *));
	for (int i = 0; i < n; ++i)
		a[i] = (double *)calloc(n, sizeof(double));

	double ** e = (double **)calloc(n, sizeof(double *));
	for (int i = 0; i < n; ++i)
		e[i] = (double *)calloc(n, sizeof(double));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lg", &a[i][j]);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i == j)
				e[i][j] = 1;
			else
				e[i][j] = 0;

	//printm(e, n);

	if (eqz(det(a, n)))
		printf("NO\n");
	else //верхнетреугольный вид
	{
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (!eqz(a[i][j]))
				{
					if (eqz(a[j][j]))
						for (int k = 0; k < n; ++k)
						{
							double ch = -a[i][k]; double ch1 = -e[i][k];
							a[i][k] = a[j][k]; e[i][k] = e[j][k];
							a[j][k] = ch; e[j][k] = ch1;
						}
					else
					{
						double mn = a[i][j]/a[j][j];
						for (int k = 0; k < n; ++k)
						{
							a[i][k] -= mn*a[j][k]; e[i][k] -= mn*e[j][k];
						};
						a[i][j] = 0;
					};
					//printm(e, n);
				};
		//printm(a, n);
		//printf("\n---------\n");

		for (int i = n-2; i >= 0; --i)
			for (int j = n-1; j > i ; --j)
				if (!eqz(a[i][j]))
				{
					double mn = a[i][j]/a[j][j];
					for (int k = 0; k < n; ++k)
					{
						e[i][k] -= mn*e[j][k];
					};
					a[i][j] = 0;
					//printm(e, n);
				};
	
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				e[i][j] = e[i][j]/a[i][i];
			};
	};

	printm(e,n);

	return 0;
}