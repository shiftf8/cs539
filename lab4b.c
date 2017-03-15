/*
Lamog-Doiel, Robert
Lab 4B

Generate a random string of chars, length of 40.
Get user input, minimum 2 chars, maximum 20 chars.
Use a function to replace user input chars within random string to designated character.
Output formatted text.
*/

#define S1SIZE 41
#define S2SIZE 21

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateStrings1(char []);
void getUserInput(char []);

int main(){
    char s1[S1SIZE] = "\0";
    char s2[S2SIZE] = "\0";

    generateStrings1(s1);
    // printf("%s\n", s1);
    getUserInput();

    return 0;
}

void generateStrings1(char s1[S1SIZE]){
    unsigned i = 0;

    srand(time(NULL));
    for (i; i < 40; i++) {
        s1[i] = (rand() % 26) + 65;
    }
}
void getUserInput(char s2[S2SIZE]){

}