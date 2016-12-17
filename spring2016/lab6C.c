/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order pairing roommate id with same/similar interest code.
*/

#include "roommate.c"

int main() {
    FILE* input = NULL;
    struct Student_T* studentList[50];
    unsigned int studentX = 0;
    unsigned int lineN = 0;
    char str[512];

    input = fopen("input.lab6C.txt", "r");

    if (input != NULL) {
        studentList[studentX] = new_student(); /* Try to add initial student */
        if (studentList[studentX] == NULL) {
            printf("newAddress: Unsuccessful.\nProgram terminated.\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(str, sizeof(str), input)) {

            if (lineN == 0) set_student_name(studentList[studentX], str);

            ++lineN;
            break;
        }
    } else {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    fclose(input);

    print_roommate_info(studentList[studentX]);

    return 0;
}