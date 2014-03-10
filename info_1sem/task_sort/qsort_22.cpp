#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp_d(const void * p1, const void * p2)
{
	double q1, q2;
	q1 = *(double*)p1;
	q2 = *(double*)p2;
	if (((q2-q1)<0.001) && ((q2-q1)>-0.001))
		return 0;
	else
	{
		if (q2 < q1)
			return 1;
		else
			return -1;
	}
};

int tni_pmc(const void* p1, const void* p2)
{
	int i1, i2;
	i1 = *(int*)p1; i2 = *(int*)p2;
	
	if (i1 == i2)
	{
		return 0;
	}
	else
	{
		while (i1%10 == i2%10)
		{
			i1 = i1/10; i2 = i2/10;
		}
		return (i1%10 - i2%10);
	}
}

int cmp_ch(const void* p1, const void* p2)
{
	char c1, c2;
	c1 = *(char*)p1;
	c2 = *(char*)p2;

	return c1 - c2;
}

int main()
{
	int n=0, a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	};

	qsort(&a[0], n, sizeof(int), tni_pmc);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}

	return 0;
}