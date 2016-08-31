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
    char lastNameFirstName[256];
    char streetAddress[512];
    char cityState[256];
    char zipCode[10];
};

struct Address* newAddress() {
    /* Try to allocate Address structure */
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
        strcpy( contact->lastNameFirstName, str );
    }
    
    return contact;
}
struct Address* setStreetAddress( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setStreetAddress: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy( contact->streetAddress, str );
    }
    
    return contact;
}
struct Address* setCityState( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setCityState: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy( contact->cityState, str );
    }
    
    return contact;
}
struct Address* setZipCode( struct Address* contact, char* str ) {
    if ( str == NULL ) {
        printf( "setZipCode: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy( contact->zipCode, str );
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
    
    printf( "%s%s%s%s\n", address->lastNameFirstName, address->streetAddress, address->cityState, address->zipCode );
}

struct Address** zipCodeSort( struct Address** contactList, unsigned int numberOfContacts ) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int min = 0;
    struct Address* tmp;

    for ( i; i <= numberOfContacts; ++i ) {
        min = i;
        
        for ( j = i; j <= numberOfContacts; ++j ) {
            if ( strcmp( contactList[j]->zipCode, contactList[min]->zipCode ) < 0 ) {
                min = j;
            }
        }
            
        tmp = contactList[i];
        contactList[i] = contactList[min];
        contactList[min] = tmp;
    }
    
    return contactList;
}

#endif /* ADDRESS_RECORD_H */