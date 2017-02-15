/*
Lamog-Doiel, Robert
Lab 1B
02/21/2017
Testing sides to make equilateral, isosceles, or scalene triangles.
*/

#include <math.h>
#include <stdio.h>

int is_valid_triangle(unsigned, unsigned, unsigned);
double area_of_triangle(unsigned, unsigned, unsigned);
void input_triangle();

int main() {
    char inputChar;
    int loopAgain;

    do {
        printf("Enter 3 sides of a triangle (a b c): ");
        input_triangle();
        printf("Would you like to enter three new sides (Y or N)? ");
        inputChar = getchar(); /* Attempting to flush newline char left over from scanf inside input_triangle() */
        inputChar = getchar();
        if (inputChar == 'Y' || inputChar == 'y') loopAgain = 1;
        else loopAgain = 0;
    } while (loopAgain);

    return 0;
}
/*
    Return 1 if the three inputs can make a valid triangle.
    Return 0 if NOT a valid triangle.
*/
int is_valid_triangle(unsigned a, unsigned b, unsigned c){
    if (a + b > c
        && b + c > a
        && c + a > b) return 1;
    return 0;
}
double area_of_triangle(unsigned a, unsigned b, unsigned c){
    double semiPerimeter, areaOfTriangle;

    semiPerimeter = (a + b + c) / 2.0;
    areaOfTriangle = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

    return areaOfTriangle;
}
void input_triangle(){
    unsigned side1, side2, side3;

    if (scanf("%u %u %u", &side1, &side2, &side3) == 3){
        if (is_valid_triangle(side1, side2, side3)){
            printf("Sides %u %u %u make a", side1, side2, side3);
            if (side1 == side2 && side1 == side3) printf("n equilateral ");
            else if (side1 == side2 || side1 == side3) printf(" isosceles ");
            else printf(" scalene ");
            printf("triangle with an area of %f\n", area_of_triangle(side1, side2, side3));
        } else {
            printf("Sides %u %u %u does NOT seem to constitute a valid triangle.\n", side1, side2, side3);
        }
    }
}