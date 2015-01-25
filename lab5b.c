/*
Lamog, Robert
Lab 3B
11/04/2014
Simple letter replacement utilizing pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char randUpperChar();
int isUpperAlpha( char );
int isAlphaNum( char );
void strfilter( char *, char *, char );

int main() {
    char s1[41] = "\0";
    char s2[21] = "\0";
    char c = '\0';
    char userInput[50] = "\0";
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    srand(time(NULL)); //Generate random upper case array string
    for (i; i < 40; i++) {
        s1[i] = randUpperChar();
    }
    // printf("%s\n", s1);
    
    printf("Let's reset some letters!\nPlease input at least 2 upper case letters to reset followed by a space and a \"reset\" character.\n");
    while (fgets(userInput, 20, stdin) != NULL) {
        if (userInput[0] == 'N' && userInput[1] == 'o') break;

        // printf("%s", userInput);
        while (isUpperAlpha(userInput[j]) && j < 20) {
            s2[j] = userInput[j];
            j++;
        }
        // printf("%s\n", s2);
        c = userInput[j + 1];
        // printf("%c / %d\n", c, j);
        if (j < 2 || !isAlphaNum(c)) printf("Invalid input.\nPlease input at least 2 upper case letters to reset followed by a space and a \"reset\" character.\n");
        else {
            printf("s1 = {\"%s\"}\n", s1);
            printf("s2 = {\"%s\"}\n", s2);
            printf("c = {\"%c\"}\n", c);
            strfilter(s1, s2, c);
        }
        
        for (k; k < 20; k++) s2[k] = '\0';
        c = '\0';
        j = 0;
        k = 0;
    }

    return 0;
}

char randUpperChar() {
    char alpha = '0';

    while (!isUpperAlpha(alpha)) {
        alpha = (rand() % 26) + 65;
    }
    return alpha;
}
int isUpperAlpha( char c ) {
    if ((c >= 'A') && (c <= 'Z')) return 1;
    return 0;
}
int isAlphaNum( char c ){
    if ((c >= '!') && (c <= '~')) return 1;
    return 0;
}
void strfilter( char randStr[], char uStr[], char resetChar ) {
    char filteredStr[41] = "\0";
    unsigned int i = 0;
    unsigned int arrLength = 0;
    
    while (isUpperAlpha(randStr[i])) {
        filteredStr[i] = randStr[i];

        while (isUpperAlpha(uStr[arrLength])) {
            if (randStr[i] == uStr[arrLength]) filteredStr[i] = resetChar;
            
            arrLength++;
        }
        
        i++;
        arrLength = 0;
    }
    // printf("%d\n", arrLength);

    printf("filtered s1 = {\"%s\"}\n", filteredStr);
    printf("Please input at least 2 upper case letters to reset followed by a space and a \"reset\" character.\n");
    printf("Or type \"No\" to quit.\n");
}
