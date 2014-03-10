#include <stdio.h>; <stdlib.h>; <math.h>

double f(double x) {
	return (log(x) - 1)*(log(x) - 1) - 2;
};

double module(double l) {
	return (l<0)?(-l):l;
};

int main() {
	double e, a, b;
	scanf("%lg%lg%lg", &e, &a, &b);

	while (module(a-b) > e) {
		if (f(a)*f((a+b)/2) < 0)
			b = (a+b)/2;
		else
			a = (a+b)/2;
	};

	printf("%lg\n", (a+b)/2);

	return 0;
}