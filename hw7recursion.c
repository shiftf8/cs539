// CS 539, HW 7, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void countdown( unsigned seconds );
unsigned add( unsigned a, unsigned b );
unsigned multiply( unsigned a, unsigned b );
unsigned power( unsigned a, unsigned b );

int die( const char * msg );

int main(){
    countdown(5);
    printf("\n");
    
    printf("%u\n", add(3, 7));
    printf("\n");
    
    printf("%u\n", multiply(3, 7));
    printf("\n");
    
    printf("%u\n", power(3, 7));
    printf("\n");
    
    return 0;
} //main

void countdown( unsigned seconds ){
    if (seconds > 0){
        printf("%u...\n", seconds--);
        countdown(seconds);
    } else
        printf("Blast off!\n");
}
unsigned add( unsigned a, unsigned b ){
    if (a > 0) add(--a, ++b);
    else return b;
}
unsigned multiply( unsigned a, unsigned b ){
    if (b == 0) return 0;
    return add(a, multiply(a, --b));
}
unsigned power( unsigned a, unsigned b ){
    if (b == 0) return 1;
    return multiply(a, power(a, --b));
}

int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}