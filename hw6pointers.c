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

void fillArray( double * begin, double * end );
int main(){
    double *arr, *arr1, *arr2;
    unsigned arr_length = 5;

    arr = malloc(arr_length * sizeof *arr);
    if (arr == NULL) die("malloc unsuccessful.");
    // printf("%p : %lf : %lu\n", &arr, *arr, sizeof *arr);
    arr1 = malloc(arr_length * sizeof *arr1);
    if (arr1 == NULL) die("malloc unsuccessful.");
    arr2 = malloc(arr_length * sizeof *arr2);
    if (arr2 == NULL) die("malloc unsuccessful.");

    fillArray(arr, arr + arr_length);
    fillArray(arr1, arr1 + arr_length);
    fillArray(arr2, arr2 + arr_length);

    show(arr, arr + arr_length);
    show(arr1, arr1 + arr_length);
    show(arr2, arr2 + arr_length);
    
    printf("sum = %lf\n", sum(arr, arr + arr_length));
    
    printf("half = ");
    half(arr, arr + arr_length);
    show(arr, arr + arr_length);
    
    printf("add = ");
    add(arr, arr + arr_length, arr1, arr2);
    show(arr, arr + arr_length);
    
    // printf("%p : %lf : %lu\n", &arr, *arr, sizeof *arr);
    free(arr);
    arr = NULL;
    free(arr1);
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
    
    return 0;
}

void show( const double * begin, const double * end ){
    printf("{");
    while (begin < end){
        printf("%lf", *begin);
        ++begin;
        if (begin < end) printf(", ");
    }
    printf("}\n");
}
double sum( const double * begin, const double * end ){
    double retVal = 0;
    
    while (begin < end){
        retVal += *begin;
        ++begin;
    }
    return retVal;
}
void half( double * begin, double * end ){
    while (begin < end){
        *begin /= 2;
        ++begin;
    }
}
void add( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin ){
    double *arr_head = resultBegin;
    unsigned i = 0;

    while (arr_head < resultEnd){
        *arr_head = *(a0Begin + i) + *(a1Begin + i);
        ++i;
        ++arr_head;
    }
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

void fillArray( double * begin, double * end ){
    double *arr_head = begin;
    unsigned i = 0;
    
    while (arr_head < end){
        *arr_head = i++;
        ++arr_head;
    }
}