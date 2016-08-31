/*
Lamog, Robert
Lab 6A
01/01/2015
Dynamically create a list of words from a paragraph alphabetically utilizing pointers to structs. Disregard duplicate words. Print line numbers of each word occurrence.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Word {
    char letters[100]; /* not accounting for longer words. */
    unsigned int lineNumber;
} word;

int is_alpha_num_checker( char );
int word_bubble_sort( word **, unsigned int );
int ascii_alphabetical_check( word *, word * );
void swap_words( word *, word * );
int is_next_duplicate( word *, word * );

int main() {
    FILE *input = NULL;
    word *arrWords[1024]; /* not accounting for particularly lengthy paragraphs. not as dynamic as i would like but works for now. */
    unsigned int lineN = 1; /* line number count */
    unsigned int isEndOfWord = 0;
    char c = '\0';
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

/*    input = fopen("input.shortloremipsum.txt", "r"); /**/
/**/    input = fopen("testinput.lab6a.txt", "r"); /* alternate test input */

    if (input == NULL) {
        perror("Error opening file.\nProgram terminated!\n");
        exit(EXIT_FAILURE);
    } else {
        while ((c = fgetc(input)) != EOF) {
            c = tolower(c);

            if (is_alpha_num_checker(c) == 1) {
                if (isEndOfWord == 0) {
                    arrWords[i] = (word *) malloc(sizeof(word));
                    if (arrWords[i] == NULL) {
                        printf("malloc: Unsuccessful.\nProgram terminated!\n");
                        exit(EXIT_FAILURE);
                    }
                }
                arrWords[i]->letters[j] = c;
                isEndOfWord = 1;
                j++;
            }
            if (is_alpha_num_checker(c) == 0) {
                if (isEndOfWord == 1) {
                    arrWords[i]->letters[j] = '\0';
                    arrWords[i]->lineNumber = lineN;
                    isEndOfWord = 0;
                    i++;
                    j = 0;
                    if (i > 1024) {
                        printf("You've written an exceptionally long paragraph which this program was not adequately designed to handle.\nProgram terminated!\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
            if (c == '\n') lineN++;
        }
        fclose(input);

        if (!word_bubble_sort(arrWords, i)) {
            printf("word_bubble_sort: Unsuccessful!\nProgram terminated!\n");
            exit(EXIT_FAILURE);
        } else {
            for (k; k < i; k++) {
                printf("%d ", arrWords[k]->lineNumber);
                if (k < i - 1) {
                    if (!is_next_duplicate(arrWords[k], arrWords[k + 1])) {
                        printf("- %s\n", arrWords[k]->letters);
                    }
                }
                if (k == i - 1) printf(" - %s\n", arrWords[k]->letters);
                free(arrWords[k]);
                arrWords[k] = NULL;
            }
        }
    }
    
    return 0;
} /* main */

int is_alpha_num_checker( char c ) {
    if (((c >='0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <='z'))) return 1;
    return 0;
}
int word_bubble_sort( word **arrWords, unsigned int sizeOfarrWords ) {
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int min = 0;

    for (i; i < sizeOfarrWords; i++) {
        min = i;
        
        for (j = i; j < sizeOfarrWords; j++) {
            if (ascii_alphabetical_check(arrWords[min], arrWords[j])) min = j;
        }
        swap_words(arrWords[min], arrWords[i]);
    }
    
    return 1;
}
int ascii_alphabetical_check( word *wordMin, word *wordX ) {
    unsigned int i = 0;
    
    for (i; i < 100; i++) {
        if (wordMin->letters[i] > wordX->letters[i]) return 1;
        if (wordMin->letters[i] < wordX->letters[i]) return 0;
    }

    return 0;
}
void swap_words( word *wordMin, word *wordX ) {
    unsigned int i = 0;
    unsigned int tmpLineNumber = 0;
    char tmpC = '\0';
    
    for (i; i < 100; i++) {
        tmpC = wordX->letters[i];
        wordX->letters[i] = wordMin->letters[i];
        wordMin->letters[i] = tmpC;
    }

    tmpLineNumber = wordX->lineNumber;
    wordX->lineNumber = wordMin->lineNumber;
    wordMin->lineNumber = tmpLineNumber;
}
int is_next_duplicate( word *wordX, word *wordNext ) {
    unsigned int i = 0;
    
    for (i; i < 100; i++) {
        if (wordX->letters[i] != wordNext->letters[i]) return 0;
    }
    return 1;
}
