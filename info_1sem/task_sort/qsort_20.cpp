#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void * p1, const void * p2)
{
	int q1, q2;
	q1 = *(int*)p1;
	q2 = *(int*)p2;
	return (q2-q1);
};

int main()
{
	int n, a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	};

	qsort(&a[0], n, sizeof(int), cmp_int);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	};

	return 0;
}