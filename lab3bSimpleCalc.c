/*
Lamog, Robert
Lab 3B
10/14/2014
Simple 2 unsigned int operand expression calculator using getchar() and putchar().
*/

#include <stdio.h>

void simpleCalc();
void makeOperand( char, unsigned int );
int isNumChecker( char );
int isOperator( char );

int main() {
    char response;

    printf("Let's test some simple unsigned integer expressions.\n");
    while (response != EOF) {
        char c;
        
        simpleCalc();
        printf("Would you like to enter another expression (Y/N)?\n");

        while ((c = getchar()) != '\n' && c != EOF) {
            /* trying to discard stdin stream */
        }
        
        response = getchar();
        if (response == 'n' || response == 'N') break;
    }
    
    return 0;
}

void simpleCalc(){
    unsigned int x =0; /* left operand */
    unsigned int y = 0; /* right operand */
    double d = 0.0; /* special division case solution */
    int endOfNumFlag = 0;
    int operandSuccess = 0;
    int operationSuccessFlag = 0;
    
    char c, operation;

    printf("Please enter an expression: ");
    while (c != '\n') {
        c = getchar();
        putchar(c);
        
        if (isNumChecker(c) == 1) {
            /*
                operandSuccess is "smart". first valid digit sets operandSuccess to 1.
                this way, it is somewhat aware of actual number of successful operands.
            */
            if (operandSuccess == 0) {
                makeOperand(c, x);
                operandSuccess++;
            }
            if (operandSuccess == 1) makeOperand(c, x);
            if (operandSuccess == 2) makeOperand(c, y);
            endOfNumFlag = 1;
        }
        if (isNumChecker(c) == 0) {
            if (endOfNumFlag == 1) {
                operandSuccess++;
                endOfNumFlag = 0;
            }
        }
    }

    c = getchar();
    printf("Blah!\n");
}
void makeOperand( char c, unsigned int operand ){
    operand = (operand * 10) + (c - '0');
}
int isNumChecker( char c ){
    if ((c >= '0') && (c <= '9')) return 1;
    return 0;
}
int isOperator( char c ){
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%')) return 1;
    return 0;
}
