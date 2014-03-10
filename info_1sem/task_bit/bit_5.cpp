#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int num(char a, char b)
{
	if ((a == 'm') && (b == 'a'))
		return 0x0001;
	else
	if ((a == 'c') && (b == 'l'))
		return 0x0002;
	else
	if ((a == 'h') && (b == 'a'))
		return 0x0004;
	else
	if ((a == 't') && (b == 'r'))
		return 0x0008;
	else
	if ((a == 'r') && (b == 'd'))
		return 0x0010;
	else
	if ((a == 'b') && (b == 'w'))
		return 0x0020;
	else
	if ((a == 'b') && (b == 'k'))
		return 0x0030;
	else
	if ((a == 'g') && (b == 'e'))
		return 0x0040;
	else
	if ((a == 'g') && (b == 'y'))
		return 0x0080;
	else
	if ((a == 'd') && (b == 'a'))
		return 0x00c0;
	else
		return 0x0000;
};

int main()
{
	char s[1000], a1, a2;
	int man = 0x0000;

	gets(s);

	for (int i = 0; i < (strlen(s)+1)/3; ++i)
	{
		a1 = s[i*3]; a2 = s[i*3+1];
		man = man|num(a1, a2);
	};

	printf("%x\n", man);

	return 0;
}