/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order pairing roommate id with same/similar interest code.
*/

#include "student.h"
#include <stdio.h>

int main() {
    FILE* input = NULL;
    struct RoommateInfo* studentList[50];
    unsigned int studentX = 0;
    
    input = fopen( "input.lab6C.txt", "r" );
    
    if ( input == NULL ) {
        perror( "fopen: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        studentList[studentX] = new_student(); /* Try to add initial student */
        if ( studentList[studentX] == NULL ) {
            printf( "newAddress: Unsuccessful.\nProgram terminated.\n" );
            exit( EXIT_FAILURE );
        }
            
        while ( fgets( str, sizeof( str ), input ) ) {
            break;
        }
        
    }
    
    return 0;
}