/*
Lamog, Robert
Lab 6A
01/01/2015
List words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

struct word {
    char letters[100]; /* not accounting for longer words. */
} word;

int is_alpha_num_checker( char );
int word_sort( struct word *, unsigned int );
int ascii_alphabetical_check( struct word *, struct word * );
void swap_words( struct word *, struct word * );

int main() {
    FILE *ipsumFile = NULL;
    struct word arrWords[1024]; /* not accounting for possible extra lengthy paragraph. */
    unsigned int isEndOfWord = 0;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

/*    ipsumFile = fopen("input.stdloremipsum.txt", "r"); /**/
/**/    ipsumFile = fopen("testinput.lab6a.txt", "r"); /* alternate test input */

    if (ipsumFile == NULL) perror("Error opening file.");
    else {
        while (c != feof(ipsumFile) || c != EOF) {
            c = fgetc(ipsumFile);

            if (is_alpha_num_checker(c) == 1) {
                arrWords[i].letters[j] = c;
                isEndOfWord = 1;
                j++;
            }
            if (is_alpha_num_checker(c) == 0) {
                if (isEndOfWord == 1) {
                    arrWords[i].letters[j] = '\0';
                    isEndOfWord = 0;
                    i++;
                    j = 0;
                }
            }
            if (c == '\n') break;
        }
        fclose(ipsumFile);

        if (!word_sort(&arrWords[0], i)) printf("word_sort: Unsuccessful!\n");
        else {
            for (k; k < i; k++) {
                printf("%s\n", arrWords[k].letters);
            }
        }
    }
    
    return 0;
} /* main */

int is_alpha_num_checker( char c ) {
    if (((c >='0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <='z'))) return 1;
    return 0;
}
int word_sort( struct word *arrWords, unsigned int sizeOfarrWords ) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int min = 0;

    for (i; i < sizeOfarrWords; i++) {
        min = i;
        
        for (j = i; j < sizeOfarrWords; j++) {
            if (ascii_alphabetical_check((&arrWords[min]), (&arrWords[j]))) min = j;
        }
        swap_words(&arrWords[min], &arrWords[i]);
    }
    
    return 1;
}
int ascii_alphabetical_check( struct word *wordMin, struct word *wordX ) {
    unsigned int i = 0;
    
    for (i; i < 100; i++) {
        if (wordMin->letters[i] < wordX->letters[i]) return 1;
        if (wordMin->letters[i] > wordX->letters[i]) return 0;
    }

    return 0;
}
void swap_words( struct word *wordMin, struct word *wordX ) {
    unsigned int i = 0;
    char tmpC = '\0';
    
    for (i; i < 100; i++) {
        tmpC = wordX->letters[i];
        wordX->letters[i] = wordMin->letters[i];
        wordMin->letters[i] = tmpC;
    }
}