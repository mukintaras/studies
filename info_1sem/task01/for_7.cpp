#include <stdio.h>
using namespace std;

int main()
{
	long long int a=0, b=0, res=0, a1=0, b1=0;
	
	scanf("%lld%lld", &a1, &b1);
	a = a1;  b = b1;

	while(a != 0){
		res = a;
		a = b%a;
		b = res;
	}

	printf("%lld %lld", res, (a1*b1/res));
	return 0;
}