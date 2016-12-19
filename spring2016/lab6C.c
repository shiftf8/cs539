/*
Lamog, Robert
Lab 6C
06/02/2016
Dynamically input names, id numbers and interest codes (0-50), and output based on student id in ascending order pairing roommate id with same/similar interest code.
*/

#include "roommate.c"

int main() {
    FILE *input = NULL;
    struct Student_T *studentList[50];
    unsigned int studentX = 0;
    unsigned int lineN = 0;
    char str[512];
    unsigned int i = 0;

    input = fopen("input.lab6C.txt", "r");

    if (input != NULL) {
        while (fgets(str, sizeof str, input)) {
            if (lineN == 0) {
                studentList[studentX] = new_student();
                if (studentList[studentX] == NULL) {
                    printf("newAddress: Unsuccessful.\nProgram terminated.\n");
                    exit(EXIT_FAILURE);
                }

                set_student_name(studentList[studentX], str);
            }
            if (lineN == 1) set_id(studentList[studentX], str);
            if (lineN == 2) {
                set_interest_code(studentList[studentX], str);
                ++studentX;
                if (studentX > 50) {
                    --studentX;
                    break;
                }
            }

            ++lineN;
            if (str[0] == '\n') lineN = 0;
        }
    } else {
        perror("fopen: Unsuccessful.\nProgram terminated.\n");
        exit(EXIT_FAILURE);
    }

    fclose(input);

    // printf("%u\n", studentX);

    // set_roommate(studentList + 2, 48);
    // print_roommate_info(studentList[2]);

    roommate_sort(studentList, studentX);
    set_next_roommate(studentList, studentX);

    for (i; i < studentX; ++i) {
        print_roommate_info(studentList[i]);
    }

    return 0;
}