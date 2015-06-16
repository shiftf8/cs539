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
    char firstLineLastNameFirstName[512];
    char secondLineStreetAddress[1024];
    char thirdLineCityState[512];
    int fourthLineZipCode[10];
} address;

#endif /* ADDRESS_RECORD_H */