#include <stdio.h>
using namespace std;

int a[1024][1024];

int main(){
	int n=0, m=0;
	a[0][0]=1;
	a[0][1]=0;
	
	scanf("%d%d", &n, &m);
	
	for (int i=1; i<=n; i++) {
		a[i][0]=1;
		for (int j=1; j<=i; j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		a[i][i+1]=0;
	}
	
	printf("%d\n", a[n][m]);
	
	return 0;
}

