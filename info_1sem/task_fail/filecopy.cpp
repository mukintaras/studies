#include <stdio.h>

int main()
{
	FILE *fin, *fout;
	fin = fopen("input.dat", "r");
	fout = fopen("output.dat","w");

	char c;
	while (fscanf(fin, "%c", &c) == 1) 
		fprintf(fout, "%c", c);

	return 0;
}