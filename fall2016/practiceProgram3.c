// CS 539, Practice Program 3, Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void f();

int main() {
    f();
    
    return 0;
} //main

void f(){
    double a, b, c, area, semiPerimeter;
    
    for (;;){
        printf("Input three lengths \"a b c\".\n");
        if (!scanf("%lf %lf %lf", &a, &b, &c)) return;
        
        printf("Triangle %lf, %lf, %lf, has an area of %lf.\n", a, b, c, areaTriangle(a, b, c));
    }
}
double areaTriangle(double a, double b, double c){
    double semiPerimeter, retVal;

    if ((a + b < c) || (b + c < a) || (c + a < b)) die("These three sides cannot make a triangle.\n");

    semiPerimeter = (a + b + c) / 2;
    retVal = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

    return retVal;
}