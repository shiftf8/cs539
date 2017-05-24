/*
Lamog-Doiel, Robert
Lab 8
05/23/2017

HEADER DEFINITIONS
Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
Use command line arguments with FILE I/O.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab8.h"

/*
    Malloc new address struct.
    Return NULL on failure.
    Return ptr to new address struct on success.
*/
Address* newAddress(){
    Address* retVal = malloc(sizeof(Address));
    if (retVal == NULL) return NULL;

    return retVal;
}
void freeAddress(Address* address){
    if (address != NULL) free(address);
}
/*
    Set contact->last_name_first_name.
    Exit program on failure.
*/
Address* setLastNameFirstName(Address* contact, char* str){
    if (str == NULL){
        printf("setLastNameFirstName: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->last_name_first_name, str);
    }

    return contact;
}
/*
    Set contact->street_address.
    Exit program on failure.
*/
Address* setStreetAddress(Address* contact, char* str){
    if (str == NULL){
        printf("setStreetAddress: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->street_address, str);
    }

    return contact;
}
/*
    Set contact->city_state.
    Exit program on failure.
*/
Address* setCityState(Address* contact, char* str){
    if (str == NULL){
        printf("setCityState: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->city_state, str);
    }

    return contact;
}
/*
    Set contact->zip_code.
    Exit program on failure.
*/
Address* setZipCode(Address* contact, char* str){
    if (str == NULL){
        printf("setZipCode: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->zip_code, str);
    }

    return contact;
}
/*
    Write single address from ptr to file.
*/
void writeAddress(Address* address, FILE* output){
    fprintf(output, "%s%s%s%s",
        address->last_name_first_name,
        address->street_address,
        address->city_state,
        address->zip_code);
}

/*
    DESTRUCTIVE selection sort utilizing zip code in ascending order.
*/
Address** zipCodeSort(Address** contact_list, unsigned number_of_contacts){
    unsigned i = 0;
    unsigned j = 0;
    unsigned min = 0;
    Address* tmp;

    for (i; i <= number_of_contacts; ++i){
        min = i;

        for (j = i; j <= number_of_contacts; ++j){
            if (strcmp(contact_list[j]->zip_code, contact_list[min]->zip_code) < 0){
                min = j;
            }
        }

        tmp = contact_list[i];
        contact_list[i] = contact_list[min];
        contact_list[min] = tmp;
    }

    return contact_list;
}