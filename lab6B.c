/*
Lamog, Robert
Lab 6B
05/30/2016
Dynamically input names and addresses that are in alphabetical order and output based on zip code. Disregard duplicate entries.
*/

#include "address.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE* input = NULL;
    struct Address* contactList[50]; /* Max records 50 */
    unsigned int contactX = 0; /* contactList[50] positional reference */
    unsigned int lineX = 0;  /* File line input positional reference. Strictly adheres to preformatted input file. */
    char str[1024];
    unsigned int i = 0;

    input = fopen( "benihana.txt", "r" );
    
    if ( input == NULL ) {
        perror( "fopen: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        contactList[contactX] = newAddress();
            
        if ( contactList[contactX] == NULL ) {
            printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
            exit( EXIT_FAILURE );
        }
            
        while ( fgets( str, sizeof( str ), input ) ) {
            if ( lineX == 5 ) {  /* Separated file input data entries with blank newline for easier source manipulation and error checking.
                                    Making each entry 5 lines long. */
                lineX = 0;  /* Reset input line iterator */
                
                contactList[++contactX] = newAddress();
                
                if ( contactList[contactX] == NULL ) {
                    printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
                    exit( EXIT_FAILURE );
                }
            }
            
            if ( lineX == 0 ) setLastNameFirstName( contactList[contactX], str );
            if ( lineX == 1 ) setStreetAddress( contactList[contactX], str );
            if ( lineX == 2 ) setCityState( contactList[contactX], str );
            if ( lineX == 3 ) setZipCode( contactList[contactX], str );

            ++lineX;
        }
        
        /* if ( feof( input ) ) printf( "\n" ); /* */
    }

    fclose( input );

    for ( i; i <= contactX; ++i ) {
        printAddress( contactList[i] );
        delAddress( contactList[i] );
    }

    return 0;
} /* main */