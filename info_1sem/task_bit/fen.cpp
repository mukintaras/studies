#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[6250500];

void putone(long long int n)
{
	long long int ind = n%32, num = n/32;
	a[num] = a[num]|(1<<(31-ind));
};

int main()
{
	for (int i = 0; i < 6250500; ++i)
	{
		a[i] = 0;
	};

	

	return 0;
}