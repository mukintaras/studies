#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a, b, c, d;

	scanf("%lg%lg%lg", &a, &b, &c);

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("R");
			}
			else
			{
				printf("NO");
			}
		}
		else
		{
			if ((-c/b) == 0)
			{
				printf("0");
			}
			else
			{
				printf("%lg", (-c/b));
			}
		}
	}
	else
	{
		d = b*b - 4*a*c;
		if (d == 0)
		{
			if (b == 0 )
			{
				printf("0");
			}
			else
			{
				printf("%lg", -b/(2*a));
			}
		}
		else
		{
			if (d < 0)
			{
				printf("NO");
			}
			else
			{
				if (a > 0)
				{
					printf("%lg %lg", (-b - sqrt(d))/(2*a), (-b + sqrt(d))/(2*a));
				}
				else
				{
					printf("%lg %lg", (-b + sqrt(d))/(2*a), (-b - sqrt(d))/(2*a));
				}
			}
		}
	}
	return 0;
}
