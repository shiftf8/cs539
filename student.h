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

struct RoommateInfo {
    char studentName[256]; /* [first name] [last name] */
    unsigned int studentID;
    unsigned int interestCode;
    unsigned int roommateID;
};

struct RoommateInfo* new_student() {
    /* Try to allocate new Student */
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

#endif /* STUDENT_RECORD_H */