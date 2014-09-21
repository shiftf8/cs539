/*
Lamog, Robert
Lab 2A
09/30/2014
Stripping punctuation and blanks, putting a single word per line from formatted source input.
*/

#include <stdio.h>

void charChecker();
int isAlphaChecker(int inputChar);

int main() {
    charChecker(); 

    return 0; 
} /* main */

void charChecker() {
    int i = 0;
    char c;

    while (c != EOF) {
        c = getchar();
        if (isAlphaChecker(c) == 1) {
            putchar(c);
            i = 1;
        }
        if (isAlphaChecker(c) == 0) {
            if (i == 1) {
                printf("\n");
                i = 0;
            }
        }
    }
}
int isAlphaChecker(int inputChar) {
    int isAlpha = 0;
    char ch;

    /* checking if capital letter */
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (inputChar == ch) {
            isAlpha = 1;
            break;
        }
    }
    /* checking if lower case letter */
    for (ch = 'a'; ch <= 'z'; ch++) {
        if (inputChar == ch) {
            isAlpha = 1;
            break;
        }
    }

    return isAlpha;
}
