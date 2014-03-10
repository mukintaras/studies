#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cm
{
	double re;
	double im;
};

struct cm pr(struct cm a, struct cm b)
{
	struct cm c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	if ((c.re < 0.5) && (c.re > -0.5))
		c.re = 0;
	if ((c.im < 0.5) && (c.im > -0.5))
		c.im = 0;
	return c;
};

struct cm vch(struct cm a, struct cm b)
{
	struct cm c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	if ((c.re < 0.5) && (c.re > -0.5))
		c.re = 0;
	if ((c.im < 0.5) && (c.im > -0.5))
		c.im = 0;
	return c;
};

struct cm a[20][20], e[20][20], nmn1, nmn2, nmn3, nmn4;

void prnta()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%lg %lg ", a[i][j].re, a[i][j].im);
		};
		printf("\n");
	};
	printf("------------\n");
};

void prnte()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%lg %lg ", e[i][j].re, e[i][j].im);
		};
		printf("\n");
	};
	printf("------------\n");
};

int main()
{
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%lg%lg", &a[i][j].re, &a[i][j].im);
		};
	};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			e[i][j].im = 0;
			if (i == j)
				e[i][j].re = 1;
			else
				e[i][j].re = 0;
		};
	};

	for (int j = 0; j < n-1; ++j)
	{
		for (int i = 1; i < j+1; ++i)
		{
			if (a[i][j] != 0)
			{
				if (a[j][j] == 0)
				{
					for (int k = j+1; k < n; ++k)
					{
						
					}
				}

				nmn1 = a[j][j];
				nmn2 = a[i][j];

				for (int k = 0; k < n; ++k)
				{
					a[j][k] = pr(a[j][k],nmn2);
					e[j][k] = pr(e[j][k],nmn2);
					a[i][k] = pr(a[i][k],nmn1);
					e[i][k] = pr(e[i][k],nmn1);
				};
				prnta();
				for (int k = 0; k < n; ++k)
				{
					a[i][k] = vch(a[i][k],a[j][k]);
					e[i][k] = vch(e[i][k],e[j][k]);
				};
			}
			prnta();
		};
	};

	prnta();

	prnte();

	for (int i = n-2; i >= 0; --i)
	{
		for (int j = n-1; j >= i+1; --j)
		{
			nmn3 = a[i][j];
			nmn4 = a[j][j];
			for (int k = 0; k < n; ++k)
			{
				a[i][k] = pr(a[i][k],nmn4);
				e[i][k] = pr(e[i][k],nmn4);
				a[j][k] = pr(a[j][k],nmn3);
				e[j][k] = pr(e[j][k],nmn3);
			};
			prnta();
			for (int k = 0; k < n; ++k)
			{
				a[i][k] = vch(a[i][k],a[j][k]);
				e[i][k] = vch(e[i][k],e[j][k]);
			};
			prnta();
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		printf("%lg %lg ", a[i][j].re, a[i][j].im);
	// 	};
	// 	printf("\n------------\n");
	// };

	return 0;
}