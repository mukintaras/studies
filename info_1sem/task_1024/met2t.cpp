#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) \{
\>return (log(x) - 1)*(log(x) - 1) - 2;
\};

double module(double l) \{
\>return (l<0)?(-l):l;
\};

int main() \{
\>double e, a, b; 
\>scanf(''\%lg\%lg\%lg'', \&e, \&a, \&b);

\>while (module(a-b) > e) \{
\>\>double med = a - ((b-a)*f(a))/(f(b)-f(a));
\>\>a = b;
\>\>b = med;
\>\};

\>printf(''\%lg\\n'', (a+b)/2);
\>return 0;
\}