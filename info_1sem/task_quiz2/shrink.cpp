#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt","w", stdout);

	char c; int n = 0, code = 0;
	// for (int i = 0; i < 100; ++i)
	// {
	// 	n = scanf("%c", &c);
	// 	printf("%d %d\n", c, n);
	// }

	code = scanf("%c", &c);

	while (code == 1)
	{
		if (c != ' ')
		{
			if (n > 0)
			{
				printf(" ");
			}
			printf("%c", c);
			n = 0;
		}
		else
		{
			n++;
		}
		code = scanf("%c", &c);	
	};

	if (n > 0)
	{
		printf(" ");
	}

	return 0;
}