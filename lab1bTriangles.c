/*
Lamog, Robert
Lab 1B
09/16/2014
Testing sides to make equilateral, isosceles, or scalene triangles.
*/

#include <math.h>
#include <stdio.h>

int sidesCheck(double arr[], int size);

int main() {
    int i = 0;
    double input = 0.0;
    double triangleSidesArr[3] = {0.0, 0.0, 0.0};

    for (i = 0; i < 3;) {
        printf("Please enter a length.\n");

        int returnSuccessful = scanf("%lf", &input);
/*        printf("%.2d\n", returnSuccessful);    /**/

        if (returnSuccessful == 1) {
            if (input > 0) {
                triangleSidesArr[i] = input;
                i++;
            }
/*            printf("%lf - %lf\n", input, sidesArr[i]);    /**/
            else if (triangleSidesArr[i] <= 0.0) {
                printf("Invalid input. Please enter an unsigned length.\n");
            } else {
                printf("Something weird happened.");
                break;
            }
        }
        if (returnSuccessful < 1) {
            scanf("%*s");
            printf("Invalid input. Please enter a length.\n");
        }
    }

/*    printf("Sides array set to ");
    for (i = 0; i < 3; i++) {
        printf("[%lf]", triangleSidesArr[i]);
        if (i !=2) printf(", ");
        else printf(".\n");
    }    /**/

    if (sidesCheck(triangleSidesArr, 3)) printf("Success! The lengths entered can make a triangle.");
 
    return 0;
}

int sidesCheck(double arr[], int size) {
    int isPossible = 0;
    int i = 0;

    for (i = 0; i < size; i++) {
    }
    return isPossible;
}
