/*
Lamog-Doiel, Robert
Lab 8
05/23/2017

HEADER
Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
Use command line arguments with FILE I/O.
*/

#ifndef LAB6B_H
#define LAB6B_H

#define MAX_RECORDS 50
#define ADDRESS_LINE_N 4

/* Not the best use of memory. Input buffer size == member array size. */
typedef struct Address {
    char last_name_first_name[512];
    char street_address[512];
    char city_state[512];
    char zip_code[512];
} Address;

Address* newAddress();
void freeAddress(Address*);
Address* setLastNameFirstName(Address*, char*);
Address* setStreetAddress(Address*, char*);
Address* setCityState(Address*, char*);
Address* setZipCode(Address*, char*);
void writeAddress(Address*, FILE*);

Address** zipCodeSort(Address**, unsigned);

#endif