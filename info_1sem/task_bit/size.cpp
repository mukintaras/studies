#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float ft(int s)
{
	float a = 1;
	for (int i = 0; i < s; ++i)
		a = a/2;
	return a;
};

double dt(int s)
{
	double a = 1;
	for (int i = 0; i < s; ++i)
		a = a/2;
	return a;
};

long double lt(int s)
{
	long double a = 1;
	for (int i = 0; i < s; ++i)
		a = a/2;
	return a;
};

int main()
{
	char c = getchar();

	int lngf = 4;
	float f = 1;

	while (f != f+ft(lngf))
		lngf++;

	int lngd = 4;
	double d = 1;

	while (d != d+dt(lngd))
		lngd++;

	int lngl = 4;
	long double l = 1;

	while (l != l+lt(lngl))
		lngl++;

	switch (c)
	{
		case 'f': printf("%d\n", lngf-1); break;
		case 'd': printf("%d\n", lngd-1); break;
		case 'l': printf("%d\n", lngl-1); break;
	};

	return 0;
}