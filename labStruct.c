// CS 539, Lab Struct, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

typedef struct AC {
    char airportCode[4];
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
    scanf("%3s %lf %u", ac->airportCode, &ac->ticketPrice, &ac->day); //Dangerous, no input validation.
}
void inflate(AC * ac){
    ac->ticketPrice *= 1.1;
}
void output(const AC * ac){
    printf("%s %lf %u\n", ac->airportCode, ac->ticketPrice, ac->day);
}