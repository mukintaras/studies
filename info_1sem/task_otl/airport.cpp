#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double r, srad1, srad2;

double dist(double p11, double p12, double p13, double p21, double p22, double p23, char pc1, char pc2)
{
	double prad1, prad2, rdist;
	prad1 = (p11 + p12/60 + p13/3600)*3.1415926535/180;
	prad2 = (p21 + p22/60 + p23/3600)*3.1415926535/180;
	if (pc1 == 'w')
		prad1 *= -1;
	if (pc2 == 'n')
		prad2 *= -1;

	double cosfi = cos((prad2+srad2)/2);
	//rdist = sqrt( (prad2-srad2)*(prad2-srad2) + cosfi*cosfi*(prad1-prad2)*(prad1-prad2) );
	rdist = acos(sin(prad2)*sin(srad2) + cos(prad2)*cos(srad2)*cos(prad1-srad1));
	return rdist;
};

int main()
{
	double s11, s12, s13, s21, s22, s23;
	double p11, p12, p13, p21, p22, p23;
	char sc1, sc2, pc1, pc2;
	int kol;
	scanf("%lg\n%lg %lg %lg %c %lg %lg %lg %c\n%d", &r, &s11, &s12, &s13, &sc1, &s21, &s22, &s23, &sc2, &kol);
	srad1 = (s11 + s12/60 + s13/3600)*3.141592653589793/180;
	srad2 = (s21 + s22/60 + s23/3600)*3.141592653589793/180;
	if (sc1 == 'w')
		srad1 *= -1;
	if (sc2 == 'n')
		srad2 *= -1;

	int i = 0;
	double cdist = 0, rdist = 1000000000;
	for (i = 0; i < kol; ++i)
	{
		scanf("%lg %lg %lg %c %lg %lg %lg %c", &p11, &p12, &p13, &pc1, &p21, &p22, &p23, &pc2);
		cdist = dist(p11, p12, p13, p21, p22, p23, pc1, pc2);
		//printf("%lg ", cdist);
		if (cdist < 0)
			cdist = -cdist;
		//printf("%lg ", cdist);
		if (cdist > 3.141592653589793)
			cdist = 2*3.141592653589793 - cdist;
		//printf("%lg ", cdist);
		cdist = cdist*r;
		//printf("%lg\n", cdist);
		if (cdist < rdist)
			rdist = cdist;
	};

	if ((rdist < 0.00001) && (rdist > -0.00001))
	{
		rdist = 0;
	}
	printf("%lg\n", rdist);

	return 0;
}