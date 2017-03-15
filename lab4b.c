/*
Lamog-Doiel, Robert
Lab 4B

Generate a random string of chars, length of 40.
Get user input, minimum 2 chars, maximum 20 chars.
Use a function to replace user input chars within random string to designated character.
Output formatted text.
*/

#define S1_SIZE 40
#define S2_SIZE 22

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomString(char [], unsigned);
void getUserInput(char [], unsigned);

int main(){
    char s1[S1_SIZE] = "\0";
    char s2[S2_SIZE] = "\0";

    srand(time(NULL));
    generateRandomString(s1, S1_SIZE);
    printf("%s\n", s1);

    getUserInput(s2, S2_SIZE);
    printf("%s\n", s2);

    return 0;
}

void generateRandomString(char str[], unsigned arr_size){
    unsigned i = 0;

    for (i; i < arr_size; ++i) {
        str[i] = (rand() % 26) + 65;
    }
}
void getUserInput(char str[], unsigned arr_size){
    printf("Enter upper case letters A-Z (2 to 20 letters) to reset, followed by any character. e.g. XH*\n");
    str = fgets(str, arr_size, stdin);
}