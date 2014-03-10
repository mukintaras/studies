#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sex(int ch)
{
	int sexn = ch&1;
	if (sexn == 0)
		printf("fe");
	else
		printf("ma");
};

void clever(int ch)
{
	int clevern = ch&2;
	if (clevern == 0)
		printf("du");
	else
		printf("cl");
};

void hat(int ch)
{
	int hatn = ch&4;
	if (hatn == 0)
		printf("nh");
	else
		printf("ha");
};

void trous(int ch)
{
	int trousn = ch&8;
	if (trousn == 0)
		printf("sk");
	else
		printf("tr");
};

void hair(int ch)
{
	int hairn = ch&48;
	switch (hairn)
	{
		case 0: printf("bn"); break;
		case 16: printf("rd"); break;
		case 32: printf("bw"); break;
		case 48: printf("bk"); break;
	};
};

void eyes(int ch)
{
	int eyesn = ch&192;
	switch (eyesn)
	{
		case 0: printf("bu"); break;
		case 64: printf("ge"); break;
		case 128: printf("gy"); break;
		case 192: printf("da"); break;
	};
};

char* scn()

int main()
{
	

	return 0;
}