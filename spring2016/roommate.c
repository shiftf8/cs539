struct RoommateInfo* new_student() {
    struct RoommateInfo* retVal = malloc( sizeof( struct RoommateInfo ) );
    if ( retVal == NULL ) return NULL;

    return retVal;
}
void del_student( struct RoommateInfo* student ) {
    if ( student != NULL ) free( student );
}

struct RoommateInfo* set_student_name( struct RoommateInfo* student, const char* str ) {
    strcpy( student->studentName, str );

    return student;
}
struct RoommateInfo* set_id( struct RoommateInfo* student, const unsigned int id ) {
    student->studentID = id;

    return student;
}
struct RoommateInfo* set_interest_code( struct RoommateInfo* student, const unsigned int interestCode ) {
    student->interestCode = interestCode;
    
    return student;
}

void print_roommate_info( const struct RoommateInfo* info ) {
    /* Test print code */
    printf( "Student: %s\nID: %d\nInterest Code: %d\n", info->studentName, info->studentID, info->interestCode );
    printf( "Roomate: %s\n", info->roommate->studentName ); /**/
    
    /* printf( "Student: %s\nRoommate: %s\n", info->studentName, info->roommate->studentName ); /**/
}