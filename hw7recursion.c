// CS 539, HW 7, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

int die( const char * msg );

int main(){
    
    return 0;
} //main

int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}