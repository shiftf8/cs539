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
    double *arr_head;
    unsigned arr_length = 3;
    double i = 0;

    arr = malloc(arr_length * sizeof *arr);
    if (arr == NULL) die("malloc unsuccessful.");
    printf("%p : %lf : %lu\n", &arr, *arr, sizeof *arr);

    arr_head = arr; //Important to utilize separate pointer iterator instead of trying to constantly remember where original pointer came from.
    // printf("%p / %p\n", &arr_head, &arr + arr_length);
    while (arr_head < arr + arr_length){
        *arr_head = i++;
        ++arr_head;
    }

    show(arr, arr + arr_length);
    
    printf("sum = %lf\n", sum(arr, arr + arr_length));
    
    arr_head = NULL; //Effectively "free" arr_head to prevent dangling pointer problem.
    
    printf("%p : %lf : %lu\n", &arr, *arr, sizeof *arr);
    free(arr);
    arr = NULL;
    
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
    
    while (end > begin++){
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