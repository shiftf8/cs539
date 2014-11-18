/*
Lamog, Robert
Lab 3B
11/04/2014

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void randomString();
int main() {
    randomString();
    
    return 0;
}

void randomString() {
    char s1[40] = "0";
    unsigned int i = 0;
    
    for (i; i <= 40; i++) {
        s1[i] = rand() % 26;
    }
    char x;
    while (x != EOF) putchar(x);
    
}
