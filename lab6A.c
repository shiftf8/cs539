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
int ascii_alpha_check( struct word *, unsigned int, struct word *, unsigned int );
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
int word_sort( struct word *arrWords, unsigned int sizeOfarrWords ) {
    unsigned int i = 0;
    unsigned int sizeOfWordA = 0;
    unsigned int sizeOfWordB = 0;
    
    for (i; i < sizeOfarrWords; i++) {
        while (arrWords[i].letters[sizeOfWordA] != '\0') sizeOfWordA++;
        // printf("%d\n", sizeOfWordA);
        while (arrWords[i + 1].letters[sizeOfWordB] != '\0') sizeOfWordB++;
        // printf("%d\n", sizeOfWordB);

        if (ascii_alpha_check((arrWords + i), sizeOfWordA, (arrWords + i + 1), sizeOfWordB)) {
            // printf("%s\n", arrWords[i].letters);
            swap_words((arrWords + i), sizeOfWordA, (arrWords + i + 1), sizeOfWordB);
        }
    }
    
    i = 0;
    for (i; i < sizeOfarrWords; i++) {
        printf("%s\n", arrWords[i].letters);
    }
    
    return 1;
}
int ascii_alpha_check( struct word *wordA, unsigned int sizeOfWordA, struct word *wordB, unsigned int sizeOfWordB ) {
    unsigned int i = 0;
    
    if (sizeOfWordB >= sizeOfWordA) {
        for (i; i < sizeOfWordA; i++) {
            if (wordA->letters[i] != wordB->letters[i]) {
                if (wordA->letters[i] > wordB->letters[i]) return 1;
                if (wordA->letters[i] < wordB->letters[i]) return 0;
            }
        }
    } else {
        for (i; i < sizeOfWordB; i++) {
            if (wordA->letters[i] != wordB->letters[i]) {
                if (wordA->letters[i] > wordB->letters[i]) return 1;
                if (wordA->letters[i] < wordB->letters[i]) return 0;
            }
        }
    }
}
void swap_words( struct word *wordA, unsigned int sizeOfWordA, struct word *wordB, unsigned int sizeOfWordB ) {
    unsigned int i = 0;
    char tmpC = '\0';
    
    if (sizeOfWordB >= sizeOfWordA) {
        for (i; i < sizeOfWordB; i++) {
            tmpC = wordA->letters[i];
            wordA->letters[i] = wordB->letters[i];
            wordB->letters[i] = tmpC;
        }
    } else {
        for (i; i < sizeOfWordA; i++) {
            tmpC = wordA->letters[i];
            wordA->letters[i] = wordB->letters[i];
            wordB->letters[i] = tmpC;
        }
    }
}
