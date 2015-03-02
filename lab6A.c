/*
Lamog, Robert
Lab 6A
01/01/2015
List words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

int main() {
    FILE *ipsum_file = NULL;
    // char buffer[101] = "\0";
    char word[100] = "\0";
    unsigned int is_next_paragraph = 0;
    unsigned int i = 0;
    
    ipsum_file = fopen("input.stdloremipsum.txt", "r");

    if(ipsum_file != NULL) {
        while (!feof(ipsum_file) || !is_next_paragraph) {
            // fgets(buffer, 100, ipsum_file);
            
            // if (buffer == NULL) break;
            // else if (buffer[0] == '\n') is_next_paragraph = 1;
            // else {
                
            // }
            
            fscanf(ipsum_file, "%100c", word);
            printf("%s", word);
        }
        fclose(ipsum_file);
    }
    
    printf("\n");
    return 0;
}