/*
Lamog, Robert
Lab 6A
01/01/2015
Break out words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

int main() {
    FILE *m_file = NULL;
    
    if((m_file = fopen("input.stdloremipsum.txt", "r")) != NULL) {
        printf("%s\n", m_file);
    } //else printf("Broke as hell.\n");
    
    return 0;
}