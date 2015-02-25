/*
Lamog, Robert
Lab 6A
01/01/2015
Break out words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

int main() {
    FILE *m_file = NULL;
    char buffer[100] = "\0";
    
    if((m_file = fopen("input.stdloremipsum.txt", "r")) != NULL) {
        while (!feof(m_file)) {
            if (fgets(buffer, 100, m_file) == NULL) break;
            fputs(buffer, stdout);
        }
        printf("\n");
        fclose(m_file);
    }
    
    return 0;
}