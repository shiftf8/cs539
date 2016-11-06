// CS 539, HW 7, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

void countdown( unsigned seconds );
unsigned add( unsigned a, unsigned b );
unsigned multiply( unsigned a, unsigned b );
unsigned power( unsigned a, unsigned b );
void output( const char * s );
unsigned length( const char * s );
unsigned howMany( char c, const char * s );
void reverse( char * s );
void copy( char * destination, const char * source );

int main(){
    char* s = "I am Job. Yes?";
    char str[30];
    
    countdown(5);
    printf("\n");
    
    printf("%u\n", add(3, 7));
    printf("\n");
    
    printf("%u\n", multiply(3, 7));
    printf("\n");
    
    printf("%u\n", power(3, 7));
    printf("\n");
    
    output(s);
    printf("\n");
    
    printf("%u\n", length(s));
    
    printf("%u\n", howMany('e', s));
    
    reverse(s);
    printf("\n");
    
    copy(str, s);
    printf("%s\n", str);
    
    return 0;
} //main

void countdown( unsigned seconds ){
    if (seconds > 0){
        printf("%u...\n", seconds--);
        countdown(seconds);
    } else
        printf("Blast off!\n");
}
unsigned add( unsigned a, unsigned b ){
    if (a == 0) return b;
    return add(--a, ++b);
}
unsigned multiply( unsigned a, unsigned b ){
    if (b == 0) return 0;
    return add(a, multiply(a, --b));
}
unsigned power( unsigned a, unsigned b ){
    if (b == 0) return 1;
    return multiply(a, power(a, --b));
}
void output( const char * s ){
    if (*s){
        printf("%c", *s);
        output(s + 1);
    }
}
unsigned length( const char * s ){
    static unsigned char_count = 0;
    
    if (*s){
        ++char_count;
        length(s + 1);
    }
    return char_count;
}
unsigned howMany( char c, const char * s ){
    static unsigned count_char = 0;
    
    if (*s){
        if (c == *s) ++count_char;
        howMany(c, s + 1);
    }
    return count_char;
}
void reverse( char * s ){
    if (*s){
        reverse(s + 1);
        printf("%c", *s);
    }
}
void copy( char * destination, const char * source ){
    *destination = *source;
    if (*source == '\0') return;
    copy(destination + 1, source + 1);
}