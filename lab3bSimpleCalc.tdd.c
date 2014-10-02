/*
Lamog, Robert
Lab 3B
10/14/2014
Simple 2 unsigned int operand expression calculator using getchar() and putchar().
*/

#include <stdio.h>

void simpleCalc();
unsigned int makeOperand( char, unsigned int );
int isNumChecker( char );
int isOperator( char );
void add(unsigned int, unsigned int);
void subtract(unsigned int, unsigned int);
void multiply(unsigned int, unsigned int);
void divide(unsigned int, unsigned int);
void modulo(unsigned int, unsigned int);

int main() {
    char response = 0;

    printf("Let's test some expressions.\n");
    while (response != '\n' || response != EOF) {
        simpleCalc();
        
        response = getchar();
        if (response != 'n' || response != 'N') {
            char c;
            
            while ((c = getchar()) != '\n' && c != '\n') {
                /* Trying to discard the buffer stream. */
            }
        }
        if (response == 'n' || response == 'N') break;
    }
    
    return 0;
}

void simpleCalc() {
    unsigned int x = 0; /* Left operand. */
    unsigned int y = 0; /* Right operand. */
    int endOfNumFlag = 0;
    int operandSuccess = 0;
    int operationSuccess = 0;
    char c = 0;
    char operation = 0;

    printf("Please enter an expression: ");

    while (c != EOF) {
        c = getchar();
        putchar(c);
        
        if (isNumChecker(c) == 1) {
            if (operandSuccess == 0) x = makeOperand(c, x);
            if (operandSuccess == 1) y = makeOperand(c, y);
            endOfNumFlag = 1;
        }
        if (isNumChecker(c) == 0) {
            if (endOfNumFlag == 1) {
                operandSuccess++;
                endOfNumFlag = 0;
            }
        }
        if (isOperator(c)) {
            if (operationSuccess == 0 && operandSuccess == 1) operation = c;
            operationSuccess++;
        }
        if (c == '\n') break;
    }
    
/*    printf("x = %d\ny = %d\nNum of Operands = %d\nOperation = %c\nNum of Operations = %d\n", x, y, operandSuccess, operation, operationSuccess);    */

    if (operandSuccess == 2 && operationSuccess == 1) {
        if (operation == '+') add(x, y);
        if (operation == '-') subtract(x, y);
        if (operation == '*') multiply(x, y);
        if (operation == '/') divide(x, y);
        if (operation == '%') modulo(x, y);
        if (operation == 0) printf("Invalid expression.\n");
    } else printf("Invalid expression.\n");
    
    printf("Would you like to enter another expression (Y/N)?\n");
}
unsigned int makeOperand( char c, unsigned int operand ) {
    return (operand * 10) + (c - '0');
}
int isNumChecker( char c ) {
    if ((c >= '0') && (c <= '9')) return 1;
    return 0;
}
int isOperator( char c ) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%')) return 1;
    return 0;
}
void add(unsigned int a, unsigned int b) {
    unsigned int total = 0;
    
    total = a + b;
    printf("%d + %d = %d\n", a, b, total);
}
void subtract(unsigned int a, unsigned int b) {
    unsigned int total = 0;
    
    if (a >= b) {
        total =  a - b;
        printf("%d - %d = %d\n", a, b, total);
    } else printf("This calculator isn't capable of handling this expression.\n");
}
void multiply(unsigned int a, unsigned int b) {
    unsigned int total = 0;
    
    total =  a * b;
    printf("%d * %d = %d\n", a, b, total);
}
void divide(unsigned int a, unsigned int b) {
    double total = 0.0;
    
    if (b == 0) printf("Undefined.\n");
    else {
        total = (a + 0.0) / b;
        printf("%d / %d = %g\n", a, b, total);
    }
}
void modulo(unsigned int a, unsigned int b) {
    unsigned int total = 0;
    
    total = a % b;
    printf("%d %% %d = %d\n", a, b, total);
}
