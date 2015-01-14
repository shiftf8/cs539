/*
Lamog, Robert
Lab 3B
11/04/2014
Simple letter replacement utilizing arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isUpperAlphaChecker( char[], unsigned int );
int randomStr( char[] );
void strfilters( char[], char[], char );
void output( char[], char[], char, unsigned int );

int main() {
    char s1[40] = "0";
    char s2[20] = "0";
    char replace = '\0';
    unsigned int j = 0;
    
    s1[0] = randomStr(s1);
    
    printf("Let's reset some letters. Please input at least two upper case letters to reset: ");
    while (gets(s2) != EOF) {
//        if (isUpperAlphaChecker(s2, sizeof))
    }

    return 0;
}
int isUpperAlphaChecker( char userStr[], unsigned int user_response_size ) {
    unsigned int i = 0;
    
    for (i; i < user_response_size; i++) {
        if (!(userStr[i] >= 'A') && !(userStr[i] <= 'Z')) return 0;
    }
    return 1;
}
int randomStr( char s[] ) {
    unsigned int i = 0;
    
    for (i; i < 40; i++) {
        s[i] = (rand() % 26) + 65;
        // putchar(s[i]);
    }
    return s[0];
}
void strfilters( char randomStr[], char userStr[], char replaceChar ) {
    
}
void output( char randomStr[], char userStr[], char replaceChar, unsigned int user_response_size ) {
    unsigned i = 0, j = 0;
    
    for (i; i < 40; i++) {
        randomStr[i];
    }
    for (j; j < user_response_size; j++) {
        userStr[i];
    }
    printf("s1 = {\"%s\"}\n", randomStr);
    printf("s2 = {\"%s\"}\n", userStr);
    printf("c = {\"%c\"}\n", replaceChar);
}
