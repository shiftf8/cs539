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
void delAddress(struct Address*);
struct Address* setLastNameFirstName(struct Address*, char*);
struct Address* setStreetAddress(struct Address*, char*);
struct Address* setCityState(struct Address*, char*);
struct Address* setZipCode(struct Address*, char*);
void printAddress(struct Address*);
struct Address** zipCodeSort(struct Address**, unsigned);

#endif
