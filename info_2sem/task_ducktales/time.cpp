#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	FILE* in;
	FILE* out;
	in = fopen("source", "rb");
	out = fopen("cracked", "wb");

	fseek(in, 0, SEEK_END);
	int i, size = ftell(in);
	rewind(in);

	char* jc = (char*)malloc(size*sizeof(char));

	fread(jc, 1, size, in);

	for (i = 0; i < (size-3); ++i)
	{
		if (*(int*)&jc[i] == 1000000000)
		{
			*(int*)&jc[i] = 2006632960;
			break;
		};
	};

	fwrite(jc, 1, size, out);

	fclose(in);
	fclose(out);

	free(jc);

	return 0;
}