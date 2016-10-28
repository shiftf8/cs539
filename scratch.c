//test scratch

#include <stdio.h>
#include <stdlib.h>

unsigned foo(unsigned, unsigned);

int main(){
    printf("%u\n", foo(3, 7));
    
    return 0;
}

unsigned foo(unsigned a, unsigned b){
    if (b == 0) return 1;
    return a * foo(a, --b);
}
