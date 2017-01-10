//CS 539, Alphabet File IO, Rob Lamog

#include <stdlib.h>
#include <stdio.h>

int die(const char* msg);

int main() {
    char fileName[64];
    FILE* fin;
    FILE* fout;
    char finChar;
    unsigned alphaCount[26] = {0};

    printf("Input file name: ");
    scanf("%s", fileName) == 1 || die("Input failure.");
    fin = fopen(fileName, "r");
    if (!fin){
        perror("Input file failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("Output file name: ");
    scanf("%s", fileName) == 1 || die("Input failure.");
    fout = fopen(fileName, "w");
    if (!fout){
        perror("Output file failed.");
        exit(EXIT_FAILURE);
    }
    
    while (finChar != EOF){
        finChar = fgetc(fin);
        if (finChar == 'a' || finChar == 'A') alphaCount[0] += 1;
        else if (finChar == 'b' || finChar == 'B') alphaCount[1] += 1;
        else if (finChar == 'c' || finChar == 'C') alphaCount[2] += 1;
        else if (finChar == 'd' || finChar == 'D') alphaCount[3] += 1;
        else if (finChar == 'e' || finChar == 'E') alphaCount[4] += 1;
        else if (finChar == 'f' || finChar == 'F') alphaCount[5] += 1;
        else if (finChar == 'g' || finChar == 'G') alphaCount[6] += 1;
        else if (finChar == 'h' || finChar == 'H') alphaCount[7] += 1;
        else if (finChar == 'i' || finChar == 'I') alphaCount[8] += 1;
        else if (finChar == 'j' || finChar == 'J') alphaCount[9] += 1;
        else if (finChar == 'k' || finChar == 'K') alphaCount[10] += 1;
        else if (finChar == 'l' || finChar == 'L') alphaCount[11] += 1;
        else if (finChar == 'm' || finChar == 'M') alphaCount[12] += 1;
        else if (finChar == 'n' || finChar == 'N') alphaCount[13] += 1;
        else if (finChar == 'o' || finChar == 'O') alphaCount[14] += 1;
        else if (finChar == 'p' || finChar == 'P') alphaCount[15] += 1;
        else if (finChar == 'q' || finChar == 'Q') alphaCount[16] += 1;
        else if (finChar == 'r' || finChar == 'R') alphaCount[17] += 1;
        else if (finChar == 's' || finChar == 'S') alphaCount[18] += 1;
        else if (finChar == 't' || finChar == 'T') alphaCount[19] += 1;
        else if (finChar == 'u' || finChar == 'U') alphaCount[20] += 1;
        else if (finChar == 'v' || finChar == 'V') alphaCount[21] += 1;
        else if (finChar == 'w' || finChar == 'W') alphaCount[22] += 1;
        else if (finChar == 'x' || finChar == 'X') alphaCount[23] += 1;
        else if (finChar == 'y' || finChar == 'Y') alphaCount[24] += 1;
        else if (finChar == 'z' || finChar == 'Z') alphaCount[25] += 1;
    }
    fclose(fin);
    
    fprintf(fout, "A %u\n", alphaCount[0]);
    fprintf(fout, "B %u\n", alphaCount[1]);
    fprintf(fout, "C %u\n", alphaCount[2]);
    fprintf(fout, "D %u\n", alphaCount[3]);
    fprintf(fout, "E %u\n", alphaCount[4]);
    fprintf(fout, "F %u\n", alphaCount[5]);
    fprintf(fout, "G %u\n", alphaCount[6]);
    fprintf(fout, "H %u\n", alphaCount[7]);
    fprintf(fout, "I %u\n", alphaCount[8]);
    fprintf(fout, "J %u\n", alphaCount[9]);
    fprintf(fout, "K %u\n", alphaCount[10]);
    fprintf(fout, "L %u\n", alphaCount[11]);
    fprintf(fout, "M %u\n", alphaCount[12]);
    fprintf(fout, "N %u\n", alphaCount[13]);
    fprintf(fout, "O %u\n", alphaCount[14]);
    fprintf(fout, "P %u\n", alphaCount[15]);
    fprintf(fout, "Q %u\n", alphaCount[16]);
    fprintf(fout, "R %u\n", alphaCount[17]);
    fprintf(fout, "S %u\n", alphaCount[18]);
    fprintf(fout, "T %u\n", alphaCount[19]);
    fprintf(fout, "U %u\n", alphaCount[20]);
    fprintf(fout, "V %u\n", alphaCount[21]);
    fprintf(fout, "W %u\n", alphaCount[22]);
    fprintf(fout, "X %u\n", alphaCount[23]);
    fprintf(fout, "Y %u\n", alphaCount[24]);
    fprintf(fout, "Z %u\n", alphaCount[25]);
    fclose(fout);
    if (ferror(fout)) die("Error writing or closing the output file.");

    return 0;
}

int die(const char* msg){
    printf("Fatal error: %s\n", msg);
    exit(EXIT_FAILURE);
}