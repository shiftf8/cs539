//CS 539: Midterm, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

int prime(unsigned n);
int die(const char* msg);

int main() {
	unsigned i = 1;

	for (i; i < 1000; ++i) {
		if (prime(i)) printf("%u\n", i);
	}

	// system("pause");
	return 0;
}
int prime(unsigned n) {
	unsigned i = 2;

	if (n == 0 || n == 1) return 0;
	if (n == 2 || n == 3) return 1;
	for (i; i < (n / 2) + 1; ++i) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int die(const char* msg) {
	printf("Fatal error: %s\n", msg);
	exit(EXIT_FAILURE);
}