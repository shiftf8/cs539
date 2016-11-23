// CS 539, Lab Struct, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

typedef struct AC {
    char airportCode[3];
    double ticketPrice;
    unsigned day; //[0, 6] Sun, ... , Sat
} AC;

void input(AC * ac);
void inflate(AC * ac);
void output(const AC * ac);

int main(){
    AC foo;
    
    input(&foo);
    inflate(&foo);
    inflate(&foo);
    output(&foo);
    
    return 0;
}
void input(AC * ac){
    scanf("%c%c%c %lf %u", &ac->airportCode[0], &ac->airportCode[1], &ac->airportCode[2], &ac->ticketPrice, &ac->day);
}
void inflate(AC * ac){
    ac->ticketPrice *= 1.1;
}
void output(const AC * ac){
    printf("%s %lf %u\n", ac->airportCode, ac->ticketPrice, ac->day);
}