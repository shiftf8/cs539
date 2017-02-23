/*
Lamog-Doiel, Robert
Lab 2A
03/07/2017
Stripping punctuation and blanks, putting a single word per line from formatted input utilizing getchar() and putchar().
*/

#include <stdio.h>

/*
    Built my own simple alpha checker.
    Return 1 if char is in range of 'a' to 'z' or 'A' to 'Z'.
    Return 0 if char is NOT in range stated above.
*/
int is_alpha( char );
/*
    Reads input redirect via a loop utilizing getchar().
    If the character received is a letter, it prints the character via putchar().
    Words are printed per line by determining the end of the word via NOT alpha characters.
*/
void word_per_line();

int main(){
    word_per_line();

    return 0;
}

int is_alpha( char inputChar ){
    if ((inputChar >= 'A' && inputChar <= 'Z') || (inputChar >= 'a' && inputChar <='z')) return 1;
    return 0;
}
void word_per_line(){
    int endOfWordFlag = 0;
    char c;

    while (c != EOF){
        c = getchar();
        if (is_alpha(c) == 1){
            putchar(c);
            endOfWordFlag = 1;
        }
        if (is_alpha(c) == 0){
            if (endOfWordFlag == 1){
                printf("\n");
                endOfWordFlag = 0;
            }
        }
    }
}