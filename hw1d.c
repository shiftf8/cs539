// CS 539, HW 1D, Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double mass(double);

int die(const char* msg);

#define SPEED_OF_LIGHT 299792458

int main(){
    double input;
    
    printf("Input Joules: ");
    if (!scanf("%lf", &input)) die("Input failure.\n");
    printf("The equivalent mass of %eJ is %fkg.\n", input, mass(input));
    
    return 0;
}

double mass(double joules){
    double retVal;

    if (joules < 0) die("Input cannot be negative.\n");
    
    retVal = joules / pow(SPEED_OF_LIGHT, 2);

    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}