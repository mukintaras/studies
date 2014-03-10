#include <stdio.h>

int main()
{
	FILE *fin, *fout;
	fin = fopen("solaris.dat", "r");
	fout = fopen("solaris.ans","w");

	char c1,c2;
	while ((fscanf(fin, "%c", &c1) == 1) && (fscanf(fin, "%c", &c2) == 1))
		fprintf(fout, "%c%c", c2, c1);

	return 0;
}