/*
Lamog-Doiel, Robert
Lab 6B
05/09/2017

Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
*/

#define MAX_RECORDS 50
#define RECORD_LINE_LENGTH 4

#include <stdio.h>
#include <stdlib.h>
#include "lab6b.h"

int main () {
    FILE* input = NULL;
    struct Address* address_list[MAX_RECORDS];
    unsigned contact_x = 0; /* Positional reference/count */
    unsigned line_n = 0;  /* File line input positional reference/count. Strictly adheres to preformatted input file. Set #define RECORD_LINE_LENGTH. */
    char str[512]; /* Arbitrary string input length */
    unsigned i = 0;

    input = fopen("address.txt", "r");

    if (input != NULL){
        address_list[contact_x] = newAddress(); /* Try to add initial address struct */
        if (address_list[contact_x] == NULL){
            printf("newAddress: Unsuccessful.\nProgram terminated.\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(str, sizeof(str), input)){
            if (line_n == RECORD_LINE_LENGTH){
                line_n = 0;  /* Reset input line iterator */

                ++contact_x;
                if (contact_x > MAX_RECORDS) {
                    --contact_x; /* Rolling back count once so we continue to stay in bounds */
                    printf("This program was designed to process a maximum of %d contacts. Further input will be ignored.\n", MAX_RECORDS);
                    break;
                }
                address_list[contact_x] = newAddress(); /* Try to add new address */
                if (address_list[contact_x] == NULL){
                    printf("newAddress: Unsuccessful.\nProgram terminated.\n");
                    exit(EXIT_FAILURE);
                }
            }

            if (line_n == 0) setLastNameFirstName(address_list[contact_x], str);
            if (line_n == 1) setStreetAddress(address_list[contact_x], str);
            if (line_n == 2) setCityState(address_list[contact_x], str);
            if (line_n == 3) setZipCode(address_list[contact_x], str);

            ++line_n;
        }
    } else {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    fclose(input);

    zipCodeSort(address_list, contact_x);

    for (i; i <= contact_x; ++i){
        printAddress(address_list[i]);
        delAddress(address_list[i]);
    }

    return 0;
} /* main */