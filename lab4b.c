/*
Lamog, Robert
Lab 3B
11/04/2014
Simple letter replacement utilizing arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomString( char[], int );
int isUpperAlpha( char );
void strfilter( char[], char[], char );

int main() {
    char s1[40] = "0";
    char s2[20] = "0";
    char c = '\0';
    char userInput[50] = "0";
    unsigned int j = 0;

    randomString(s1, 40);
    // printf("%s\n", s1);
    
    printf("Let's reset some letters!\nPlease input at least 2 upper case letters to reset followed by a space and a \"reset\" character.\n");
    while (fgets(userInput, 50, stdin) != NULL) {
        if (userInput[0] == 'N' && userInput[1] == 'o') break;

        // printf("%s", userInput);
        while (isUpperAlpha(userInput[j]) && j < 20) {
            s2[j] = userInput[j];
            j++;
        }
        // printf("%s\n", s2);
        c = userInput[j + 1];
        // printf("%c / %d\n", c, j);
        if (j < 2) printf("Invalid input.\nPlease input at least 2 upper case letters to reset followed by a space and a \"reset\" character.\n");
        else {
            printf("s1 = {\"%s\"}\n", randomStr);
            printf("s2 = {\"%s\"}\n", userStr);
            printf("c = {\"%c\"}\n", resetChar);
            strfilter(s1, s2, c);
        }
        
        c = '\0';
        j = 0;
    }

    return 0;
}

void randomString( char str[], int strLength ) {
    unsigned int i = 0;
    
    srand(time(NULL));
    
    for (i; i < strLength; i++) {
        str[i] = (rand() % 26) + 65;
        // putchar(s[i]);
    }
}
int isUpperAlpha(char c) {
    if ((c >= 'A') && (c <= 'Z')) return 1;
    return 0;
}
void strfilter( char randStr[], char uStr[], char replaceChar ) {
    
}
