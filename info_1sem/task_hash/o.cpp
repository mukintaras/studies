#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[100003][13][2];

// void printt()
// {
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		printf("%d - %d ", i, a[i][0][0]);
// 		for (int j = 1; j < 4; ++j)
// 		{
// 			printf("(%d %d) ", a[i][j][0], a[i][j][1]);
// 		};
// 		printf("\n");
// 	};
// 	printf("-----\n");
// }

int main()
{
	long long int code, curi, i;
	int crnt, prev, prevost;

	for (i = 0; i < 100003; ++i)
	{
		a[i][0][0] = 0;
	}

	scanf("%d", &prev);
	code = scanf(" %d", &crnt);

	while (code == 1)
	{
		prevost = prev % 100003;
		curi = -1;
		for (i = 1; i < a[prevost][0][0]+1; ++i)
		{
			if (a[prevost][i][0] == prev)
				curi = i;
		}

		if (curi == -1)
		{
			a[prevost][0][0]++;
			a[prevost][a[prevost][0][0]][0] = prev;
			a[prevost][a[prevost][0][0]][1] = crnt;
		}
		else
		{
			a[prevost][curi][1] = crnt;
		}
		
		prev = crnt;
		code = scanf(" %d", &crnt);
	};

	prevost = prev % 100003;

	curi = -1;

	//printf("%lld \n\n", a[prevost][0][0]);

	for (i = 1; i < a[prevost][0][0]+1; ++i)
	{
		//printf("%lld\n", a[prevost][i][0]);
		if (a[prevost][i][0] == prev)
			//printf("%lld\n", a[prevost][i][1]);
			curi = i;
	};

	if (curi != -1)
	{
		printf("%d\n", a[prevost][curi][1]);
	}
	else
		printf("-1\n");


	// printf("%lld %lld\n", prev, prevost);

	return 0;
}