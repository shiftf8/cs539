// CS 539, HW 1A, Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double hypotenuse(double, double);

int die(const char* msg);

int main(){
    double leg1, leg2;
    
    printf("Input the length of a leg: ");
    if (!scanf("%lf", &leg1)) die("Input failure.\n");
    printf("Input the length of a leg: ");
    if (!scanf("%lf", &leg2)) die("Input failure.\n");
    printf("The hypotenuse of %f and %f is %f.\n", leg1, leg2, hypotenuse(leg1, leg2));
    
    return 0;
}

double hypotenuse(double side0, double side1){
    double retVal;
    
    if ((side0 < 0) || (side1 < 0)) die("Legs cannot be negative.\n");
    
    retVal = sqrt(pow(side0, 2) + pow(side1, 2));
    
    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}