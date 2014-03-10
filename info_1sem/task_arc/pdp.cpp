// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

union bit
{
	char a[2];
	unsigned short b;
};

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int adr;

byte mem[65536];

byte b_read(adr a)
{
	return mem[a];
};

void b_write(adr a, byte val)
{
	mem[a] = val;
};

word w_read (adr a)
{
	union bit bt;
	bt.a[0] = mem[a];
	bt.a[1] = mem[a+1];
	return bt.b;
};

void w_write (adr a, word val)
{
	union bit bt;
	bt.b = val;
	mem[a] = bt.a[0];
	mem[a+1] = bt.a[1];
};

// int main()
// {
// 	code

// 	return 0;
// }