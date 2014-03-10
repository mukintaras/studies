#include <stdio.h>
using namespace std;

int main()
{
	int a[20][20], x, y, l;

	scanf("%d%d", &x, &y);
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j) {
			scanf("%d", &l);
			a[i][j]+=l;
		};

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	};
	
	return 0;
}