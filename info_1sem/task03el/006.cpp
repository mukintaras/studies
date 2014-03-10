#include <stdio.h>
#include <math.h>
using namespace std;

bool b[10001];

int main()
{
	int n = 0, l = 0, m = 0;
	scanf("%d", &n);

	int d = trunc(sqrt(n));

	for (int i = 0; i <= d; ++i)
	{
		for (int j = i; j <= d; ++j)
		{
			for (int k = j; k <= d; ++k)
			{
				l = i*i + j*j+ k*k;
				if (l <= n)
				{
					b[l] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		m += (!b[i])?1:0;
	}

	printf("%d\n", m);

	return 0;
}