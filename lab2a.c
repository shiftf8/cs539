/*
Lamog-Doiel, Robert
Lab 2A
03/07/2017
Stripping punctuation and blanks, put a single word per line from formatted input utilizing getchar() and putchar().
*/

#include <stdio.h>

/*
    Built my own simple alpha checker.
    Return 1 if char is in range of 'A' to 'Z' or 'a' to 'z'.
    Return 0 if char is NOT in range stated above.
*/
int is_alpha( char );

int main(){
    int isWord = 0;
    char inputChar;

    /*
        Since I only care about letters, it seems appropriate to putchar() only letters via a simple is_alpha( char ) function.
        End of word is simply determined by NON letter after first letter/word recognized.
    */
    while ((inputChar = getchar()) != EOF){
        if (is_alpha(inputChar) == 1){
            putchar(inputChar);
            isWord = 1;
        }
        if (is_alpha(inputChar) == 0){
            if (isWord == 1){
                printf("\n");
                isWord = 0;
            }
        }
    }

    return 0;
}

int is_alpha( char c ){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z')) return 1;
    return 0;
}