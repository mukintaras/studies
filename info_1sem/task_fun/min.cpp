#include <stdio.h>
using namespace std;

int main()
{
	int n = 0;
	char c;
	do
	{
		scanf("%c", &c);
		if (c == '(') n++
		else n--;
	} while ((n >= 0) && (c != EOL));

	if ((c == EOL) && (n == 0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}