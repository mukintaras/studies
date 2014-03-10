#include <stdio.h>

int main()
{
float f=1;
double db=1;
long double ldb=1;
long double x=1;
char s[20];
scanf ("%s", s);

int i=0;
switch (s[0])
{
case 'f':while (x!=(x+f)) {i++; f=f/2;} break;
case 'd':while (x!=(x+db)) {i++; db=db/2;} break;
case 'l':while (x!=(x+ldb)) {i++; ldb=ldb/2;} break;
};

printf ("%d", i);
}