/* Simple build const char [0-9 a-z] for cut and paste */

#include <stdio.h>

int main() {
    char arr[36];
    unsigned int i = 0;
    char letter = 'A';
    
    printf("const char alpha_num_arr[36] = {");
    for (i; i < 10; i++) {
        printf("\'%u\', ", i);
    }
    for (letter; letter <= 'Z'; letter++) {
        printf("\'%c\'", letter);
        if (letter != 'Z') printf(", ");
    }
    printf("};\n");
    
    return 0;
}