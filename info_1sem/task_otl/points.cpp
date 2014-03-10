#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[100019][102][3], num[100019];

void add(int x, int y, int col)
{
	int xn = x%100019, fl = 0;
	for (int i = 0; i < num[xn]; ++i)
	{
		if ((a[xn][i][0] == x) && (a[xn][i][1] == y))
		{
			a[xn][i][2] = col;
			fl = 1;
		};
	};
	if (fl == 0)
	{
		num[xn]++;
		a[xn][num[xn]][0] = x;
		a[xn][num[xn]][1] = y;
		a[xn][num[xn]][2] = col;
	};
};

int req(int x, int y)
{
	int xn = x%100019, fl = 0, res;
	for (int i = 0; i < num[xn]; ++i)
	{
		if ((a[xn][i][0] == x) && (a[xn][i][1] == y))
		{
			fl = 1;
			return a[xn][i][2];
		};
	};
	if (fl == 0)
		return -1;
};

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 100019; ++i)
	{	
		num[i] = 0;
		for (int j = 0; j < 102; ++j)
		{
			a[i][j][0] = 0;
			a[i][j][1] = 0;
			a[i][j][2] = -1;
		};
	};

	for (int i = 0; i < n; ++i)
	{
		int type, x, y, col, colL;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf(" %d %d %c", &x, &y, &colL);
			if (colL == 66)
				col = 0; //BLUE
			else
				col = 1; //RED
			add(x,y,col);
		};
		else
		{
			int cr = req(x, y);
			printf("%c\n", (cr == -1)?('N'):((cr == 0)?('B'):('R')));
		};
	};

	return 0;
}