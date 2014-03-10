#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	int com = 0;
	int a, b, r[9];
	scanf("%d", &com);

	for (int i = 0; i < 9; ++i)
	{
		r[i] = 0;
	}

	while (com != 0)
	{
		switch (com)
		{
			case 1:
			{
				scanf("%d%d", &a, &b);
				r[a] = (r[a]+r[b])%256;
			};
			break;

			case 2:
			{
				scanf("%d%d", &a, &b);
				r[a] = (r[a]-r[b]);
				if (r[a]<0)
					r[a] += 256;
			};
			break;

			case 3:
			{
				scanf("%d%d", &a, &b);
				r[a] = b%256;
				if (r[a]<0)
					r[a] += 256;
			};
			break;

			case 4:
				printf("%d %d %d %d\n", r[5], r[6], r[7], r[8]);
			break;
		};

		scanf("%d", &com);
	};	

	return 0;
};