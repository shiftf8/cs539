/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order with roomate id.

For use with lab6C. Simple Student data structure based on predetermined file input.
*/

#ifndef ROOMMATE_RECORD_H
#define ROOMMATE_RECORD_H

#include "roommate.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RoommateInfo {
    char studentName[256]; /* [first name] [last name] */
    unsigned int studentID;
    unsigned int interestCode;
    struct RoommateInfo* roommate;
} RoommateInfo;

struct RoommateInfo* new_student();
void del_student( struct RoommateInfo* student );
struct RoommateInfo* set_student_name( struct RoommateInfo* student, const char* str );
struct RoommateInfo* set_id( struct RoommateInfo* student, const unsigned int id );
struct RoommateInfo* set_interest_code( struct RoommateInfo* student, const unsigned int interestCode );
void print_roommate_info( const struct RoommateInfo* info );

#endif /* ROOMMATE_RECORD_H */