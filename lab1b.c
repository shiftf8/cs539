/*
Lamog, Robert
Lab 1B
02/21/2017
Testing sides to make equilateral, isosceles, or scalene triangles.
*/

#include <math.h>
#include <stdio.h>

int is_valid_triangle(int, int, int);
double area_of_triangle(int, int, int);

int main() {

    printf("%i\n", is_valid_triangle(3, 4, 5));
    printf("%f\n", area_of_triangle(3, 4, 5));

    return 0;
}
/*
    Return 1 if the three inputs can make a valid triangle.
    Return 0 if NOT a valid triangle.
*/
int is_valid_triangle(int a, int b, int c){
    if (a + b > c
        && b + c > a
        && c + a > b) return 1;
    return 0;
}
double area_of_triangle(int a, int b, int c){
    double semiPerimeter, areaOfTriangle;

    semiPerimeter = (a + b + c) / 2.0;
    areaOfTriangle = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

    return areaOfTriangle;
}