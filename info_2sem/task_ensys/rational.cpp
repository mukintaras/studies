#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
	double ans = 0;
	scanf("%c", &c);

	while ((c != '.') && (c != '\n'))
	{	
		ans = 2*ans + ((c == '0')?0:1);
		scanf("%c", &c);
	};

	if (c == '.')
	{
		double tw = 2;
		scanf("%c", &c);

		while (c != '\n')
		{
			ans += ((c == '0')?0:1)/tw;
			tw *= 2;
			scanf("%c", &c);
		};
	};

	printf("%.12lf\n", ans);

	return 0;
}