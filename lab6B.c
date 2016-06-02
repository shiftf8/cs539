/*
Lamog, Robert
Lab 6B
05/30/2016
Dynamically input names and addresses that are in alphabetical order and output based on zip code. Disregard duplicate entries.

************ I never wrote an isDuplicateEntry function, per the assignment. Might get around to it later. *************
*/

#include "address.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE* input = NULL;
    struct Address* contactList[50]; /* Max records 50 */
    unsigned int contactX = 0; /* contactList[50] positional reference/count */
    unsigned int lineN = 0;  /* File line input positional reference/count. Strictly adheres to preformatted input file. */
    char str[512];
    unsigned int i = 0;

    input = fopen( "benihana.txt", "r" );
    
    if ( input == NULL ) {
        perror( "fopen: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        contactList[contactX] = newAddress(); /* Try to add initial address struct. */
        if ( contactList[contactX] == NULL ) {
            printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
            exit( EXIT_FAILURE );
        }
            
        while ( fgets( str, sizeof( str ), input ) ) {
            if ( lineN == 5 ) {  /* Separated file input data entries with blank newline for easier source manipulation and error checking.
                                    Making each entry 5 lines long. */
                
                /* printAddress( contactList[contactX] ); /* Pre test print */
                
                lineN = 0;  /* Reset input line iterator */
                
                if ( ( ++contactX ) == 51 ) {
                    printf( "This program was designed to process a maximum of 50 contacts. Further input will be ignored.\n" );
                    break;
                }
                contactList[contactX] = newAddress(); /* Try to add new address. */
                if ( contactList[contactX] == NULL ) {
                    printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
                    exit( EXIT_FAILURE );
                }
            }
            
            if ( lineN == 0 ) setLastNameFirstName( contactList[contactX], str );
            if ( lineN == 1 ) setStreetAddress( contactList[contactX], str );
            if ( lineN == 2 ) setCityState( contactList[contactX], str );
            if ( lineN == 3 ) setZipCode( contactList[contactX], str );

            ++lineN;
        }
        
        /* if ( feof( input ) ) printf( "\n" ); /* */
    }

    fclose( input );
    
    /* printf( "%d\n", contactX ); /* */
    zipCodeSort( contactList, contactX );

    for ( i; i <= contactX; ++i ) {
        printAddress( contactList[i] ); /* Test print */
        delAddress( contactList[i] );
    }

    return 0;
} /* main */