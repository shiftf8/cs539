// CS 539, Practice Program 1, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void stat( double * minPos, double * maxPos, const double a[], unsigned els );
int die(const char* msg);

int main() {
    double minPos;
    double maxPos;
    double a[] = {0.0, 1.0, 2.0, 3.0, 4.0};
    
    stat(&minPos, &maxPos, a, 5);
    printf("minPos = %f, maxPos = %f\n", minPos, maxPos);
    
    return 0;
} //main

void stat( double * minPos, double * maxPos, const double a[], unsigned els ){
    unsigned i = 1;
    
    *minPos = a[0];
    *maxPos = a[0];
    
    for (i; i < els; ++i){
        if (*minPos > a[i]) *minPos = a[i];
        if (*maxPos < a[i]) *maxPos = a[i];
    }
    
    if (*minPos <= 0 && *maxPos <= 0) die("No positive elements in array.");
}

int die(const char* msg){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}