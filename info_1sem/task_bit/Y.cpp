// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

long double Ryad(int x)
{
	long double rs = 0;
	for (long double i = x; i > 0; --i)
	{
		rs = rs + 1/(i*i + i);
	};
	return rs;
};

// int main()
// {
// 	printf("%lf\n", Ryad(1));

// 	return 0;
// }