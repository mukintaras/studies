#include <stdio.h>
#include <math.h>
using namespace std;

unsigned int a[1000], b[1000], c[1000], d[1000];

int max(int a, int b)
{
	return (a>b)?a:b;
};

void fib(unsigned int n)
{
	for (int i = 0; i < 1000; ++i)
	{
		a[i]=0; b[i]=0; c[i]=0; d[i]=0; 
	}
	a[0] = 1; a[1] = 1;
	b[0] = 1; b[1] = 1;
	c[0] = 1; c[1] = 0;
	for (int j = 1; j < n; ++j)
	{
		// c = b;
		for (int i = 0; i <= b[0]; ++i)
		{
			c[i] = b[i];
		}


		// b = a+b; 		
		for (int i = 0; i < 1000; ++i)
			d[i]=0; 

		for (int i = 1; i <= max(a[0], b[0]); ++i)
		// {
		// 	d[i] = (a[i] + b[i] + d[i])%10;
		// 	d[i+1] += d[i]/10;
		// }
		{
			d[i+1] = (a[i] + b[i] + d[i])/10;
			d[i] = (a[i] + b[i] + d[i])%10;
		}

		d[0] = (d[max(a[0], b[0])+1] != 0)?(max(a[0], b[0])+1):(max(a[0], b[0]));
		
		for (int i = 0; i <= d[0]; ++i)
		{
			b[i] = d[i];
		}		


		// a = c;
		for (int i = 0; i <= c[0]; ++i)
		{
			a[i] = c[i];
		}
	};
};

int main()
{
	int n = 0;
	scanf("%d", &n);

	// for (int j = 1; j < n+1; ++j)
	// {
	// 	fib(j);

	// 	for (int i = b[0]; i >= 1; --i)
	// 	{
	// 		printf("%d", b[i]);
	// 	}

	// 	printf("\n");
	// }



	fib(n);

	for (int i = b[0]; i >= 1; --i)
	{
		printf("%d", b[i]);
	}

	// printf("%lld\n", fib(n));

	return 0;
}