/*
Lamog-Doiel, Robert
Lab 6B
05/09/2017

Dynamically allocate array of pointers to structs from file input.
Names and addresses are in alphabetical order.
Output based on ascending zip code.
Include duplicate entries.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab6b.h"

int main(int argc, char* argv[]){
    FILE* input = NULL;
    FILE* output = NULL;
    Address* address_list[MAX_RECORDS];
    unsigned contact_x = 0; /* Positional reference/count. Used contact instead of address for readability. */
    unsigned line_n = 0;  /* Line input positional reference. Set #define ADDRESS_LINE_N. */
    char str[512]; /* Arbitrary string input length */
    unsigned i = 0;

    if (argc != 3){
        printf("Missing arguments. e.g. input.txt output.txt\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    input = fopen(argv[1], "r");
    if (input != NULL){
        address_list[contact_x] = newAddress(); /* Try to add initial address struct */
        if (address_list[contact_x] == NULL){
            printf("newAddress: Unsuccessful.\nProgram terminated.\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(str, sizeof(str), input)){
            if (line_n == ADDRESS_LINE_N){
                if (++contact_x == MAX_RECORDS) {
                    --contact_x; /* Rolling back count to stay in bounds */
                    printf("This program was designed to process a maximum of %d addresses. Further input will be ignored.\n", MAX_RECORDS);
                    break;
                }
                address_list[contact_x] = newAddress(); /* Try to add new address */
                if (address_list[contact_x] == NULL){
                    printf("newAddress: Unsuccessful.\nProgram terminated.\n");
                    exit(EXIT_FAILURE);
                }

                line_n = 0;  /* Reset input line iterator */
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

    output = fopen(argv[2], "w");
    if (output != NULL){
        for (i; i <= contact_x; ++i){
            writeAddress(address_list[i], output);
            freeAddress(address_list[i]); /* Freeing structs at this time. Convenient. */
        }
    } else {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }
    fclose(output);

    return 0;
}