/*
Lamog, Robert
Lab 3B
10/14/2014
Simple 2 unsigned int operand expression calculator using getchar() and putchar().
*/

#include <stdio.h>

int isAlphaChecker( char );
int isNumChecker( char );
int isOperator( char );
void buildExpression( char, unsigned int, unsigned int, int, int, int, char );
unsigned int makeOperand( char, unsigned int );
void add( unsigned int, unsigned int );
void subtract( unsigned int, unsigned int );
void multiply( unsigned int, unsigned int );
void divide( unsigned int, unsigned int );
void modulo( unsigned int, unsigned int );

int main() {
    char char_response = 0;
    unsigned int first_operand = 0;
    unsigned int second_operand = 0;
    int end_of_operand_flag = 0;
    int operand_success_flag = 0;
    int operation_success_flag = 0;
    char operation = 0;

    printf("Let's test some simple expressions.\nPlease input an expression: ");
    while ((char_response = getchar()) != EOF) {

        if (isAlphaChecker(char_response)) {
            if (char_response == 'N') {
                printf("Thanks for playing. Goodbye.\n");
                break;
            }
            if (char_response == 'Y') printf("Please input an expression: ");
        }
        buildExpression(char_response, first_operand, second_operand, end_of_operand_flag, operand_success_flag, operation_success_flag, operation);
    }
    
    return 0;
}

int isAlphaChecker( char is_alpha ) {
    if (((is_alpha >= 'a') && (is_alpha <= 'z')) || ((is_alpha >= 'A') && (is_alpha <= 'Z'))) return 1;
    return 0;
}
int isNumChecker( char is_num ) {
    if ((is_num >= '0') && (is_num <= '9')) return 1;
    return 0;
}
int isOperator( char is_operator ) {
    if ((is_operator == '+') || (is_operator == '-') || (is_operator == '*') || (is_operator == '/') || (is_operator == '%')) return 1;
    return 0;
}
void buildExpression( char ch, unsigned int x, unsigned int y, int endOfOperand, int operandSuccess, int operationSuccess, char operationX);
    putchar(ch);
    
    if (isNumChecker(ch)) {
        if (operandSuccess == 0) {
            x = makeOperand(ch, x);
            // printf("x = %d\n", x);
        }
        if (operandSuccess == 1) {
            y = makeOperand(ch, y);
            // printf("y = %d\n", y);
        }
        endOfOperand = 1;
    }
    if (isOperator(ch)) {
        if (operandSuccess == 1 && operationSuccess == 0) {
            operationX = ch;
        }
        operationSuccess++;
    }
    if (!isNumChecker(ch) && endOfOperand == 1) {
        operandSuccess++;
        endOfOperand = 0;
    }

    if (operandSuccess == 2 && operationSuccess == 1) {
        if (operationX == 0) printf("Invalid expression.\nWould you like to input another expression (Y/N)?\n");
        if (operationX == '+') add(x, y);
        if (operationX == '-') subtract(x, y);
        if (operationX == '*') multiply(x, y);
        if (operationX == '/') divide(x, y);
        if (operationX == '%') modulo(x, y);
    }
}
unsigned int makeOperand( char digit, unsigned int operand ) {
    return (operand * 10) + (digit - '0');
}
void add( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a + b;
    printf("%d + %d = %d\nWould you like to input another expression (Y/N)?\n", a, b, total);
}
void subtract( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    if (a >= b) {
        total =  a - b;
        printf("%d - %d = %d\nWould you like to input another expression (Y/N)?\n", a, b, total);
    } else printf("This calculator isn't capable of handling this expression.\nWould you like to input another expression (Y/N)?\n");
}
void multiply( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total =  a * b;
    printf("%d * %d = %d\nWould you like to input another expression (Y/N)?\n", a, b, total);
}
void divide( unsigned int a, unsigned int b ) {
    double total = 0.0;
    
    if (b == 0) printf("Undefined.\nWould you like to input another expression (Y/N)?\n");
    else {
        total = (a + 0.0) / b;
        printf("%d / %d = %g\n", a, b, total);
    }
}
void modulo( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a % b;
    printf("%d %% %d = %d\nWould you like to input another expression (Y/N)?\n", a, b, total);
}
