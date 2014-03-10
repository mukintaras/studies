#include "stdio.h"
#include "stdlib.h"
#include "math.h"
using namespace std;

int main()
{
	double x1, y1, z1, x2, y2, z2, sub, ln1, ln2;
	scanf("%lg%lg%lg%lg%lg%lg",  &x1, &y1, &z1, &x2, &y2, &z2);
	
	sub = x1*x2 + y1*y2 + z1*z2;
	ln1 = sqrt(x1*x1 + y1*y1 + z1*z1);
	ln2 = sqrt(x2*x2 + y2*y2 + z2*z2);

	if (fabs(sub)<0.01)
	{
		printf("1\n");
	}
	else
	{
		if (fabs(fabs(sub)-ln1*ln2)<0.01)
		{
			printf("2\n");
		}
		else
		{
			printf("0\n");
		};
	};

	return 0;
}