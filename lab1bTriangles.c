/*
Lamog, Robert
Lab 1B
09/16/2014
Testing sides to make equilateral, isosceles, or scalene triangles.
*/

#include <math.h>
#include <stdio.h>

void triangleTest();
void inputSides(double arr[]);
int triangleSidesCheck(double arr[]);
double triangleArea(double arr[]);
int triangleType(double arr[]);
void printTriangleSides(double arr[]);
void printTriangleArea(double area);
void printTriangleType(int type);

int main() {
    triangleTest();
    return 0;
}

void triangleTest() {
    char response = 'y';

    printf("Welcome. Let's test some triangles, shall we?\n");

    while ((response == 'y') || (response == 'Y')) {
        int i = 0;
        double triangleSidesArr[3] = {0.0, 0.0, 0.0};

        inputSides(triangleSidesArr);
/*        printTriangleSides(triangleSidesArr);
        printf("\n");   /**/

        if (triangleSidesCheck(triangleSidesArr) == 3) {
            printf("Success! The lengths ");
            printTriangleSides(triangleSidesArr);
            printf(" can make a");
            printTriangleType(triangleType(triangleSidesArr));
            printf(" triangle with an approximate area of ");
            printTriangleArea(triangleArea(triangleSidesArr));
            printf(".\nWould you like to try again (Y/N)?\n");
            scanf("%s", &response); 
        } else {
            printf("It is NOT possible to make a triangle with sides of length ");
            printTriangleSides(triangleSidesArr);
            printf(".\nWould you like to try again (Y/N)?\n");
            scanf("%s", &response); 
        }
    }
}

void inputSides(double arr[]) {
    int i = 0;
    double input = 0.0;

    /* i is incrementing upon successful input */
    for (i = 0; i < 3;) {
        printf("Please enter a length.\n");

        int returnSuccessful = scanf("%lf", &input);
/*        printf("%.2d\n", returnSuccessful);    /**/

        if (returnSuccessful == 1) {
            if (input > 0) {
                arr[i] = input;
                i++;
            }
/*            printf("%lf - %lf\n", input, sidesArr[i]);    /**/
            else if (arr[i] <= 0.0) {
                printf("Invalid input. Please enter an unsigned length.\n");
            } else {
                printf("Unexpected behavior. Consult a fellow programmer.\n");
                break;
            }
        }
        if (returnSuccessful < 1) {
            scanf("%*s");
            printf("Invalid input. ");
        }
    }
}

/* A triangle is possible @return 3 */
int triangleSidesCheck(double arr[]) {
    int isPossible = 0;

    if (arr[0] + arr[1] > arr[2]) isPossible++;
    if (arr[1] + arr[2] > arr[0]) isPossible++;
    if (arr[2] + arr[0] > arr[1]) isPossible++;
     
    return isPossible;
}

double triangleArea(double arr[]) {
    double s = 0.0;
    double area = 0.0;

    s = (arr[0] + arr[1] + arr[2]) / 2;
    area = sqrt(s * (s - arr[0]) * (s - arr[1]) * (s - arr[2]));
    return area;
}

/* 
@return 0 == "Scalene Triangle"
@return 1 == "Isosceles Triangle"
@return 3 == "Equilateral Triangle"
*/
int triangleType(double arr[]) {
    int type = 0;

    if (arr[0] == arr[1]) type++;
    if (arr[1] == arr[2]) type++;
    if (arr[2] == arr[0]) type++;
    return type;
}

void printTriangleSides(double arr[]) {
    int i = 0;

    printf("(");
    for (i = 0; i < 3; i++) {
        printf("%.0lf", arr[i]);
        if (i !=2) printf(", ");
    } 
    printf(")");
}

void printTriangleArea(double area) {
    printf("%.2lf", area);
}

void printTriangleType(int type) {
    if (type == 0) printf(" Scalene");
    if (type == 1) printf(" Isosceles");
    if (type == 3) printf("n Equilateral");
}

