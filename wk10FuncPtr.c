/*
   function pointer
   f0 with no parens means a pointer to the function f0
   f0(x) means to call f & get the returned value
   
   f  pointer to a function that takes a double & returns double
   *f a function that takes a double & returns a double
   *f( double x)    double
   
   double  (*f)( double x)



*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int die( const char * msg );
double f0( double x );
double f1( double x );
double f2( double x );
double f3( double x );

void table( double x0, double deltaX, unsigned rows,
            double (*f)( double x));

int main(){
   table( 5, .5, 10, sqrt );
} // main

int die( const char * msg ){
   printf( "Fatal error: %s\n", msg );
   exit( EXIT_FAILURE );
} // die

double f0( double x ) {return x*x*x;}
double f1( double x );
double f2( double x );
double f3( double x );

void table( double x0, double deltaX, unsigned rows, double (*f)( double x) ){
   unsigned r = 0;
   
   for(  r;  r < rows;  r++  ){
      double x = x0 + r*deltaX;
      double y = (*f)(x);
      printf( "%g:  %g\n", x, y );
   }
} // table