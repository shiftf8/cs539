//CS 539, At home practice midterm 2 speed programming for study. 1 hour started already. Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double areaTriangle( double );
int die ( const char * );

int main() {
    double input;
    
    while (scanf("%lf", &input)){
        if (input < 0) die("Not a positive number");
        printf("Area: %f\n", areaTriangle(input));
    }
    
    return 0;
}
double areaTriangle( double length ){
    return (sqrt(3) / 4) * pow(length, 2);
}
int die( const char * msg ){
    printf("Fatal error: %s.\n", msg);
    exit(EXIT_FAILURE);
}