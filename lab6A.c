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
int alpha_sort( struct word *, struct word * );

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
            // printf("%c", c);
            
            if (is_alpha_num_checker(c) == 1) {
                arrWords[i].letters[j] = c;
                isEndOfWord = 1;
                j++;
                // printf("%c", c);
            }
            if (is_alpha_num_checker(c) == 0) {
                if (isEndOfWord == 1) {
                    arrWords[i].letters[j] = '\0';
                    isEndOfWord = 0;
                    j = 0;
                    i++;
                    // printf("\n");
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
int word_sort( struct word *wordList, unsigned int sizeOfWordList ) {
    unsigned int i = 0;

    for (i; i < sizeOfWordList; i++) {
        if (alpha_sort((wordList + i), (wordList + i + 1))) printf("%s\n", wordList[i].letters);
    }
    
    return 1;
}
int alpha_sort( struct word *wordA, struct word *wordB ) {
    unsigned int i = 0;
    unsigned int sizeOfWordA = 0;
    unsigned int sizeOfWordB = 0;
    
    while (wordA->letters[sizeOfWordA] != '\0') sizeOfWordA++;
    // printf("%d\n", sizeOfWordA);
    while (wordB->letters[sizeOfWordB] != '\0') sizeOfWordB++;
    // printf("%d\n", sizeOfWordB);
    
    if (sizeOfWordB >= sizeOfWordA) {
        for (i; i < sizeOfWordA; i++) {
            if (wordA->letters[i] > wordB->letters[i]) return 1;
            if (wordA->letters[i] < wordB->letters[i]) return 0;
        }
    }
}

