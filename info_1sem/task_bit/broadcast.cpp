#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a1, a2, a3, a4, m1, m2, m3, m4;

	scanf("%d.%d.%d.%d\n%d.%d.%d.%d", &a1, &a2, &a3, &a4, &m1, &m2, &m3, &m4);

	unsigned int a = a4 + 256*a3 + 256*256*a2 + 256*256*256*a1;
	unsigned int m = m4 + 256*m3 + 256*256*m2 + 256*256*256*m1;

	// printf("%d.%d.%d.%d\n", (~m1)|a1, (~m2)|a2, (~m3)|a3, (~m4)|a4);

	// printf("%u %u\n", a, m);

	unsigned int br = (~m)|a;

	printf("%u.%u.%u.%u\n", br/(256*256*256), (br/(256*256))%256, (br/(256))%256, br%256);



	return 0;
}