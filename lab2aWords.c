/*
Lamog, Robert
Lab 2A
09/30/2014
Stripping punctuation and blanks, putting a single word per line from formatted input utilizing getchar() and putchar().
*/

#include <stdio.h>

void wordPerLine();
int isAlphaChecker(char); // Built my own alpha checker.

int main() {
    wordPerLine(); 

    return 0; 
} /* main */

void wordPerLine() {
    int endOfWordFlag = 0;
    char c;

    while (c != EOF) {
        c = getchar();
        if (isAlphaChecker(c) == 1) {
            putchar(c);
            endOfWordFlag = 1;
        }
        if (isAlphaChecker(c) == 0) {
            if (endOfWordFlag == 1) {
                printf("\n");
                endOfWordFlag = 0;
            }
        }
    }
}
int isAlphaChecker(char inputChar) {
    if (((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <='z'))) return 1;
    return 0;
}
