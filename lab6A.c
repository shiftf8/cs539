/*
Lamog, Robert
Lab 6A
01/01/2015
List words from a paragraph alphabetically. Disregard duplicates.
*/

#include <stdio.h>

struct word {
    char letters[100]; /* not accounting for words longer than 100 chars obviously */
} word;

int is_alpha_num_checker( char );
int word_sort( struct word *, unsigned int );
int ascii_alphabetical_check( struct word *, unsigned int, struct word *, unsigned int );
void swap_words( struct word *, unsigned int, struct word *, unsigned int );

int main() {
    FILE *ipsumFile = NULL;
    struct word arrWords[1024]; /* not accounting for possible overflow. this would infer a fairly lengthy paragraph. */
    unsigned int isEndOfWord = 0;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;

    ipsumFile = fopen("input.stdloremipsum.txt", "r");
    // ipsumFile = fopen("testinput.lab6a.txt", "r");

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
                    j = 0;
                    i++;
                }
            }
            if (c == '\n') break;
        }
        fclose(ipsumFile);

        if (!word_sort(&arrWords[0], i)) printf("alpha_sort: Unsuccessful!\n");
    }
    
    return 0;
} /* main */

int is_alpha_num_checker( char c ) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <='z')) || ((c >='0') && (c <= '9'))) return 1;
    return 0;
}
int word_sort( struct word *arrWords, unsigned int sizeOfarrWords ) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int min = 0;
    unsigned int sizeOfWordX = 0;
    unsigned int sizeOfWordMin = 0;
    
    for (i; i < sizeOfarrWords; i++) {
        while (arrWords[i].letters[sizeOfWordX] != '\0') sizeOfWordX++;
        while (arrWords[min].letters[sizeOfWordMin] != '\0') sizeOfWordMin++;

        for (j = i + 1; j < sizeOfarrWords; j++) {
            if (ascii_alphabetical_check((&arrWords[j]), sizeOfWordX, (&arrWords[min]), sizeOfWordMin)) min = j;
        }
        swap_words(&arrWords[i], sizeOfWordX, &arrWords[min], sizeOfWordMin);
        sizeOfWordX = 0;
        sizeOfWordMin = 0;
    }
    
    i = 0;
    for (i; i < sizeOfarrWords; i++) {
        printf("%s\n", arrWords[i].letters);
    }
    
    return 1;
}
int ascii_alphabetical_check( struct word *wordX, unsigned int sizeOfWordX, struct word *wordMin, unsigned int sizeOfWordMin ) {
    unsigned int i = 0;
    
    if (sizeOfWordMin >= sizeOfWordX) {
        for (i; i < sizeOfWordMin; i++) {
            if (wordX->letters[i] != wordMin->letters[i]) {
                if (wordX->letters[i] < wordMin->letters[i]) return 1;
            }
        }
    } else {
        for (i; i < sizeOfWordX; i++) {
            if (wordX->letters[i] != wordMin->letters[i]) {
                if (wordX->letters[i] < wordMin->letters[i]) return 1;
            }
        }
    }
    
    return 0;
}
void swap_words( struct word *wordX, unsigned int sizeOfWordX, struct word *wordMin, unsigned int sizeOfWordMin ) {
    unsigned int i = 0;
    char tmpC = '\0';
    
    if (sizeOfWordMin >= sizeOfWordX) {
        for (i; i < sizeOfWordMin; i++) {
            tmpC = wordX->letters[i];
            wordX->letters[i] = wordMin->letters[i];
            wordMin->letters[i] = tmpC;
        }
    } else {
        for (i; i < sizeOfWordX; i++) {
            tmpC = wordX->letters[i];
            wordX->letters[i] = wordMin->letters[i];
            wordMin->letters[i] = tmpC;
        }
    }
}
