/*
Lamog-Doiel, Robert
Lab 4B

Generate a random string of chars, length of 40.
Get user input, minimum 2 chars, maximum 20 chars.
Use a function to replace user input chars within random string to designated character.
Output formatted text.
*/

#define S1_SIZE 40
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
    Error checks to keep minimum 2 chars and maximum of 20 chars.
        Checks for valid upper case letters.
*/
void getUserInput(char [], unsigned);
int isUpperAlpha(char);

int main(){
    char s1[S1_SIZE] = "\0";
    char s2[S2_SIZE] = "\0";
    int loop_again = 0;
    char c = NULL;

    srand(time(NULL));
    generateRandomString(s1, S1_SIZE);
    printf("%s\n", s1);

    do {
        printf("Enter upper case letters A-Z (2 to 20 letters) to reset, followed by any character. e.g. XH*\n");
        getUserInput(s2, S2_SIZE);
        printf("Would you like to enter new letters to reset (Y/N)? ");
        c = getchar();
        putchar(c);
        printf("\n");
        if (c == 'Y' || c == 'y'){
            loop_again = 1;
            while ((c = getchar()) != '\n'){ /* Clearing buffer through '\n' */ }
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
void getUserInput(char str[], unsigned arr_size){
    int is_lower = 0;
    unsigned els = 0;
    char c = NULL;

    str = fgets(str, arr_size, stdin);
    while (str[els++] != '\n'){ /* Counting number of actual elements in array */
        if (isUpperAlpha(str[els] == 0) is_lower = 1; /* Check of current char in array for valid upper case letter */
    }
    if (els > 20) while ((c = getchar()) != '\n'){ /* Clearing buffer through '\n' to strip overflow */ }
    if (els < 2 || is_lower){
        printf("Invalid input.\n");
        return;
    }

    printf("%u\n%s\n", els, str);
}
int isUpperAlpha(char c){
    if ((c >= 'A') || (c <= 'Z')) return 1;
    return 0;
}