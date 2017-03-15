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

void generateRandomString(char []);
void getUserInput(char []);

int main(){
    char s1[S1_SIZE] = "\0";
    char s2[S2_SIZE] = "\0";

    srand(time(NULL));
    generateRandomString(s1);

    getUserInput(s2);
    printf("%s\n", s2);

    return 0;
}

void generateRandomString(char s1[S1_SIZE]){
    unsigned i = 0;

    for (i; i < S1_SIZE; i++) {
        s1[i] = (rand() % 26) + 65;
    }
}
void getUserInput(char s2[S2_SIZE]){
    printf("Enter upper case letters A-Z (2 to 20 letters) to reset, followed by any character. e.g. XH*\n");
    s2 = fgets(s2, sizeof(s2), stdin);
}