//CS 539, At home practice midterm 2 speed programming for study. 1 hour started already. Rob Lamog

#include <stdio.h>
#include <stdlib.h>

double boxArea(double length, double width, double height);
void stats(double * mn, double * av, double * mx, double x, double y, double z);
double aveOdd(const unsigned a[], unsigned els);
void reverse(double * begin, double * end);
unsigned howMany(char c, const char * s);
int die (const char* msg);

int main() {
    double a, b, c;
    unsigned d[] = {1, 22, 3, 44, 5, 1};
    double e[] = {1.1, 2.2, 3.3};
    char* s = "Jack and Jill.";
    
    printf("%lf\n", boxArea(3, 3, 3));

    stats(&a, &b, &c, 7, 2, 3);
    printf("%lf %lf %lf\n", a, b, c);
    
    printf("%lf\n", aveOdd(d, 6));
    
    reverse(e, e + 3);
    printf("%lf %lf %lf\n", e[0], e[1], e[2]);
    
    printf("%u\n", howMany('J', s));
    
    return 0;
}

double boxArea(double length, double width, double height){
    return 2 * ((length * width) + (width * height) + (height * length));
}
void stats(double * mn, double * av, double * mx, double x, double y, double z){
    if ((x < y) && (x < z)) *mn = x;
    else if ((y < x) && (y < z)) *mn = y;
    else *mn = z;
    
    *av = (x + y + z) / 3;
    
    if ((x > y) && (x > z)) *mx = x;
    else if ((y > x) && (y > z)) *mx = y;
    else *mx = z;
}
double aveOdd(const unsigned a[], unsigned els){
    double average = 0.0;
    unsigned oddCount = 0;
    unsigned i = 0;
    
    for (i; i < els; ++i){
        if (a[i] % 2 != 0){
            average += a[i];
            oddCount++;
        }
    }

    return average / oddCount;
}
void reverse(double * begin, double * end){ //Brute force it. Loop through and flip each location. end - begin == number of elements
    double temp = 0;
    unsigned els = end - begin;
    unsigned i = 0;
    
    for (i; i < els / 2; ++i){
        temp = *(begin + i);
        *(begin + i) = *(begin + (els - 1 - i));
        *(begin + (els - 1 - i)) = temp;
    }
}
unsigned howMany(char c, const char * s){
    static unsigned retVal; //Must remember to use static var
    
    if (*s){
        if (*s == c) retVal++;
        howMany(c, (s + 1));
    }
    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s.\n", msg);
    exit(EXIT_FAILURE);
}