#include <stdio.h>
using namespace std;

int main(){

	int a[100], n, ch;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				ch = a[j]; a[j] = a[j+1]; a[j+1] = ch;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	};

	return 0;	
};
