// CS 539, HW 5B Arrays, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void show( const double a[], unsigned elements );
double sum( const double a[], unsigned elements );
void half( double a[], unsigned elements );
void add( double result[], const double a0[], const double a1[], unsigned elements );
void maximum( double result[], const double a0[], const double a1[], unsigned elements );
void stat( double * smallest, double * average, double * largest, const double a[], unsigned elements );
void setFib( unsigned result[], unsigned elements );
void reverse( double a[], unsigned elements );
int die( const char msg[] );

unsigned fib( unsigned n );

int main(){

    return 0;
} //int main()

void show( const double a[], unsigned elements ){
    unsigned i = 0;
    
    printf("{");
    for (i; i < elements; ++i){
        printf("%lf", a[i]);
        if (i < elements - 1) printf(", ");
    }
    printf("}\n");
}
double sum( const double a[], unsigned elements ){
    double retVal = 0;
    unsigned i = 0;
    
    for (i; i < elements; ++i) retVal += a[i];
    return retVal;
}
void half( double a[], unsigned elements ){
    unsigned i = 0;
    
    for (i; i < elements; ++i) a[i] = a[i] / 2;
}
void add( double result[], const double a0[], const double a1[], unsigned elements ){
    unsigned i = 0;
    
    for (i; i < elements; ++i) result[i] = a0[i] + a1[i];
}
void maximum( double result[], const double a0[], const double a1[], unsigned elements ){
    unsigned i = 0;
    
    for (i; i < elements; ++i){
        if (a0[i] < a1[i]) result[i] = a1[i];
        else result[i] = a0[i];
    }
}
void stat( double * smallest, double * average, double * largest, const double a[], unsigned elements ){
    double min = 0, mean = 0, max = 0;
    unsigned i = 0;
    
    if (elements == 0) die("Zero elements defined. stat() needs at least one element to examine.\n");
    
    //Initializing with first element. First make copies to manipulate, in order to maintain const double arr[].
    min = *a;
    *smallest = min;
    mean = *a;
    *average = mean;
    max = *a;
    *largest = max;

    if (elements > 1){
        for (i; i < elements; ++i){
            if (min >= a[i]){
                *smallest = a[i];
            }
            mean += a[i];
            if (max <= a[i]){
                *largest = a[i];
            }
        }

        mean = mean / elements;
        *average = mean;
    }
}
void setFib( unsigned result[], unsigned elements ){
    unsigned i = 0;
    
    for (i; i < elements; ++i) result[i] = fib(i);
}
void reverse( double a[], unsigned elements ){
    double temp = 0;
    unsigned i = 0;
    
    for (i; i < elements / 2; ++i){
        temp = a[i];
        a[i] = a[elements - 1 -i];
        a[elements - 1 -i] = temp;
    }
}
int die( const char msg[] ){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}

unsigned fib( unsigned n ){ //Subject to overflow.
    if (n == 0) return 0; //Special 0 case
    if (n == 1) return 1; //Special 1 case
    
    return fib(n - 1) + fib(n - 2);
}