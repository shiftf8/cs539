// CS 539, HW 7, Rob Lamog

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countdown( unsigned seconds );
unsigned add( unsigned a, unsigned b );
unsigned multiply( unsigned a, unsigned b );
unsigned power( unsigned a, unsigned b );
void output( const char * s );
unsigned length( const char * s );
unsigned howMany( char c, const char * s );
void reverse( char * s );

int die( const char * msg );

int main(){
    char* s = "George!";
    
    countdown(5);
    printf("\n");
    
    printf("%u\n", add(3, 7));
    printf("\n");
    
    printf("%u\n", multiply(3, 7));
    printf("\n");
    
    printf("%u\n", power(3, 7));
    printf("\n");
    
    // printf("%lu\n", sizeof s);
    output(s);
    printf("\n");
    
    printf("%u\n", length(s));
    
    printf("%u\n", howMany('G', s));
    
    reverse(s);
    printf("\n");
    
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
    static unsigned position = 0;

    printf("%c", *(s + (position++)));
    if (position < strlen(s)) output(s);
}
unsigned length( const char * s ){
    static unsigned char_count = 0;
    
    if (char_count < strlen(s)){
        char_count++;
        length(s);
    }
    return char_count;
}
unsigned howMany( char c, const char * s ){
    static unsigned position = 0;
    static unsigned count_char = 0;
    
    if (c == *(s + (position++))) ++count_char;
    if (position < strlen(s)) howMany(c, s);
    return count_char;
}
void reverse( char * s ){
    static unsigned position = 0;
    char temp = '\0';
    unsigned end = (strlen(s) - 1) - position;
    
    if (position <= strlen(s) / 2){
        temp = *(s + position);
        *(s + position) = *(s + end);
        *(s + end) = temp;
        // reverse(s);
    }
}

int die( const char * msg ){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}