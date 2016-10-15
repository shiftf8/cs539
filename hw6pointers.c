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

void fillArraySequentially( double * begin, double * end );
void fillArrayRandomly( double * begin, double * end );
void fillUnsignedArraySequentially( unsigned * begin, unsigned * end );
unsigned fib( unsigned n );
void showUnsigned( const unsigned * begin, const unsigned * end );

int main(){
    /*
    * Change size for ALL tests here.
    */
    unsigned set_size = 7;

    /*
    * Initializing main variables.
    */
    double *arr, *arr1, *arr2;
    unsigned *uarr;
    double szero = 0, azero = 0, lzero = 0; //An address for pointers s (smallest), a (average), l (largest), to point to for stat().
    double *s = &szero, *a = &azero, *l = &lzero; //It's important to point to someplace that is defined.
    srand(time(NULL)); //Using srand() to seed pseudo random numbers for fillArrayRandomly().

    /*
    * Building test arrays.
    */
    arr = malloc(set_size * sizeof *arr);
    if (arr == NULL) die("malloc unsuccessful.");
    // printf("%p : %lf : %lu\n", &arr, *arr, sizeof *arr);
    arr1 = malloc(set_size * sizeof *arr1);
    if (arr1 == NULL) die("malloc unsuccessful.");
    arr2 = malloc(set_size * sizeof *arr2);
    if (arr2 == NULL) die("malloc unsuccessful.");
    uarr = malloc(set_size * sizeof *uarr);
    if (uarr == NULL) die("malloc unsuccessful.");

    /*
    * Filling test arrays with something worth manipulating.
    */
    fillArraySequentially(arr, arr + set_size);
    // fillArrayRandomly(arr, arr + set_size);
    fillArraySequentially(arr1, arr1 + set_size);
    // fillArrayRandomly(arr1, arr1 + set_size);
    // fillArraySequentially(arr2, arr2 + set_size);
    fillArrayRandomly(arr2, arr2 + set_size);
    fillUnsignedArraySequentially(uarr, uarr + set_size); //Special unsigned array for setfib().
    // printf("%lf\n", *(arr1 + (set_size - 1)));

    /*
    * Printing initialized arrays with show() and custom showUnsigned().
    */
    show(arr, arr + set_size);
    show(arr1, arr1 + set_size);
    show(arr2, arr2 + set_size);
    showUnsigned(uarr, uarr + set_size);
    printf("\n");
    
    /*
    * Running tests.
    */
    printf("sum = %lf\n", sum(arr, arr + set_size));
    
    printf("half = ");
    half(arr, arr + set_size);
    show(arr, arr + set_size);
    
    printf("add = ");
    add(arr, arr + set_size, arr1, arr2);
    show(arr, arr + set_size);

    printf("maximum = ");
    maximum(arr, arr + set_size, arr1, arr2);
    show(arr, arr + set_size);
    
    stat(s, a, l, arr, arr + set_size);
    printf("smallest = %lf, average = %lf, largest = %lf of ", *s, *a, *l);
    show(arr, arr + set_size);
    
    printf("setFib = ");
    setFib(uarr, uarr + set_size);
    showUnsigned(uarr, uarr + set_size); //Utilizing custom showUnsigned(). Same as show(), except this function prints unsigned arrays instead of double arrays.
    
    printf("reverse = ");
    reverse(arr, arr + set_size);
    show(arr, arr + set_size);

    /*
    * It's important to free allocated memory and manage pointers safely.
    */
    free(arr);
    arr = NULL;
    free(arr1);
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
    free(uarr);
    uarr = NULL;
    
    s = NULL;
    a = NULL;
    l = NULL;
    
    return 0;
} //main

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
    unsigned i = 0;

    // printf("%lf / %lf : %lf", *(a0Begin + i), *(a1Begin + i), (*(a0Begin + i) + *(a1Begin + i)));
    while (resultBegin < resultEnd){
        *resultBegin = *(a0Begin + i) + *(a1Begin + i);
        ++i;
        ++resultBegin;
    }
}
void maximum( double * resultBegin, double * resultEnd, const double *a0Begin, const double * a1Begin ){
    unsigned i = 0;
    
    while (resultBegin < resultEnd){
        if (*(a0Begin + i) < *(a1Begin + i)) *resultBegin = *(a1Begin + i);
        else *resultBegin = *(a0Begin + i);
        ++i;
        ++resultBegin;
    }
}
void stat( double * smallest, double * average, double * largest, const double * begin, const double * end ){
    unsigned elements = end - begin;

    if (begin == end) die("Zero elements defined. stat() needs at least one element to examine."); //Be wary of dying before the rest of your test code can manage.
    
    //Initializing with first element.
    *smallest = *begin;
    *largest = *begin;

    while (begin < end){ //In this case, while loop will always run at least once. Affording *average to be initialized properly.
        if (*smallest >= *begin) *smallest = *begin;
        *average += *begin;
        if (*largest <= *begin) *largest = *begin;
        ++begin;
    }

    *average = *average / elements;
}
void setFib( unsigned * begin, unsigned * end ){
    while (begin < end){
        *begin = fib(*begin);
        ++begin;
    }
}
void reverse( double * begin, double * end ){
    double temp = 0;
    unsigned elements = end - begin;
    unsigned i = 0;
    
    // printf("%u\n", i);
    for (i; i < elements / 2; ++i){
        temp = *(begin + i);
        *(begin + i) = *(begin + (elements - 1 - i));
        *(begin + (elements - 1 - i)) = temp;
    }
}
int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}

void fillArraySequentially( double * begin, double * end ){ //Range [0++]
    unsigned i = 0;
    
    while (begin < end){
        *begin = i++;
        ++begin;
    }
}
void fillArrayRandomly( double * begin, double * end ){ //Range [0-9]
    while (begin < end){
        *begin = rand() % 10;
        // *begin = rand() / (RAND_MAX / (10.0));
        ++begin;
    }
}
void fillUnsignedArraySequentially( unsigned * begin, unsigned * end ){ //Range [0++]
    unsigned i = 0;
    
    while (begin < end){
        *begin = i++;
        ++begin;
    }
}
unsigned fib( unsigned n ){
    if (n == 0) return 0; //Special 0 case
    if (n == 1) return 1; //Special 1 case
    
    return fib(n - 1) + fib(n - 2);
}
void showUnsigned( const unsigned * begin, const unsigned * end ){
    printf("{");
    while (begin < end){
        printf("%u", *begin);
        ++begin;
        if (begin < end) printf(", ");
    }
    printf("}\n");
}