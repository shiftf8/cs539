// CS 539, Practice Program 2, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

char grade( unsigned score );

int main() {
    
    return 0;
} //main

char grade( unsigned score ){
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}