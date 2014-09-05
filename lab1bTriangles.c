/*
Lamog, Robert
Lab 1B
09/16/2014
Testing sides to make triangles.
*/

#include <math.h>
#include <stdio.h>

int main() {
    long sidesArr[3] = {0};
    char toContinue = NULL;
    long input = 0;
    int i = 0;

    while (input != 'N'){
        printf("Please enter the length of a side of a triangle: ");
        scanf("%ld", &input);
        if (input > 0) {
            sidesArr[i] = input;
            i++;
        }
        else printf("Your input is invalid. Please enter an unsigned integer as the length of your side.");

        if (i == 3) {
            /* output test results, reset 'i' and ask to terminate program */
            i = 0;
            printf("Would you like to test another triangle? Type \'N\' to exit test.\n");
            scanf("%c", &toContinue);
        }
    }

    return 0;
}
