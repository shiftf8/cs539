// CS 539, HW 1C, Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double areaTriangle(double, double, double);

int die(const char* msg);

int main(){
    double input1, input2, input3;
    
    printf("Input the length of a side: ");
    if (!scanf("%lf", &input1)) die("Input failure.\n");
    printf("Input the length of a side: ");
    if (!scanf("%lf", &input2)) die("Input failure.\n");
    printf("Input the length of a side: ");
    if (!scanf("%lf", &input3)) die("Input failure.\n");
    printf("The area of a triangle with sides %f, %f, %f, is %f.\n", input1, input2, input3, areaTriangle(input1, input2, input3));
    
    return 0;
}

double areaTriangle(double a, double b, double c){
    double semiPerimeter, retVal;

    semiPerimeter = (a + b + c) / 2;
    if ((a + b < c) || (b + c < a) || (c + a < b)) die("These three sides cannot make a triangle.\n");
    
    retVal = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}