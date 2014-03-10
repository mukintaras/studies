#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char ** argv)
{
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2],"w");

	char c;
	while (fscanf(fin, "%c", &c) == 1) 
		fprintf(fout, "%c", c);

	fclose(fin);
	fclose(fout);

	return 0;
}