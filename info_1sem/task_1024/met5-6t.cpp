\#include <stdio.h>\\
\#include <stdlib.h>\\
\#include <math.h>\\
{}\\
double f(double x) \{\\
\>return sin(x);\\
\};\\
{}\\
int main() \{\\
\>double e, a, b; \\
\>scanf(''\%lg\%lg\%lg'', \&e, \&a, \&b);\\
\>double sum = 0;\\
\>int num = 0;\\
{}\\
\>while (num < (b-a)/e) \{\\
\>\>sum += f(a + num*e);\\
\>\>num++;\\
\>\};\\
{}\\
\>printf(''\%lg\textbackslash n'', sum*e);\\
\>return 0;\\
\}