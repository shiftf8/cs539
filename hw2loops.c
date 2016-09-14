// CS 539, HW 2 Loops, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void outputRange( unsigned lo, unsigned hi ); // [lo, hi)
unsigned addRange( unsigned lo, unsigned hi ); // [lo, hi)
unsigned factorial( unsigned n ); // factorial(4) returns 24
unsigned fib( unsigned n ); // fibonacci function of 6 is 8
int prime( unsigned n ); // returns 1 if n is 2, 3, 5, 7, ...
unsigned gcd( unsigned a, unsigned b ); // greatest common divisor
void multiplicationTable( unsigned max ); // output multiplication table
int die( const char * msg );

int main(){
    printf("outputRange(3, 7)\n");
    outputRange(3,7);
    printf("outputRange(7, 3)\n");
    outputRange(7,3);
    printf("\n");
    
    printf("addRange(a, b)\n");
    printf("%u\n", addRange(3,7));

    printf("factorial(n)\n");
    printf("%u\n", factorial(0));
    printf("%u\n", factorial(1));
    printf("%u\n", factorial(2));
    printf("%u\n", factorial(3));
    printf("%u\n", factorial(4));

    printf("fib(n)\n");
    printf("%u\n", fib(0));
    printf("%u\n", fib(1));
    printf("%u\n", fib(2));
    printf("%u\n", fib(3));
    printf("%u\n", fib(4));
    printf("%u\n", fib(5));
    printf("%u\n", fib(6));
    printf("----------\n");
    printf("%u\n", fib(7));
    printf("%u\n", fib(5) + fib(6));

    printf("prime(n)\n");
    printf("2 is %i prime.\n", prime(2));
    printf("3 is %i prime.\n", prime(3));
    printf("5 is %i prime.\n", prime(5));
    printf("7 is %i prime.\n", prime(7));
    printf("11 is %i prime.\n", prime(11));
    printf("----------\n");
    printf("1 is %i prime.\n", prime(1));
    printf("4 is %i prime.\n", prime(4));
    printf("9 is %i prime.\n", prime(9));
    
    printf("gcd(a, b)\n");
    printf("GCD of 6 and 6 is %u.\n", gcd(6, 6));
    printf("GCD of 3 and 9 is %u.\n", gcd(3, 9));
    printf("GCD of 9 and 3 is %u.\n", gcd(9, 3));
    printf("GCD of 300 and 110 is %u.\n", gcd(300, 110));
    printf("GCD of 2 and 21 is %u.\n", gcd(2, 21));
    
    printf("multiplicationTable(18)\n");
    multiplicationTable(18);
    printf("----------\n");
    multiplicationTable(0);
    printf("----------\n");
    multiplicationTable(1);
    printf("----------\n");
    multiplicationTable(12);

    return 0;
}

void outputRange( unsigned lo, unsigned hi ){
    for(lo; lo < hi; ++lo) printf("%u\n", lo);
}
unsigned addRange( unsigned lo, unsigned hi ){
    unsigned retVal = 0; //Initialize as 0 to maintain Additive Identity.
    
    for(lo; lo < hi; ++lo) retVal = retVal + lo;
    return retVal;
}
unsigned factorial( unsigned n ){
    unsigned retVal = 1; //Initialize as 1 to maintain Multiplicative Identity.
    unsigned i = 1; //Starting calculation loop at 1 to maintain Multiplicative Identity.
    
    if (n == 0) return 1; //Special 0 case
    
    for(i; i <= n; ++i) retVal = retVal * (i);
    return retVal;
}
unsigned fib( unsigned n ){ //Recursive function. May fail with larger numbers.
    if (n == 0) return 0; //Special 0 case
    if (n == 1) return 1; //Special 1 case
    
    return fib(n - 1) + fib(n - 2);
}
int prime( unsigned n ){
    unsigned i = 2; //Starting calculation loop at 2 to avoid modulo by zero or one.
    
    if ((n == 0) || (n == 1)) return 0; //Special 0 or 1 case
    if (n == 2) return 1; //Special 2 case
    if (n % 2 == 0) return 0; //Even numbers are not prime. Except 2, see above line.
    for(i; i < n; ++i){ //Not the most efficient check, but should work well enough for this program.
        if (n % i == 0) return 0;
    }
    return 1; //It's reasonable to assume, if we have reached this far, the number must be prime.
}
unsigned gcd( unsigned a, unsigned b ){ //Recursive function. May fail with larger numbers.
    if ((a == 0) || (b == 0)) return 0; //Special 0 case
    if (a % b == 0) return b;
    
    a = a % b;
    return gcd(b, a);
}
void multiplicationTable( unsigned max ){
    unsigned row = 0;
    unsigned column = 0;
    
    if (max > 18) die("Outside display constraint of 80 char per line.\n");
    
    printf (" *");
    for(column; column <= max; ++column) printf("%4u", column);
    printf("\n");
    column = 0; //Reset column
    for(row; row <= max; ++row){
        printf("%2u", row);
        for(column; column <= max; ++column) printf("%4u", column * row);
        printf("\n");
        column = 0; //Reset column
    }
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}