#include <stdio.h>
using namespace std;

int main(){

	int a[256][3], a1 = 0, a2 = 1, n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i][0]);
	};

	a[0][1] = 1; a[0][2] = 0;

	for (int i = 0; i < n-1; ++i)
	{
		a[i+1][1] = (a[i][1] == a[i+1][0])?1:0;
		a1 += (a[i+1][1] == 0)?1:0;
		a[i+1][2] = (a[i][2] == a[i+1][0])?1:0;
		a2 += (a[i+1][2] == 0)?1:0;	
	};

	printf("%d\n", (a1<a2)?a1:a2);

	return 0;	
};
