/*
Lamog-Doiel, Robert
Lab 6B
05/09/2017

HEADER DEFINITIONS 
Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char lastNameFirstName[256];
    char streetAddress[512];
    char cityState[256];
    char zipCode[10];
};

struct Address* newAddress(){
    /* Try to allocate Address structure */
    struct Address* retVal = malloc(sizeof(struct Address));
    if (retVal == NULL) return NULL;

    return retVal;
}
void delAddress(struct Address* address){
    if (address != NULL) free(address);
}
struct Address* setLastNameFirstName(struct Address* contact, char* str){
    if (str == NULL){
        printf("setLastNameFirstName: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->lastNameFirstName, str);
    }

    return contact;
}
struct Address* setStreetAddress(struct Address* contact, char* str){
    if (str == NULL){
        printf("setStreetAddress: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->streetAddress, str);
    }

    return contact;
}
struct Address* setCityState(struct Address* contact, char* str){
    if (str == NULL){
        printf("setCityState: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->cityState, str);
    }

    return contact;
}
struct Address* setZipCode(struct Address* contact, char* str){
    if (str == NULL){
        printf("setZipCode: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->zipCode, str);
    }

    return contact;
}
void printAddress(struct Address* address){
    /* Test code print block
    printf("%p\n", address);
    printf("%s%p\n", address->lastNameFirstName);
    printf("%s%p\n", address->streetAddress);
    printf("%s%p\n", address->cityState);
    printf("%s%p\n", address->zipCode);
    /* */

    printf("%s%s%s%s\n", address->lastNameFirstName, address->streetAddress, address->cityState, address->zipCode);
}

struct Address** zipCodeSort(struct Address** contactList, unsigned numberOfContacts){
    unsigned i = 0;
    unsigned j = 0;
    unsigned min = 0;
    struct Address* tmp;

    for (i; i <= numberOfContacts; ++i){
        min = i;

        for (j = i; j <= numberOfContacts; ++j){
            if (strcmp(contactList[j]->zipCode, contactList[min]->zipCode ) < 0){
                min = j;
            }
        }

        tmp = contactList[i];
        contactList[i] = contactList[min];
        contactList[min] = tmp;
    }

    return contactList;
}
