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

int main(){
    double a[] = {1.1, 2.2, 3.3, 4.4};
    double b[] = {2, 4, 6};
    double c[] = {1, 2, 3};
    double result[3] = {};
    unsigned i = 0;
    unsigned elements = 3;
    
    show(a, 4);
    
    printf("sum = %lf\n", sum(a, 4));
    printf("sum = %lf\n", sum(b, 3));
    
    half(a, elements);
    printf("half = {");
    for (i; i < elements; ++i){
        printf("%lf", a[i]);
        if (i < elements - 1) printf(", ");
    }
    printf("}\n");
    
    add(result, b, c, elements);
    printf("add = {");
    for (i; i < elements; ++i){
        printf("%lf", result[i]);
        if (i < elements - 1) printf(", ");
    }
    printf("}\n");
    
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
    
    // i = 0;
    // for (i; i < elements; ++i) printf("%lf\n", result[i]);
}
void maximum( double result[], const double a0[], const double a1[], unsigned elements ){
    
}
void stat( double * smallest, double * average, double * largest, const double a[], unsigned elements ){
    
}
void setFib( unsigned result[], unsigned elements ){
    
}
void reverse( double a[], unsigned elements ){
    
}
int die( const char msg[] ){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}