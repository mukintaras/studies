#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int d[1005];

void prnum()
{
	for (int i = 7; i > 0; --i)
	{
		printf("%c", (d[i] == 0)?'0':((d[i] == 1)?'1':'$'));
	};

	printf("   ");

	for (int i = 7; i > 0; --i)
	{
		printf("%d ", d[i]);
	};

	printf("\n");
}

int main()
{
	int a[1005], b[1005], ln, fl = 0, curdi;
	char c;
	a[0] = 0;
	b[0] = 0;

	for (int i = 0; i < 1005; ++i)
	{
		a[i] = 0; b[i] = 0; d[i] = 0;
	};

	scanf("%c", &c);
	while ((c == '1') || (c == '0'))
	{
		for (int i = a[0]; i > 0; --i)
		{
			a[i+1] = a[i];
		};
		if (c == '1')
			a[1] = 1;
		else
			a[1] = 0;
		a[0]++;
		scanf("%c", &c);
	};

	scanf("%c", &c);
	while ((c == '1') || (c == '0'))
	{
		for (int i = b[0]; i > 0; --i)
		{
			b[i+1] = b[i];
		};
		if (c == '1')
			b[1] = 1;
		else
			b[1] = 0;
		b[0]++;
		scanf("%c", &c);
	};

	ln = (a[0]<b[0])?(b[0]):(a[0]);

	for (int i = 1; i <= ln; ++i)
	{
		//printf("%d %d %d", a[i], b[i], d[i]);
		curdi = a[i]+b[i]+d[i];
		//printf(" -> %d --- ", curdi);
		if (curdi == 3)
	    	{d[i] = 1; d[i+1] = 1;};
	    if (curdi == 2)
	    	{d[i] = 0; d[i+1] = 1;};
	    if (curdi == 1)
	    	{d[i] = 1; d[i+1] = 0;};
	    if (curdi == 0)
	    	{d[i] = 0; d[i+1] = 0;};
	   // prnum();
	};

	//prnum();

	ln = 0;
	for (int i = 1; i < 1005; ++i)
	{
		if (d[i] != 0)
			ln = i;
	};

	if (ln > 0)
	{
		for (int i = ln; i > 0; --i)
		{
			printf("%c", (d[i] == 0)?'0':'1');
		};
		printf("\n");
	}
	else
		printf("0\n");

	return 0;
}