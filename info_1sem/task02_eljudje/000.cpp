#include "stdio.h"
using namespace std;

int main()
{
	int a = 0, b = 0;
	char c;
	scanf("%d%c%d", &a, &c, &b);
	if (c == '^')
	{
		printf("%d\n", a*b);
	}
	else
	{
		printf("%d\n", (a+b)%2);
	};
	return 0;
}