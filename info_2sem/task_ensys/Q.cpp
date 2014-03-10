#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long long int n, rs, md;
	scanf("%lld", &n); //x^2 % M^3 = x
	long long int n3 = n*n*n;

	// for (long long int i = n3-1; i > 127730; --i)
	// {
	// 	md = (i*i)%n3;

	// 	//printf("i %lld, i^2 %lld, n3 %lld, mod %lld\n", i, i*i, n3, md);

	// 	if (md == i)
	// 	{
	// 		rs = i;
	// 		break;
	// 	};
	// };

	long long int i = n3-1;

	while (((i*i)%n3) != i)
		i--;

	printf("%lld\n", i);

	return 0;
}