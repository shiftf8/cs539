/*
Lamog, Robert
Lab 3B
10/14/2014
Simple 2 unsigned int operand expression calculator using getchar() and putchar().
*/

#include <stdio.h>

int buildExpression( char );
int isNumChecker( char );
int isOperator( char );
unsigned int makeOperand( char, unsigned int );
void add( unsigned int, unsigned int );
void subtract( unsigned int, unsigned int );
void multiply( unsigned int, unsigned int );
void divide( unsigned int, unsigned int );
void modulo( unsigned int, unsigned int );

int main() {
    /*  @return -1 == Processing.
        @return 0 == Invalid expression.
        @return 1 == Valid expression.
    */
    int expressionState = -1;
    char response = 0;

    printf("Let's test some simple expressions.\nPlease input an expression: ");
    while (response != EOF) {
        response = getchar();
        if (isNumChecker(response)) {
            expressionState = buildExpression(response);
        }
        
        if (expressionState == 0) printf("Invalid expression.\nWould you like to input another expression (Y/N)?\n");
        if (expressionState == 1) printf("Would you like to input another expression (Y/N)?\n");
        if (response == 'N') {
            printf("Thanks for playing. Goodbye.\n");
            break;
        }
        if (response == 'Y') printf("Please input an expression: ");
    }
    
    return 0;
}

/*  It would be easy to assign operand into arr[operandSuccess] to support more than two operands.
    As well as, assigning operation into arr[operationSuccess].
*/
int buildExpression( char c ) {
    unsigned int x = 0; /* First operand. */
    unsigned int y = 0; /* Second operand. */
    int operand = 0;
    int endOfOperandFlag = 0;
    int operandSuccess = 0;
    int operationSuccess = 0;
    char operation = 0;

    putchar(c);
    
    if (isNumChecker(c) == 1) {
        operand = makeOperand(c, operand);
        if (operandSuccess == 0) x = operand;
        if (operandSuccess == 1) y = operand;
        endOfOperandFlag = 1;
    }
    if (isNumChecker(c) == 0) {
        if (endOfOperandFlag == 1) {
            operandSuccess++;
            endOfOperandFlag = 0;
        }
        if (isOperator(c)) {
            if (operandSuccess == 1 && operationSuccess == 0) operation = c;
            operationSuccess++;
        }
    }

    if (operandSuccess == 2 && operationSuccess == 1) {
        if (operation == 0) return 0;
        if (operation == '+') {
            add(x, y);
            return 1;
        }
        if (operation == '-') {
            subtract(x, y);
            return 1;
        }
        if (operation == '*') {
            multiply(x, y);
            return 1;
        }
        if (operation == '/') {
            divide(x, y);
            return 1;
        }
        if (operation == '%') {
            modulo(x, y);
            return 1;
        }
    }
//    return -1;
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
void add( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a + b;
    printf("%d + %d = %d\n", a, b, total);
}
void subtract( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    if (a >= b) {
        total =  a - b;
        printf("%d - %d = %d\n", a, b, total);
    } else printf("This calculator isn't capable of handling this expression.\n");
}
void multiply( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total =  a * b;
    printf("%d * %d = %d\n", a, b, total);
}
void divide( unsigned int a, unsigned int b ) {
    double total = 0.0;
    
    if (b == 0) printf("Undefined.\n");
    else {
        total = (a + 0.0) / b;
        printf("%d / %d = %g\n", a, b, total);
    }
}
void modulo( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a % b;
    printf("%d %% %d = %d\n", a, b, total);
}
