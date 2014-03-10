#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a[1000], mid = 0, d = 0;
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lg", &a[i]);
		mid += a[i]/n;
	};

	for (int i = 0; i < n; ++i)
		d += (a[i] - mid)*(a[i] - mid)/n;

	d = sqrt(d);

	printf("%lg %lg", mid, d);

	return 0;
}