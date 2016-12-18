/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order pairing roommate id with same/similar interest code.
*/

#include "roommate.c"

int main() {
    FILE* input = NULL;
    struct Student_T *studentList[50];
    unsigned int studentX = 0;
    unsigned int lineN = 0;
    char str[512];

    studentList[studentX] = new_student();
    if (studentList[studentX] == NULL) {
        printf("newAddress: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    input = fopen("input.lab6C.txt", "r");

    if (input != NULL) {
        while (fgets(str, sizeof str, input)) {
            if (lineN == 0) set_student_name(studentList[studentX], str);
            if (lineN == 1) set_id(studentList[studentX], str);
            if (lineN == 2) set_interest_code(studentList[studentX], str);
            ++lineN;
            if (str[0] == '\n') {
                lineN = 0;
                studentList[++studentX] = new_student();
                if (studentList[studentX] == NULL) {
                    printf("newAddress: Unsuccessful.\nProgram terminated.\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
    } else {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    fclose(input);

    print_roommate_info(studentList[1]);

    return 0;
}