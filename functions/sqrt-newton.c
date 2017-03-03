
#include <stdio.h>
#define PRECISION 0.05

double test_pow(double x, int p) {
	return p == 0 ? 1 : x * test_pow(x, p-1);
}

double test_sqrt(double y, double x) {
	return (test_pow(y, 2) <= x+PRECISION && test_pow(y, 2) >= x-PRECISION) ? y : test_sqrt(((y + (x/y))/2), x);
}

int main(void) {
	double y = 0.0001;
	printf("Result: %f\n", test_sqrt(y, 199));
	return 0;
}
