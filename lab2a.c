/*
Lamog-Doiel, Robert
Lab 2A
03/07/2017
Stripping punctuation and blanks, putting a single word per line from formatted input utilizing getchar() and putchar().
*/

#include <stdio.h>

/*
    Built my own alpha checker.
*/
int is_alpha_checker( char );
/*
    Reads input redirect via a loop utilizing getchar().
    If the character received is a letter, it prints the character via putchar().
*/
void word_per_line();

int main() {
    word_per_line();

    return 0;
}

int is_alpha_checker( char inputChar ){
    if (((inputChar >= 'A') && (inputChar <= 'Z')) || ((inputChar >= 'a') && (inputChar <='z'))) return 1;
    return 0;
}
void word_per_line(){
    int endOfWordFlag = 0;
    char c;

    while (c != EOF) {
        c = getchar();
        if (is_alpha_checker(c) == 1) {
            putchar(c);
            endOfWordFlag = 1;
        }
        if (is_alpha_checker(c) == 0) {
            if (endOfWordFlag == 1) {
                printf("\n");
                endOfWordFlag = 0;
            }
        }
    }
}