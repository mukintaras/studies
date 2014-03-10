#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ch
{
	int name[30];
	int bugs;
};

int alph(const void* a1, const void* b1)
{
	struct ch a = *(struct ch*)a1;
	struct ch b = *(struct ch*)b1;

	int nm = 0;
	while (a.name[nm] == b.name[nm])
		nm++;
	if (a.name[nm] > b.name[nm])
		return 1;
	else
		return -1;
};

int printch(struct ch a)
{
	int i = 0; 
	while (a.name[i] != 0)
	{	
		printf("%c", a.name[i]);
		i++;
	};
	printf(" %d\n", a.bugs);
};

int nums(const void* a1, const void* b1)
{
	struct ch a = *(struct ch*)a1;
	struct ch b = *(struct ch*)b1;

	if (a.bugs > b.bugs)
		return -1;
	else
		if (a.bugs < b.bugs)
			return 1;
		else
			return alph(a1, b1);
};

int main()
{
	int n, num = 0;
	struct ch* arr;
	char c;

	scanf("%d", &n);
	arr = (struct ch*)calloc(n,sizeof(struct ch));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 30; ++j)
			arr[i].name[j] = 0;
		arr[i].bugs = 0;
	};

	for (int i = 0; i < n; ++i)
	{
		scanf("\n%c", &c);
		//					printf("-%c-", c);
		num = 0;
		while (c != ' ')
		{
			arr[i].name[num] = c;
			num++;
			//				printf(" =%c=", arr[i].name[num]);
			scanf("%c", &c);
		};
		scanf("%d", &arr[i].bugs);
	};

	// for (int i = 0; i < 10; ++i)
	// {
	// 	printf("(%d %c) ", arr[1].name[i], arr[1].name[i]);
	// };

	qsort(arr, n, sizeof(struct ch), alph);

	for (int i = 0; i < n; ++i)
	{
		printch(arr[i]);
	};

	printf("\n");

	qsort(arr, n, sizeof(struct ch), nums);

	for (int i = 0; i < n; ++i)
	{
		printch(arr[i]);
	};

	free(arr);

	return 0;
}