#include <stdio.h>
using namespace std;

int main()
{
	char c; int i=0; bool b=true;
	do
	{
		scanf("%c", &c);
		if (c == '(') i++;
		if (c == ')') i--;
		if (c == '\n') break;
		if (i < 0) b = false;
	} while (b);

	if (b)
		if (i == 0)
			printf("YES");
		else
			printf("NO");
	else
		printf("NO");

	return 0;
}