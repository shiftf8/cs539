// CS 539, HW 1B, Rob Lamog

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
    printf("That's %u chickens and %u goats.\n", chickens(unsigned, unsigned), goats(unsigned, unsigned));
    
    return 0;
}

unsigned chickens(unsigned heads, unsigned legs){
    unsigned retVal;
    H = C + G
    L = 2C + 4G
    C = 2H - L/2
    G = L/2 - H
    return retVal;
}
unsigned goats(unsigned heads, unsigned legs){
    unsigned retVal;

    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}