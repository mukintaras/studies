#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int det(long long int a[3][3])
{
	long long int rez = a[0][0]*(a[1][1]*a[2][2] - a[2][1]*a[1][2]) - a[1][0]*(a[0][1]*a[2][2] - a[2][1]*a[0][2]) + a[2][0]*(a[0][1]*a[1][2] - a[1][1]*a[0][2]);
	if ((rez < 0.5) && (rez > -0.5))
	{
		return 0;
	}
	else
	{
		return rez;
	}
};

int main()
{
	long long int a[3][4];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%lld", &a[i][j]);
		}
	}

	long long int a1[3][3], a2[3][3], a3[3][3], d[3][3];
	
	for (int i = 0; i < 3; ++i)
	{
		a1[i][0] = a[i][3];
		a2[i][1] = a[i][3];
		a3[i][2] = a[i][3];

		a1[i][1] = a[i][1];
		a1[i][2] = a[i][2];

		a2[i][0] = a[i][0];
		a2[i][2] = a[i][2];

		a3[i][0] = a[i][0];
		a3[i][1] = a[i][1];

		d[i][0] = a[i][0];
		d[i][1] = a[i][1];
		d[i][2] = a[i][2];
	};

	double rt1, rt2, rt3;

	long long int detd = det(d);

	if (detd == 0)
	{
		printf("NO\n");
	}
	else
	{
		rt1 = ((double)det(a1))/((double)detd);
		rt2 = ((double)det(a2))/((double)detd);
		rt3 = ((double)det(a3))/((double)detd);
		printf("%lg\n%lg\n%lg\n", rt1, rt2, rt3);
	};

	return 0;
}