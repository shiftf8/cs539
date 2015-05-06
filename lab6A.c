/*
Lamog, Robert
Lab 6A
01/01/2015
List words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

struct word {
    char letters[100];
    // int *pre_node = NULL;            might explore this kind of struct later
    // int *nxt_node = NULL;
} word;

int is_alpha_num_checker( char );
int word_sort( struct word *, unsigned int );

int main() {
    FILE *ipsum_file = NULL;
    struct word arr_words[1024]; /* not accounting for overflow */
    unsigned int is_end_of_word = 0;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;

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

        if (!word_sort(&arr_words[0], i)) printf("alpha_sort: Unsuccessful!\n");
    }
    
    return 0;
} /* main */

int is_alpha_num_checker( char c ) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <='z')) || ((c >='0') && (c <= '9'))) return 1;
    return 0;
}
int word_sort( struct word *word_list, unsigned int size_of_word_list ){
    struct word *current_position = word_list;
    struct word tmp;

    tmp = *word_list;
    word_list[0] = *(current_position + 1);
    word_list[1] = tmp;

    printf("%s\n", word_list[0].letters);
    printf("%s\n", word_list[1].letters);
    printf("%s\n", word_list[2].letters);
    printf("%s\n", word_list[3].letters);
    
    return 1;
}
