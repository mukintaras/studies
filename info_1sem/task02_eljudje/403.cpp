#include "stdio.h"
#include "stdlib.h"
#include "math.h"
using namespace std;

int main()
{
	long long int a, b;
	char c;

	scanf("%lld %c %lld", &a, &c, &b);

	switch (c){
		case '+':
		printf("%lld\n", a+b);
		break;
		case '/':
		printf("%lld\n", a/b);
		break;
		case '*':
		printf("%lld\n", a*b);
		break;
		case '-':
		printf("%lld\n", a-b);
		break;
	};

	return 0;
}