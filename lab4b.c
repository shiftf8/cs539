/*
Lamog-Doiel, Robert
Lab 4B

Generate a random string of chars, length of 40.
Get user input, minimum 2 chars, maximum 20 chars.
Use a function to replace user input chars within random string to designated character.
Output formatted text.
*/

#define S1_SIZE 41
#define S2_SIZE 21

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Utilizes <stdlib.h>, srand(), and <time.h>, time().
    Generates 40 char string of random upper case letters A-Z and puts it in s1.
*/
void generateRandomString(char [], unsigned);
/*
    fgets() to populate s2.
    Error checks for minimum 2 chars and maximum of 20 chars.
        Checks for valid upper case letters.
*/
int getStrings2(char [], unsigned);
/*
    Advance through s1 and replace any characters in s1 that match characters from s2 with 'reset' character.
*/
void strfilter(char [], char [], char);
/*
    My own simple upper alpha checker.
*/
int isUpperAlpha(char);
void clearBuffer();

int main(){
    char s1[S1_SIZE] = "\0";
    char s2[S2_SIZE] = "\0";
    char c = NULL;
    int loop_again = 0;

    srand(time(NULL));
    generateRandomString(s1, S1_SIZE);
    printf("%s\n", s1);

    do {
        printf("Enter any upper case letters A-Z (2 to 20 letters).\n");
        if (getStrings2(s2, S2_SIZE)){
            printf("Enter any character.\n");
            c = getchar();
            printf("%c or %i\n", c, c);
            clearBuffer();
        } else {
            printf("Invalid input.\n");
            clearBuffer();
        }
        printf("Would you like to enter new letters to reset (Y/N)? ");
        c = getchar();
        putchar(c);
        printf("\n");
        if (c == 'Y' || c == 'y'){
            loop_again = 1;
            clearBuffer();
        }
        else loop_again = 0;
    } while (loop_again);

    return 0;
}

void generateRandomString(char str[], unsigned arr_size){
    unsigned i = 0;

    for (i; i < arr_size; ++i){
        str[i] = (rand() % 26) + 65;
    }
}
int getStrings2(char str[], unsigned arr_size){
    char buf[1024] = "\0";
    unsigned els = 0;
    unsigned upper_alpha = 0;
    char c = NULL;

    fgets(buf, sizeof(buf), stdin);
    while (buf[els] != '\n'){
        if (isUpperAlpha(buf[els])){
            if (els <= 20) str[els] = buf[els];
            upper_alpha++; /* Counting number of valid upper case letters */
        }
        els++; /* Counting number of elements in array */
    }
    printf("%s%u = %u\n", buf, els, upper_alpha);

    if (els <= 2 || els > 20 || els != upper_alpha) return 0;
    else return 1;
}
void strfilter(char s1[], char s2[], char c){

}
int isUpperAlpha(char c){
    if ((c >= 'A') && (c <= 'Z')) return 1;
    return 0;
}
void clearBuffer(){
    char c = NULL;

    while ((c = getchar()) != '\n' && c != EOF){ /* Clearing text input buffer in case of overflow */ }
}