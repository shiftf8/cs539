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
    char last_name_first_name[256];
    char street_address[512];
    char city_state[256];
    char zip_code[10];
};

/*
    Malloc new address struct.
    Return NULL on failure.
    Return ptr to new address struct on success.
*/
struct Address* newAddress(){
    struct Address* retVal = malloc(sizeof(struct Address));
    if (retVal == NULL) return NULL;

    return retVal;
}
void delAddress(struct Address* address){
    if (address != NULL) free(address);
}
/*
    Set contact->last_name_first_name.
    Exit program on failure.
*/
struct Address* setLastNameFirstName(struct Address* contact, char* str){
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
struct Address* setStreetAddress(struct Address* contact, char* str){
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
struct Address* setCityState(struct Address* contact, char* str){
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
struct Address* setZipCode(struct Address* contact, char* str){
    if (str == NULL){
        printf("setZipCode: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        strcpy(contact->zip_code, str);
    }

    return contact;
}
/*
    Print single address from ptr.
*/
void printAddress(struct Address* address){
    /* TEST CODE PRINT BLOCK
    printf("%p\n", address);
    printf("%s%p\n", address->last_name_first_name);
    printf("%s%p\n", address->street_address);
    printf("%s%p\n", address->city_state);
    printf("%s%p\n", address->zip_code);
    /* */

    printf("%s%s%s%s", address->last_name_first_name, address->street_address, address->city_state, address->zip_code);
}

/*
    DESTRUCTIVE bubble sort from zip code in ascending order.
*/
struct Address** zipCodeSort(struct Address** contact_list, unsigned number_of_contacts){
    unsigned i = 0;
    unsigned j = 0;
    unsigned min = 0;
    struct Address* tmp;

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