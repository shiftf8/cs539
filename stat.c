//CS 539: Midterm, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

void stat(double * ave, double * max, const double a[], unsigned els);
int die(const char* msg);

int main() {
	double ave, max;
	double a[] = { 1, 2, 3, 4 };
	unsigned els = 4;

	stat(&ave, &max, a, els);
	printf("%lf %lf\n", ave, max);

	system("pause");
	return 0;
}
void stat(double * ave, double * max, const double a[], unsigned els) {
	unsigned i = 0;

	*ave = a[0];
	*max = a[0];

	for (i; i < els; ++i) {
		if (*max < a[i]) *max = a[i];
		*ave += a[i];
	}

	*ave = *ave / els;
}

int die(const char* msg) {
	printf("Fatal error: %s\n", msg);
	exit(EXIT_FAILURE);
}