#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student_T {
    char studentName[256]; /* [first name] [last name] */
    unsigned int studentID;
    unsigned int interestCode;
    struct Student_T *roommate;
};

struct Student_T *new_student()
{
    struct Student_T *retVal = malloc(sizeof(struct Student_T));
    if (retVal == NULL) return NULL;

    return retVal;
}
void del_student(struct Student_T *student)
{
    if (student != NULL) free(student);
}

struct Student_T *set_student_name(struct Student_T *student, char *str)
{
    strcpy(student->studentName, str);

    return student;
}
struct Student_T *set_id(struct Student_T *student, unsigned int id)
{
    student->studentID = id;

    return student;
}
struct Student_T *set_interest_code(struct Student_T *student, unsigned int interestCode)
{
    student->interestCode = interestCode;

    return student;
}

void print_roommate_info(struct Student_T *info)
{
    /* Test print code */
    printf("Student: %s\nID: %d\nInterest Code: %d\n", info->studentName, info->studentID, info->interestCode);
    printf("Roomate: %s\n", info->roommate->studentName); /**/

    /* printf("Student: %s\nRoommate: %s\n", info->studentName, info->roommate->studentName); /**/
}