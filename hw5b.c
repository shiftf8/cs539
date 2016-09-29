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
    double m[] = {1.1, 2.2, 3.3, 4.4};
    double n[] = {2, 4, 6};
    double p[] = {1, 2, 50};
    double q[] = {10, 20, 30};
    double r[3] = {};
    double *smallest, *average, *largest;
    unsigned i = 0;
    unsigned e = 3;
    
    show(m, 4);
    
    // printf("sum = %lf\n", sum(m, 4));
    // printf("sum = %lf\n", sum(n, 3));
    
    // half(m, e);
    // printf("half = {");
    // for (i; i < e; ++i){
    //     printf("%lf", m[i]);
    //     if (i < e - 1) printf(", ");
    // }
    // printf("}\n");
    
    // i = 0;
    // add(r, p, q, e);
    // printf("add = {");
    // for (i; i < e; ++i){
    //     printf("%lf", r[i]);
    //     if (i < e - 1) printf(", ");
    // }
    // printf("}\n");
    
    // i = 0;
    // maximum(r, p, q, e);
    // printf("maximum = {");
    // for (i; i < e; ++i){
    //     printf("%lf", r[i]);
    //     if (i < e - 1) printf(", ");
    // }
    // printf("}\n");
    
    i = 0;
    stat(smallest, average, largest, m, e);
    // printf("smallest = %lf, average = %lf, largest = %lf of ", *smallest, *average, *largest);
    show(m, e);

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
    
    //Initializing with first element.
    min = *a;
    smallest = &min;
    // printf("a == %p : %lf\nmin == %p : %lf\nsmallest == %p : %lf\n", &a, *a, &min, min, &smallest, *smallest);
    mean = *a;
    average = &mean;
    max = *a;
    largest = &max;

    // if (elements > 1){
    //     for (i; i < elements; ++i){
    //         if (min >= a[i]){
    //             min = *(a + i);
    //             smallest = &min;
    //         }
    //         mean += a[i];
    //         if (max <= a[i]){
    //             max = *(a + i);
    //             largest = &max;
    //         }
    //     }

    //     mean = mean / elements;
    //     average = &mean;
    // }
}
void setFib( unsigned result[], unsigned elements ){
    
}
void reverse( double a[], unsigned elements ){
    
}
int die( const char msg[] ){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}