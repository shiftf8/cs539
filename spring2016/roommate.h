/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order with roomate id.

For use with lab6C. Simple Student data structure based on predetermined file input.
*/

#ifndef ROOMMATE_RECORD_H
#define ROOMMATE_RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RoommateInfo {
    char studentName[256]; /* [first name] [last name] */
    unsigned int studentID;
    unsigned int interestCode;
    struct RoommateInfo* roommate;
} RoommateInfo;

struct RoommateInfo* new_student() {
    struct RoommateInfo* retVal = malloc( sizeof( struct RoommateInfo ) );
    if ( retVal == NULL ) return NULL;

    return retVal;
}
void del_student( struct RoommateInfo* student ) {
    if ( student != NULL ) free( student );
}

struct RoommateInfo* set_student_name( struct RoommateInfo* student, char* str ) {
    strcpy( student->studentName, str );

    return student;
}
struct RoommateInfo* set_id( struct RoommateInfo* student, unsigned int id ) {
    student->studentID = id;

    return student;
}
struct RoommateInfo* set_interest_code( struct RoommateInfo* student, unsigned int interestCode ) {
    student->interestCode = interestCode;
    
    return student;
}

void print_roommate_info( struct RoommateInfo* info ) {
    /* Test print code */
    printf( "Student: %s\nID: %d\nInterest Code: %d\n", info->studentName, info->studentID, info->interestCode );
    printf( "Roomate: %s\n", info->roommate->studentName ); /**/
    
    /* printf( "Student: %s\nRoommate: %s\n", info->studentName, info->roommate->studentName ); /**/
}

#endif /* ROOMMATE_RECORD_H */