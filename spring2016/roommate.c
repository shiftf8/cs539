#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student_T {
    char studentName[256]; /* [first name] [last name] */
    long unsigned studentID;
    long unsigned interestCode;
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
    if (student != NULL) {
        student->roommate = NULL;
        free(student);
    }
}

struct Student_T *set_student_name(struct Student_T *student, const char *str)
{
    strcpy(student->studentName, str);
    student->studentName[strcspn(student->studentName, "\n")] = 0; /* Remember this little inline to strip newline */

    return student;
}
struct Student_T *set_id(struct Student_T *student, char *str) /* Be wary of ID numbers too big to 'fit' */
{
    student->studentID = strtoul(str, NULL, 10);

    return student;
}
struct Student_T *set_interest_code(struct Student_T *student, char *str)
{
    student->interestCode = strtoul(str, NULL, 10);

    return student;
}
/*
 * This is a 'magic' function.
 * It attempts to loop through struct Student_T *studentList[] and match the next nearest student1->interestCode
 * with the first encounter from the struct Student_T *studentList[]->interestCode.
 * Next nearest checks equals, then plus 1, minus 1, plus 2, minus 2, ...
 * Then sets student1->roommate to the nearest matching struct Student_T *.
 * Should only set when student1->roommate == NULL && studentList[]->roommate == NULL.
 * Which means this function doesn't set anything if the list has an odd number of structs.
 * NOT AN EFFICIENT METHOD.
 */
struct Student_T *set_roommate(struct Student_T *studentList[], unsigned int els)
{
    unsigned int i = 1; /* Skipping first entry since that's what we're supposed to be testing against */
    unsigned int plusOrMinus = 0; /* 0 == plus. 1 == minus. 2 == reset and adjust j */
    unsigned int j = 1; /* j == by how much to plus or minus */
    long unsigned tmpInterestCode = studentList[0]->interestCode;

    // printf("%p\n", (void *) studentList[i]);
    while (studentList[0]->roommate == NULL) {
        for (i; i < els; ++i) {
            if (studentList[i]->roommate == NULL) {
                if (tmpInterestCode == studentList[i]->interestCode) {
                    studentList[0]->roommate = studentList[i];
                    studentList[i]->roommate = studentList[0];
                    return studentList[0];
                }
            }
        }
        if (plusOrMinus == 0) {
            ++plusOrMinus;
            tmpInterestCode + j;
        }
        else if (plusOrMinus == 1) {
            ++plusOrMinus;
            tmpInterestCode - j - j;
        }
        else if (plusOrMinus == 2) {
            plusOrMinus = 0;
            ++j;
        }
    }
    return studentList[0];
}
void print_roommate_info(struct Student_T *info)
{
    /* Test print code */
    printf("Student: %s\nID: %lu\nInterest Code: %lu\nRoomate: %s\n", info->studentName, info->studentID, info->interestCode, info->roommate->studentName); /**/

    /* printf("Student: %s\nRoommate: %s\n", info->studentName, info->roommate->studentName); /**/
}