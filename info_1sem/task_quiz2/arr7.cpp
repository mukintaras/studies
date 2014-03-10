#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	freopen("input", "r", stdin);
	freopen("answer","w", stdout);

	long long int n, a[105];
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &a[i]);
	};

	printf("1 ");

	for (int i = 0; i < n-1; ++i)
	{
		printf("%lld ", a[i]+a[i+1]);
	};

	printf("1\n");

	return 0;
}