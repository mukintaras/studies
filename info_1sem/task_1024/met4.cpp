#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
	return (log(x) - 1)*(log(x) - 1) - 2;
};

double g(double x) {
	return f(x)+x;
}

double module(double l) {
	return (l<0)?(-l):l;
};

int main() {
	double e, a, b; 
	scanf("%lg%lg%lg", &e, &a, &b);
	double c1 = a+2*e, c2 = a;

	while (module(c2 - c1) > e) {
		c1 = c2;
		c2 = g(c2);
	};

	printf("%lg\n", (c1+c2)/2);
	return 0;
}