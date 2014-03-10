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

int main()
{
	int n; double a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &a[i]);
	};

	qsort(&a[0], n, sizeof(double), cmp_d);

	for (int i = 0; i < n; ++i)
	{
		printf("%.2lf ", a[i]);
	};

	return 0;
}