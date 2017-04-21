/*
Lamog-Doiel, Robert
Lab 6B
05/09/2017

HEADER
Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
*/

#ifndef LAB6B_H
#define LAB6B_H

struct Address* newAddress();
void delAddress( struct Address* address );
struct Address* setLastNameFirstName( struct Address* contact, char* str );
struct Address* setStreetAddress( struct Address* contact, char* str );
struct Address* setCityState( struct Address* contact, char* str );
struct Address* setZipCode( struct Address* contact, char* str );
void printAddress( struct Address* address );
struct Address** zipCodeSort( struct Address** contactList, unsigned int numberOfContacts );

#endif