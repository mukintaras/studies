#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a, b;

	scanf("%lg%lg", &a, &b);

	double s = (a+b)/20000000;

	for (int i = 1; i < 10000000; ++i)
	{
		s += sin((a + ((b-a)*i)/10000000)*(a + ((b-a)*i)/10000000))*(b-a)/10000000;
	}

	printf("%lg", s);

	return 0;
}