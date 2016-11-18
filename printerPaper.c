//CS 539: Midterm, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

unsigned pages(unsigned linesPerPage, unsigned totalLines);
int die(const char* msg);

int main() {
	unsigned linesPerPage, totalLines;

	printf("lines per page: ");
	if (!scanf("%u", &linesPerPage )) die("Not a number.");
	printf("lines to print: ");
	if (!scanf("%u", &totalLines)) die("Not a number.");
	printf("%u pages\n", pages(linesPerPage, totalLines));

	// system("pause");
	return 0;
}
unsigned pages(unsigned linesPerPage, unsigned totalLines) {
	if (totalLines % linesPerPage == 0) return totalLines / linesPerPage;
	else return (totalLines / linesPerPage) + 1;
}

int die(const char* msg) {
	printf("Fatal error: %s\n", msg);
	exit(EXIT_FAILURE);
}