// CS 539, HW 1B, Rob Lamog

#include <stdio.h>
#include <stdlib.h>

unsigned pages(unsigned, unsigned);

int die(const char* msg);

int main(){
    unsigned input1, input2;
    
    printf("Input the number of lines that can be printed on one page: ");
    if (!scanf("%u", &input1)) die("Input failure.\n");
    printf("Input the number of lines we want to print: ");
    if (!scanf("%u", &input2)) die("Input failure.\n");
    printf("The number of pages required for %u number of lines with %u lines per page is %u.\n", input2, input1, pages(input1, input2));
    
    return 0;
}

unsigned pages(unsigned linesPerPage, unsigned totalLines){
    unsigned retVal;
    
    if ((linesPerPage < 1) || (linesPerPage > 999)) die("Lines per page falls outside the range [1,999].\n");

    retVal = totalLines / linesPerPage;
    if ((totalLines % linesPerPage) != 0) retVal++;
    
    return retVal;
}

int die(const char* msg){
    printf("Fatal error: %s", msg);
    exit(EXIT_FAILURE);
}