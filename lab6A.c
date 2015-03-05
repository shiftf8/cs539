/*
Lamog, Robert
Lab 6A
01/01/2015
List words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

const char alpha_num_arr[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

typedef struct word {
    char letters[100];
} word;

int is_alpha_num_checker( char );

int alpha_sort( const alpha_num_arr, word *, unsigned int );

int main() {
    FILE *ipsum_file = NULL;
    word arr_words[1024];
    char str[100];
    unsigned int is_end_of_word = 0;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    ipsum_file = fopen("input.stdloremipsum.txt", "r");

    if (ipsum_file == NULL) perror("Error opening file.");
    else {
        while (c != feof(ipsum_file) || c != EOF) {
            c = fgetc(ipsum_file);
            // printf("%c", c);
            if (c == '\n') break;
            
            if (is_alpha_num_checker(c) == 1) {
                arr_words[i].letters[j] = c;
                is_end_of_word = 1;
                j++;
                // printf("%c", c);
            }
            if (is_alpha_num_checker(c) == 0) {
                if (is_end_of_word == 1) {
                    arr_words[i].letters[j] = '\0';
                    is_end_of_word = 0;
                    j = 0;
                    i++;
                    // printf("\n");
                }
            }
        }
        fclose(ipsum_file);

        if (!alpha_sort(alpha_num_arr[36], arr_words, i)) printf("alpha_sort: Unsuccessful!\n");
    }
    
    // printf("\n");
    return 0;
} /* main */

int is_alpha_num_checker( char c ) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <='z')) || ((c >='0') && (c <= '9'))) return 1;
    return 0;
}
int alpha_sort( const alpha_num_arr, word * word_list, unsigned int size_of_word_list ){
    word *tmp;
    char str[100];
    
    tmp = word_list;
    word_list = word_list + 1;
    word_list + 1;
    word_list = tmp;

    return 1;
}
