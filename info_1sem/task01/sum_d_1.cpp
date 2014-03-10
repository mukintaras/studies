#include <stdio.h>
using namespace std;

int main()
{
	double x1, x2, x3, y1, y2, y3;

	scanf("%lg%lg%lg%lg%lg%lg", &x1, &y1, &x2, &y2, &x3, &y3);

	printf("%lg %lg", ((x1+x2+x3)/3), ((y1+y2+y3)/3));
	return 0;
}
