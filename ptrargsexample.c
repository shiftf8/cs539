/*
    C++ changes caller's args: reference parameters
    C   changes caller's args: pointer parameters
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int die( const char * msg );
void minimum( double * a, double * b );
void minMax( double * min, double * max, double a, double b );

int main(){
    double x=7, y=3;
    double * p = &x;
    
    printf( "%f\n", *&*&*p );
    minimum( &x, &y );
    printf( "x y == %f %f\n", x, y );
    double smaller, larger;
    x = 10, y = -10;
    minMax( &smaller, &larger, x, y );
    printf( "smaller is %f, larger is %f\n", smaller, larger );
} // main

int die( const char * msg ){
    printf( "Fatal error: %s\n", msg );
    exit( EXIT_FAILURE );
} // die
void minimum( double * a, double * b ){
    if( *a < *b ) *a = 0;
    else *b = 0;
} // minimum
void minMax( double * min, double * max, double a, double b ){
    if( a < b ){
        *min = a;
        *max = b;
    }else{
        *min = b;
        *max = a;
    }
}