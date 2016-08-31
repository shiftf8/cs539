/*
Lamog, Rob
CS539 Common Custom Function Library
*/

#ifndef CS539_CUSTOM_LIB
#define CS539_CUSTOM_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_num_checker( char c ) {
    if ( ( c >= '0' ) && ( c <= '9' ) ) return 1;
    return 0;
}
unsigned int char_to_int( char c, unsigned int i ) {
    return (i * 10) + (c - '0');
}
unsigned int build_num( char* c ) {
    unsigned int i = 0;
    int end_of_operand_flag = 0;

    return i;    
}
void die( char* msg ) {
    printf( "\nFatal error: %s\n", msg );
    exit( EXIT_FAILURE );
}

#endif /* CS539_CUSTOM_LIB */