#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, m = 0;

	while(scanf("%d", &n) == 1) 
	{
		m += n;
	}

	// printf("%d\n", m);
	return m;
}