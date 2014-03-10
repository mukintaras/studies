#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a, b;

	scanf("%lg%lg", &a, &b);

	double s = (a+b)/2000000;

	for (int i = 1; i < 1000000; ++i)
	{
		s += sin((a + ((b-a)*i)/1000000)*(a + ((b-a)*i)/1000000))*(b-a)/1000000;
	}

	printf("%lg", s);

	return 0;
}