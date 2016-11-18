//CS 539: Midterm, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

int prime(unsigned n);
int die(const char* msg);

int main() {
	unsigned i = 1;

	for (i; i < 1000; ++i) {
		if (prime(i)) printf("%f\n", i);
	}

	// system("pause");
	return 0;
}
int prime(unsigned n) {
	unsigned i = 5;

	if (n == 2 || n == 3) return 1;
	if (n % 2 == 0) return 0;
	for (i; i < n; i + 2) {
		if (i > n) return 1;
		if (!(n % i)) return 0;
	}
}

int die(const char* msg) {
	printf("Fatal error: %s\n", msg);
	exit(EXIT_FAILURE);
}