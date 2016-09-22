// CS 539, HW 4 Functions, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

char grade( double score );
void sort( double * a, double * b, double * c );
int prime( unsigned n );
unsigned howManyPrimes( unsigned lo, unsigned hi );
int relPrime( unsigned a, unsigned b );
int leap( unsigned year );
void stats( double * min, double * average, double * max );

void swap(double * x, double * y);
int gcd( unsigned a, unsigned b );
int die(const char * msg);

int main(){

    return 0;
}

char grade( double score ){
    if ((score < 0) || (score > 100)) die("Score is outside range [0, 100].\n");
    
    if (score >= 85) return 'A';
    if (score >= 75) return 'B';
    if (score >= 65) return 'C';
    if (score >= 50) return 'D';
    if (score >= 0) return 'F';
}
void sort( double * a, double * b, double * c ){
    if (*a < *b) swap(a, b);
    if (*b < *c) swap(b, c);
    if (*a < *b) swap(a, b);
    printf("%f, %f, %f\n", *a, *b, *c);
}
int prime( unsigned n ){
    unsigned i = 2; //Starting calculation loop at 2 to avoid modulo by zero or one.
    
    if ((n == 0) || (n == 1)) return 0; //Special 0 or 1 case
    if (n == 2) return 1; //Special 2 case
    for(i; i < ((n / 2) + 1); ++i){
        if (n % i == 0) return 0;
    }
    return 1; //It's reasonable to assume, if we have reached this far, the number must be prime.
}
unsigned howManyPrimes( unsigned lo, unsigned hi ){
    unsigned retVal = 0;
    
    for (lo; lo < hi; ++lo){
        if (prime(lo)) retVal++;
    }
    
    return retVal;
}
int relPrime( unsigned a, unsigned b ){
    if (gcd(a, b) == 1) return 1; //If the greatest common denominator of two numbers is equal to 1, the two numbers must necessarily be relatively prime.
    return 0;
}
int leap( unsigned year ){
    if (year < 1752) die("Year entered is prior 1752.\n");
    
    if (year % 100 == 0){
        if (year % 400 == 0) return 1; //Special 400 year, leap year case.
        return 0;
    }
    if (year % 4 == 0) return 1; //Leap year cases must necessarily follow, year is evenly divisible by 4, given previous logic.
    return 0;
}
void stats( double * min, double * average, double * max ){
    double num[1024] = {};
    double mean = 0;
    unsigned i = 0, j = 0;

    while (i < 1024){ //1024 double input limit.
        if (scanf("%lf, ", &num[i])) ++i;
        else break;
    }

    if (i == 0) die("Must input numeric values to evaluate.\n");

    //Initializing with first valid input.
    min = &num[0];
    average = &num[0];
    max = &num[0];

    if (i > 1){
        for (j; j < i; ++j){
            if (*min >= num[j]) min = &num[j];
            mean += num[j];
            if (*max <= num[j]) max = &num[j];
        }

        mean = mean / i;
        average = &mean;
    }
}

void swap(double * x, double * y){
    double temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
int gcd( unsigned a, unsigned b ){ //Recursive function. May fail with larger numbers.
    if ((a == 0) || (b == 0)) return 0; //Special 0 case
    if (a % b == 0) return b;
    
    a = a % b;
    return gcd(b, a);
}

int die(const char * msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}