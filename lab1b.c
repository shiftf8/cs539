/*
Lamog-Doiel, Robert
Lab 1B
02/21/2017
Testing sides to make equilateral, isosceles, or scalene triangles.
*/

#include <math.h>
#include <stdio.h>

/*
    Return 1 if the three inputs can make a valid non-degenerate triangle.
    Return 0 if NOT a valid triangle.
*/
int is_valid_triangle(unsigned, unsigned, unsigned);
/*
    Area of triangle calculated via semiperimeter and three sides.
    <math.h> dependent. sqrt()
*/
double area_of_triangle(unsigned, unsigned, unsigned);
/*
    Test first three valid inputs for a valid triangle,
    print the triangle type and area of the triangle,
    and ask if user would like to test three new sides (Y/N), NOT case dependent.
*/
void test_input_triangle();

int main(){
    int inputChar, loopAgain;

    do {
        printf("Enter 3 sides to test for a triangle (a b c): ");
        test_input_triangle();
        printf("Would you like to enter three new sides (Y/N)? ");
        inputChar = getchar();
        if (inputChar == 'Y' || inputChar == 'y') loopAgain = 1;
        else loopAgain = 0;
        /* printf("%c\n", inputChar); */
    } while (loopAgain);

    return 0;
}

int is_valid_triangle(unsigned s1, unsigned s2, unsigned s3){
    if (s1 + s2 > s3
        && s2 + s3 > s1
        && s3 + s1 > s2) return 1;
    return 0;
}
double area_of_triangle(unsigned s1, unsigned s2, unsigned s3){
    double semiPerimeter, areaOfTriangle;

    semiPerimeter = (s1 + s2 + s3) / 2.0;
    areaOfTriangle = sqrt(semiPerimeter * (semiPerimeter - s1) * (semiPerimeter - s2) * (semiPerimeter - s3));

    return areaOfTriangle;
}
void test_input_triangle(){
    unsigned side1, side2, side3;
    int isNewLine;

    if (scanf("%u %u %u", &side1, &side2, &side3) == 3){
        /* printf("%d %d %d\n", side1, side2, side3); */
        if (is_valid_triangle(side1, side2, side3)){
            printf("%u, %u, and %u make a", side1, side2, side3);
            if (side1 == side2 && side1 == side3) printf("n EQUILATERAL ");
            else if (side1 == side2 || side2 == side3 || side3 == side1) printf("n ISOSCELES ");
            else printf(" SCALENE ");
            printf("triangle with an approximate area of %f.\n", area_of_triangle(side1, side2, side3));
        } else {
            printf("%d, %d, and %d do NOT seem to constitute a valid triangle.\n", side1, side2, side3);
        }
    } else printf("Invalid entry.\n");

    while (isNewLine = getchar() != '\n'); /* Flushing buffer stream through newline char. */
}