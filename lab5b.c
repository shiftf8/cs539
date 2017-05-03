/*
Lamog-Doiel, Robert
Lab 5B
04/18/2017

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
void generateRandomString(char *, unsigned);
/*
    fgets() to populate s2.
    Error checks for minimum 2 chars and maximum of 20 chars.
        Checks for valid upper case letters.

    Return 1 on success.
    Return 0 on failure.
*/
int getStrings2(char *, unsigned);
/*
    Advance through s1 and replace any characters in s1 that match characters from s2 with 'reset' character.
    Output formatted string.
*/
void strfilter(char *, char *, char);
/*
    My own simple upper alpha checker.
*/
int isUpperAlpha(char *);
/*
    Initialize string with \0.
*/
void initializeString(char *, unsigned);
/*
    Clear stdin buffer with getchar().
*/
void clearBuffer();

int main(){
    char s1[S1_SIZE] = "\0";
    char s2[S2_SIZE] = "\0";
    char c = NULL;
    int loop_again = 0;

    srand(time(NULL));
    generateRandomString(s1, S1_SIZE - 1); /* Only need to set 40 elements == S1_SIZE - 1 */

    do {
        fputs("Enter any upper case letters A-Z (2 to 20 letters).\n", stdout);
        if (getStrings2(s2, S2_SIZE)){
            fputs("Enter any character.\n", stdout);
            c = getchar();

            fputs("s1 = {\"", stdout);
            fputs(s1, stdout);
            fputs("\"}\ns2 = {\"", stdout);
            fputs(s2, stdout);
            fputs("\"}\nc = {\"", stdout);
            fputc(c, stdout);
            fputs("\"}\n", stdout);
            strfilter(s1, s2, c);
            clearBuffer();
        } else fputs("Invalid input.\n", stdout);
        fputs("Would you like to enter new letters to reset (Y/N)? ", stdout);
        c = getchar();
        putchar(c);
        fputs("\n", stdout);
        if (c == 'Y' || c == 'y'){
            loop_again = 1;
            clearBuffer();
        } else loop_again = 0;
    } while (loop_again);

    return 0;
}

void generateRandomString(char *ptr_str, unsigned arr_size){
    char *ptr_str_tmp = ptr_str;

    while (arr_size){
        *ptr_str_tmp = (rand() % 26) + 65;
        ptr_str_tmp++;
        arr_size--;
    }
}
int getStrings2(char *ptr_str, unsigned arr_size){
    char *ptr_str_tmp = ptr_str;
    char buf[1024] = "\0"; /* Arbitrary buffer size */
    char *ptr_buf_tmp = buf;
    char c = NULL;
    unsigned els = 0;
    unsigned upper_alpha = 0;

    initializeString(ptr_str, arr_size);

    fgets(buf, sizeof(buf), stdin);

    while (*ptr_buf_tmp != '\n'){
        if (isUpperAlpha(ptr_buf_tmp)){
            if (els < S2_SIZE - 1){ /* Only need to set at most 20 elements == S2_SIZE - 1 */
                *ptr_str_tmp = *ptr_buf_tmp;
            }
            upper_alpha++; /* Counting number of upper case letters */
        }
        ptr_str_tmp++;
        ptr_buf_tmp++;
        els++; /* Counting number of elements in array */
    }

    if (els < 2 || els > 20 || els != upper_alpha) return 0;
    return 1;
}
void strfilter(char *s1, char *s2, char c){
    char *ptr_s1_tmp = s1;
    char *ptr_s2_tmp = s2;
    char filtered[S1_SIZE] = "\0";
    char *ptr_filtered_tmp = filtered;
    unsigned i = 0;
    unsigned j = 0;

    for (i; i < S1_SIZE - 1; ++i){ /* Only need to check 40 elements == S1_SIZE - 1 */
        *ptr_filtered_tmp = *ptr_s1_tmp;

        for (j; j < S2_SIZE - 1; ++j){ /* Only need to check 20 elements == S2_SIZE - 1 */
            if (*ptr_s1_tmp == *ptr_s2_tmp) *ptr_filtered_tmp = c;
            ptr_s2_tmp++;
        }
        ptr_filtered_tmp++;
        ptr_s1_tmp++;
        j = 0;
    }

    fputs("filtered = {\"", stdout);
    fputs(filtered, stdout);
    fputs("\"}\n", stdout);
}
int isUpperAlpha(char *c){
    if ((*c >= 'A') && (*c <= 'Z')) return 1;
    return 0;
}
void initializeString(char *ptr_str, unsigned arr_size){
    char *ptr_str_tmp = ptr_str;

    while (arr_size){
        *ptr_str_tmp = '\0';
        ptr_str_tmp++;
        arr_size--;
    }
}
void clearBuffer(){
    char c = NULL;

    while ((c = getchar()) != '\n' && c != EOF){ /* Clearing stdin buffer */ }
}