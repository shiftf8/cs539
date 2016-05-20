/*
Lamog, Robert
Lab 6B
01/01/2015
Dynamically input names and addresses that are in alphabetical order and output based on zip code. Disregard duplicate entries.
*/

#include "address.h"
#include <stdio.h>
#include <stdlib.h>

int address_sort( address **, unsigned int );

int main() {
    FILE *input = NULL;
    address *addressList[1024];
    unsigned int lineN = 0; /* check address.h for line designations */
    unsigned int isNextRecord = 1;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;

    input = fopen("input.lab6B.txt", "r");
    
    if (input == NULL) {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    } else {
        while ((c = fgetc(input)) != EOF) {
            if (isNextRecord) {
                isNextRecord = 0;

                addressList[i] = (address *) malloc(sizeof(address));
                if (addressList[i] == NULL) {
                    printf("malloc: Unsuccessful.\nProgram terminated.\n");
                    exit(EXIT_FAILURE);
                }
            }
            
            if (lineN == 0) {
                addressList[i]->firstLineLastNameFirstName[j++] = c;
                // printf("%c", addressList[i]->firstLineLastNameFirstName[j - 1]);
            }
            if (lineN == 1) {
                addressList[i]->secondLineStreetAddress[j++] = c;
                // printf("%c", addressList[i]->secondLineStreetAddress[j - 1]);
            }
            if (lineN == 2) {
                addressList[i]->thirdLineCityState[j++] = c;
                // printf("%c", addressList[i]->thirdLineCityState[j - 1]);
            }
            if (lineN == 3) {
                addressList[i]->fourthLineZipCode[j++] = c;
                // printf("%c", addressList[i]->fourthLineZipCode[j - 1]);
            }
            
            if (c == '\n') lineN++;
            if (lineN == 5) {
                isNextRecord = 1;
                i++;
                lineN = 0;
                j = 0;
                // printf("\n");
            }
        }
        fclose(input);
        
        if (!address_sort(addressList, i)) {
            printf("address_sort: Unsuccessful.\nProgram terminated.\n");
            exit(EXIT_FAILURE);
        } else {
            printf("SUCCESS! for now.\n");
        }
    }

    // printf("\n");
    return 0;
} /* main */

int address_sort( address **addressList, unsigned int sizeOfaddressList ) {
    return 1;
}
