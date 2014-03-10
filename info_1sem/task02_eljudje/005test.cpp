#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c,d,e,f;

	c = scanf("%d_%d", &a, &b);
	d = scanf("%d-%d", &e, &f);

	printf("c %d - a %d, b %d\n d %d - e %d, f %d\n", c, a, b, d, e, f);
	
	
	char c1, c2, c3, c4, c0;
	int d1;
	scanf("%c%c%d%c%c%c", &c0, &c1, &d1, &c2, &c3, &c4);
	printf("c0 (%c) c1(%c) d1(%d) c2(%c) c3(%c) c4(%c)", c0, c1, d1, c2, c3, c4);

	return 0;
}