// CS 539, HW 1A, Rob Lamog

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double hypotenuse( double side0, double side1 );

int die( const char * msg );

int main(){
    
    
    return 0;
}

double hypotenuse( double side0, double side1 ){
    double retVal;
    
    retVal = sqrt(pow( side0, 2 ) + pow( side1, 2 ));
    
    return retVal;
}

int die( const char * msg ){
    printf( "%s", msg );
    exit( EXIT_FAILURE );
}