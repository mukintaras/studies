#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	enum agent {sm, tw, neo};
	agent anderson = neo;

	printf("%s\n", anderson);

	return 0;
}