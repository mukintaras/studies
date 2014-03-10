int fib(int a, int b)
{
	int a = 1, b = 1, c = 0;
	for (int i = 1; i < n; ++i)
	{
		c = b; b = a+b; a = c;
	};
	return b;
};