#include <stdio.h>
#include <math.h>
using namespace std;

unsigned long long int fib(unsigned int n)
{
    unsigned long long int a = 1, b = 1, c = 0;
    for (int i = 1; i < n; ++i)
    {
        c = b; b = a+b; a = c;
    };
    return b;
};

int main()
{
    int n = 0;
    scanf("%d", &n);

    printf("%lld\n", fib(n));

    return 0;
}