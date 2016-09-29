// CS 539, HW 5B Array, Rob Lamog

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
    double m[] = {1.1, 2.2, 3.3, 4.4};
    double n[] = {2, 4, 6};
    double p[] = {1, 2, 50};
    double q[] = {10, 20, 30};
    double r[3] = {};
    unsigned k[7] = {};
    double s = 0, a = 0, l = 0;
    unsigned e = 3;
    unsigned i = 0;
    
    // show(m, 4);
    
    // printf("sum = %lf\n", sum(m, 4));
    // printf("sum = %lf\n", sum(n, 3));
    
    // half(m, e);
    // printf("half = ");
    // show(m, e);

    // add(r, p, q, e);
    // printf("add = ");
    // show(r, e);

    // maximum(r, p, q, e);
    // printf("maximum = ");
    // show(r, e);

    // stat(&s, &a, &l, m, e);
    // printf("smallest = %lf, average = %lf, largest = %lf of ", s, a, l);
    // show(m, e);
    
    // setFib(k, 7);
    // printf("{");
    // for (i; i < 7; ++i){
    //     printf("%u", k[i]);
    //     if (i < 6) printf(", ");
    // }
    // printf("}\n");
    
    reverse(n, e);

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
    unsigned i = 0;
    
    // for (i; i < elements; ++i) 
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