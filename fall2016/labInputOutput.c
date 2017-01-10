//CS 539, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

int main(){
    double x, y;
    
    printf("Input two numbers to add: ");
    while (scanf("%lf %lf", &x, &y)) printf("%f\n", x + y);
    
    return 0;
}