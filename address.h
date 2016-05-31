/*
Lamog, Robert
Lab 6B
05/30/2016
Dynamically input names and addresses that are in alphabetical order and output based on zip code. Disregard duplicate entries.

For use with lab6B. Simple Address data structure based on predetermined file input.
*/

#ifndef ADDRESS_RECORD_H
#define ADDRESS_RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char lastNameFirstName[512];
    char streetAddress[1024];
    char cityState[512];
    char zipCode[10];
};

struct Address* newAddress() {
    /* Try to allocate address structure */
    
    struct Address* retVal = malloc( sizeof( struct Address ) );
    if ( retVal == NULL ) return NULL;
    
    return retVal;
}
void delAddress( struct Address* address ) {
    if ( address != NULL ) free( address );
}
struct Address* setLastNameFirstName( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setLastNameFirstName: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy(contact->lastNameFirstName, str);
    }
    
    return contact;
}
struct Address* setStreetAddress( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setStreetAddress: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy(contact->streetAddress, str);
    }
    
    return contact;
}
struct Address* setCityState( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setCityState: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy(contact->cityState, str);
    }
    
    return contact;
}
struct Address* setZipCode( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setZipCode: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy(contact->zipCode, str);
    }
    
    return contact;
}
void printAddress( struct Address* address ) {
    /* Test code print block
    printf( "%p\n", address );
    printf( "%s%p\n", address->lastNameFirstName );
    printf( "%s%p\n", address->streetAddress );
    printf( "%s%p\n", address->cityState );
    printf( "%s%p\n", address->zipCode );
    /* */
    
    printf( "%s", address->lastNameFirstName );
    printf( "%s", address->streetAddress );
    printf( "%s", address->cityState );
    printf( "%s\n", address->zipCode );
}

#endif /* ADDRESS_RECORD_H */