#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void * p1, const void * p2)
{
	int q1, q2;
	q1 = *(int*)p1;
	q2 = *(int*)p2;
	return (q1-q2);
};

int main()
{
	int n, i=0; char a[1000], c;
	scanf("%c", &c);

	while (c != '.')
	{
		a[i] = c;
		i++;
		scanf("%c", &c);
	};

	qsort(&a[0], n, sizeof(int), cmp_int);

	for (int i = 0; i < n; ++i)
	{
		printf("%c", a[i]);
	};
	printf(".\n");

	return 0;
}