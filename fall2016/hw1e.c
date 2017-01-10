// CS 539, HW 1E, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

unsigned chickens(unsigned, unsigned);
unsigned goats(unsigned, unsigned);

int die(const char* msg);

int main(){
    unsigned input1, input2;
    
    printf("Input the number of heads: ");
    if (!scanf("%u", &input1)) die("Input failure.\n");
    printf("Input the number of legs: ");
    if (!scanf("%u", &input2)) die("Input failure.\n");
    printf("That's %u chickens and %u goats.\n", chickens(input1, input2), goats(input1, input2));
    
    return 0;
}

unsigned chickens(unsigned heads, unsigned legs){
    unsigned retVal, testGoatVal;

    if (legs % 2 != 0) die("It is not possible to have an odd number of legs.\n");
    if (legs < heads * 2) die("Anatomically impossible.\n"); //Too few legs
    if (legs > heads * 4) die("Anatomically impossible.\n"); //Too many legs
    
    retVal = (2 * heads) - (legs / 2);
    testGoatVal = (legs / 2) - heads;
    
    if ((heads == retVal + testGoatVal) && (legs == (2 * retVal) + (4 * testGoatVal))) return retVal;
    
    die("Anatomically impossible.\n"); //If we made it this far, it's reasonable to assume a real solution is not possible.
}
unsigned goats(unsigned heads, unsigned legs){
    unsigned retVal, testChickenVal;
    
    if (legs % 2 != 0) die("It is not possible to have an odd number of legs.\n");
    if (legs < heads * 2) die("Anatomically impossible.\n"); //Too few legs
    if (legs > heads * 4) die("Anatomically impossible.\n"); //Too many legs
    
    retVal = (legs / 2) - heads;
    testChickenVal = (2 * heads) - (legs / 2);
    
    if ((heads == testChickenVal + retVal) && (legs == (2 * testChickenVal) + (4 * retVal))) return retVal;

    die("Anatomically impossible.\n"); //If we made it this far, it's reasonable to assume a real solution is not possible.
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}