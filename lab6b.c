/*
Lamog-Doiel, Robert
Lab 6B
05/09/2017

Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab6b.h"

int main () {
    FILE* input = NULL;
    struct Address* contactList[50]; /* Max records 50 */
    unsigned int contactX = 0; /* contactList[50] positional reference/count */
    unsigned int lineN = 0;  /* File line input positional reference/count. Strictly adheres to preformatted input file. */
    char str[512]; /* Arbitrary string length */
    unsigned int i = 0;

    input = fopen( "benihana.txt", "r" );

    if ( input != NULL ) {
        contactList[contactX] = newAddress(); /* Try to add initial address struct */
        if ( contactList[contactX] == NULL ) {
            printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
            exit( EXIT_FAILURE );
        }

        while ( fgets( str, sizeof( str ), input ) ) {
            if ( lineN == 5 ) {  /* File input data entries are separated with blank newline for easier source manipulation and error checking.
                                    Making each entry 5 lines long instead of 4. */

                lineN = 0;  /* Reset input line iterator */

                ++contactX;
                if ( contactX > 50 ) { /* This sets the max limit of input contacts. contactX should likely be compared to a defined or static const max_limit or something equivalent. */
                    --contactX; /* Rolling back count once so we continue to stay in bounds */
                    printf( "This program was designed to process a maximum of %d contacts. Further input will be ignored.\n", contactX );
                    break;
                }
                contactList[contactX] = newAddress(); /* Try to add new address */
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
    } else {
        perror( "fopen: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    }

    fclose( input );

    zipCodeSort( contactList, contactX );

    for ( i; i <= contactX; ++i ) {
        printAddress( contactList[i] );
        delAddress( contactList[i] );
    }

    return 0;
} /* main */