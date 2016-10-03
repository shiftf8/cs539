//test scratch

#include <stdio.h>
#include <stdlib.h>

void foo(double*, double);

int main(){
    double x;
    double y = 13;
    double i2 = -2;
    unsigned u1 = 1;
    unsigned u2 = 2;

    printf("%p : %lf\n", &x, x);
    printf("%p : %s\n", &"Blah", "Blah");

    foo(&x, y);

    printf("foo -> %p : %lf\n", &x, y);

    printf("%lf\n", -i2++);

    if (5 < 20 < 10) printf("WILD\n");

//    u2 %= 2;
//    printf("%u\n", u2);

    u1 += u2 *= 3;
    printf("%u / %u\n", u1, u2);

    return 0;
}

void foo(double* x, double y){
    *x = y;
}
