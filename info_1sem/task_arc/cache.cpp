#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[1024][1024], b[1024][1024], c[1024][1024];

int gcd(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main()
{
	int n, d, p, glob = 0;
	scanf("%d%d", &n, &d);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			a[i][j] = gcd(i+1, j+1);
			a[j][i] = a[i][j];
			b[j][i] = gcd(n-j+1,n-i+1);
			b[i][j] = b[j][i];
		};
	};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p = 0;
			for (int k = 0; k < n; ++k)
				p += a[i][k]*b[j][k];
			if (p%d == 0)
				glob++;
		};
	};

	printf("%d\n", glob);

	return 0;
}