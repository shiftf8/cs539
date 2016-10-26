// CS 539, HW 7, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void countdown( unsigned seconds );
unsigned add( unsigned a, unsigned b );
unsigned multiply( unsigned a, unsigned b );

int die( const char * msg );

int main(){
    countdown(5);
    printf("\n");
    
    printf("%u\n", add(3, 7));
    printf("\n");
    
    printf("%u\n", multiply(3, 7));
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
    if (a > 0){
        add(--a, ++b);
    } else
        return b;
}
unsigned multiply( unsigned a, unsigned b ){
    static unsigned product = 0;
    
    // if (a > 0){
    //     product = add(a, b);
    //     multiply(--a,)
    // }
    return 0;
}

int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}