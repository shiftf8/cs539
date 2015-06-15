/*
Lamog, Robert
Lab 6B
01/01/2015
Dynamically input names and addresses that are in alphabetical order and output based on zip code. Disregard duplicate entries.

Address header file.
*/

#ifndef ADDRESS_RECORD_H
#define ADDRESS_RECORD_H

typedef struct Address {
    char firstName[100];
    char lastName[100];
    char streetAddress[1024];
    char city[512];
    char state[2];
    int zipCode[10];
};

#endif /* ADDRESS_RECORD_H */