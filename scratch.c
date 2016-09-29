//test scratch

#include <stdio.h>
#include <stdlib.h>

void foo(double*, double);

int main(){
    double x;
    double y = 13;

    printf("%p : %lf\n", &x, x);

    foo(&x, y);

    printf("foo -> %p : %lf\n", &x, y);

    return 0;
}

void foo(double* x, double y){
    *x = y;
}