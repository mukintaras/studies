#include <stdio.h>
using namespace std;

int main(){
	long long int n, a[1000];

	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &a[i]);
	}

	for (int j = 2; j < 1141; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] != 0)
			{
				if ((a[i] % j) == 0)
				{
					/* code */
				}
			}
		}
	}
	
	return 0;
}

