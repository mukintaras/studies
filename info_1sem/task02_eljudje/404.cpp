#include <stdio.h>
using namespace std;

bool a[2][1000000];

int main(){
	
	int now;
	bool e = true;

	for (int i = 0; i < 1000000; ++i)
	{
		a[0][i] = false;
		a[1][i] = false;
	};

	scanf("%d", &now);
	while (now > 0) {
		a[0][now] = true;
		scanf("%d", &now);
	};

	scanf("%d", &now);
	while (now > 0) {
		a[1][now] = true;
		scanf("%d", &now);
	};

	for (int i = 0; i < 1000000; ++i)
	{
		if (a[0][i] && a[1][i])
		{
			printf("%d ", i);
			e = false;
		};
	};

	if (e)
	{
		printf("empty\n");
	};

	return 0;
}

