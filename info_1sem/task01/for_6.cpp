#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int a, res=0, l;
	char k[10000], c;
	scanf("%c %s", &c, k);
	l=(int)strlen(k);

	for (int i=1; i<=l; i++)
		if (c == k[i]) ++res;

	printf("%d", res);
	return 0;
}