// CS 539, HW 6, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void show( const double * begin, const double * end );
double sum( const double * begin, const double * end );
void half( double * begin, double * end );
void add( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin );
void maximum( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin );
void stat( double * smallest, double * average, double * largest, const double * begin, const double * end );
void setFib( unsigned * begin, unsigned * end );
void reverse( double * begin, double * end );
int die( const char * msg );

int main(){
    double *arr;
    double *arr_start;
    unsigned arr_length = 11;
    unsigned i = 0;

    arr = malloc(arr_length * sizeof(*arr));
    if (arr == NULL) die("malloc unsuccessful.");

    arr_start = arr; //Important to remember where the array starts.
    while (arr + arr_length != arr++) *arr = i++;

    show(arr, arr + arr_length);
    
    sum(arr, arr + arr_length);
    
    free(arr);
    
    return 0;
}

void show( const double * begin, const double * end ){
    printf("{");
    while (end != begin++){
        printf("%lf", *begin);
        if (begin < end) printf(", ");
    }
    printf("}\n");
}
double sum( const double * begin, const double * end ){
    double retVal = 0;
    
    while (end != begin++){
        retVal += *begin;
    }
    return retVal;
}
void half( double * begin, double * end ){
    
}
void add( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin ){
    
}
void maximum( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin ){
    
}
void stat( double * smallest, double * average, double * largest, const double * begin, const double * end ){
    
}
void setFib( unsigned * begin, unsigned * end ){
    
}
void reverse( double * begin, double * end ){
    
}
int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}