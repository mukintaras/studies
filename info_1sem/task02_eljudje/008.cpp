#include <stdio.h>
using namespace std;

int main()
{
	int n = 0, i = -1;
	char c[4000];
	scanf("%s", c);

	// for (int j = 0; j < 4; ++j)
	// {
	// 	printf("%d\n", (int)c[j]);
	// };

	do
	{	
		i++;
		if (c[i] == '(') 
			n++;
		else 
			n--;
	} while ((n >= 0) && ((c[i] == '(') || (c[i] == ')')));

	if ((c[i] != '(') && (c[i] != ')') && (n == -1))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}