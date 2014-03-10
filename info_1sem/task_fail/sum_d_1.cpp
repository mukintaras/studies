#include <stdio.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);

	double x1, y1, x2, y2, x3, y3;
	scanf("%lg%lg%lg%lg%lg%lg", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%lg %lg\n", (x1+x2+x3)/3, (y1+y2+y3)/3);

	return 0;
}