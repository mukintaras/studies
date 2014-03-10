// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

char* whatisyourname()
{
	struct anomaly* an = (struct anomaly*)malloc(sizeof(struct anomaly));
	for (int i = 0; i < 256; ++i)
		an->name_of_anomaly[i] = 'n';
	an->number_of_anomaly = 0;

	return an->name_of_anomaly;
};

// int main()
// {
// 	code

// 	return 0;
// }