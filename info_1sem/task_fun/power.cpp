// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

int power(int a, unsigned int n)
{
	int m = 1;
	for (int i = 1; i <= n; ++i)
	{
		m = m*a;
	};
	return m;
};

// int main()
// {
// 	int a, n;
// 	scanf("%d%d", &a, &n);

// 	printf("%d\n", power(a,n));	

// 	return 0;
// }