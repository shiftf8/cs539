/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order with roomate id.

For use with lab6C. Simple Student data structure based on predetermined file input.
*/

#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int isRandomInitialized = 0;

struct StudentAndRoommate {
    char studentName[256]; /* [first name] [last name] */
    unsigned int studentID;
    unsigned int interestCode;
    unsigned int roommateID;
};

struct StudentAndRoommate* newStudent() {
    /* Try to allocate new Student */
    struct StudentAndRoommate* retVal = malloc( sizeof( struct StudentAndRoommate ) );
    if ( retVal == NULL ) return NULL;
    
    return retVal;
}
void delStudent( struct StudentAndRoommate* student ) {
    if ( student != NULL ) free( student );
}
struct StudentAndRoommate* setStudentName( struct StudentAndRoommate* student, char* str ) {
    if ( str == NULL ) {
        printf( "setName: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        strcpy( student->studentName, str );
    }
    
    return student;
}
struct StudentAndRoommate* setID( struct StudentAndRoommate* student, unsigned int ID ) {
    if ( !ID ) {
        printf( "setID: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        student->studentID = ID;
    }
    
    return student;
}
struct StudentAndRoommate* setInterestCode( struct StudentAndRoommate* student, unsigned int interestCode ) {
    if ( !interestCode ) {
        printf( "setInterestCode: Unsuccessful.\nProgram terminated.\n" );
        exit( EXIT_FAILURE );
    } else {
        if (!isRandomInitialized) {
            srand( time( NULL ) );
            isRandomInitialized = 1;
        }
        
        student->interestCode = rand() % 50; /* Using dumb PRNG for interest code ftm. */
    }
}

#endif /* STUDENT_RECORD_H */