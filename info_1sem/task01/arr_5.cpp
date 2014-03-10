#include <stdio.h>
using namespace std;

int main(){

	bool pr[1150];

	for (int i = 2; i < 1140; ++i)
		pr[i] = true;

	for (int i = 2; i < 35;7 ++i)
	{
		int j = 2;
		do
		{
			pr[i*j] = false;
			j++;
		} while (i*j <= 1140);
	};



	int n, m;

	scanf("%d", &n);
	m = n;

	for (int i = 2; i < 1140; ++i)
	{
		if (pr[i]) printf("%d ", i);			
	}		

	return 0;	
};
