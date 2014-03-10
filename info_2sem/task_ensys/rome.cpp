#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rom(char c)
{
	switch (c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	};
};

int main()
{
	char curr, prev;
	int rs = 0, ncurr, nprev;

	scanf("%c%c", &prev, &curr);
	rs += rom(prev);
	ncurr = rom(curr); nprev = rom(prev);

	while (curr != '\n')
	{
		rs += (ncurr > nprev)?(ncurr - 2*nprev):(ncurr);
		prev = curr; nprev = ncurr;
		scanf("%c", &curr);
		ncurr = rom(curr);
	};

	printf("%d\n", rs);

	return 0;
}