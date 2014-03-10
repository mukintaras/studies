#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dot
{
	int x;
	int y;
	int c;
};

struct dot ** a; 
int num[100019];

void add(int x, int y, int col)
{
	int xn = x%100019, fl = 0, i=0;
	for (i = 0; i < num[xn]; ++i)
	{
		if ((a[xn][i].x == x) && (a[xn][i].y == y))
		{
			a[xn][i].c = col;
			fl = 1;
		};
	};
	if (fl == 0)
	{
		num[xn]++;
		a[xn] = (struct dot *)realloc((void *)a[xn], num[xn]*sizeof(struct dot));
		a[xn][num[xn]-1].x = x;
		a[xn][num[xn]-1].y = y;
		a[xn][num[xn]-1].c = col;
	};
};

int req(int x, int y)
{
	int xn = x%100019, fl = 0, res, i;
	for (i = 0; i < num[xn]; ++i)
	{
		if ((a[xn][i].x == x) && (a[xn][i].y == y))
		{
			fl = 1;
			return a[xn][i].c;
		};
	};
	if (fl == 0)
		return -1;
};

int main()
{
	a = (struct dot **)calloc(100019, sizeof(struct dot *));
	int n;
	scanf("%d", &n);
	int i = 0, i1 = 0, i2 = 0, j1 = 0;
	for (i1 = 0; i1 < 100019; ++i1)
	{	
		num[i1] = 0;
		a[i1] = (struct dot *)malloc(sizeof(struct dot));
	};

	for (i = 0; i < n; ++i)
	{
		int type, x, y, col;
		char colL;
		scanf("%d", &type);
		//printf("%d - ", type);
		if (type == 1)
		{
			scanf(" %d %d %c", &x, &y, &colL);
			//printf("%d %d (%c)\n", x, y, colL);
			if (colL == 66)
				col = 0; //BLUE
			else
				col = 1; //RED
			add(x,y,col);
		}
		else
		{
			scanf("%d%d", &x, &y);
			int cr = req(x, y);
			printf("%c\n", (cr == -1)?('N'):((cr == 0)?('B'):('R')));
		};
	};

	return 0;
}