#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
	scanf("%c", &c);
	int rs = 0, nm = 0;

	while ((c == '0') || (c == '1') || (c == '2'))
	{
		//printf("%c - ", c);

		if (c == '0')
			nm = 0;
		else
			nm = (c == '1')?1:2;
		//printf("%d\n", nm);

		rs = rs*3 + nm;

		scanf("%c", &c);
	};

	printf("%d\n", rs);

	return 0;
}