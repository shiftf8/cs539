/*
Lamog, Robert
Lab 3B
10/14/2014
Simple 2 unsigned int operand expression calculator using getchar() and putchar().
*/

#include <stdio.h>

int isNumChecker( char );
int isOperator( char );
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
    int operand_success = 0;
    int operation_success = 0;
    char operation = 0;

    printf("Let's test some simple expressions. Type \'N\' at any time to exit.\nPlease input an expression: ");
    while ((char_response = getchar()) != EOF) {
        putchar(char_response);

        if (char_response == 'N') {
            printf("\nThanks for playing. Goodbye.\n");
            break;
        }
        if (isNumChecker(char_response)) {
            if (isNumChecker(char_response)) {
                if (operand_success == 0) {
                    first_operand = makeOperand(char_response, first_operand);
                    // printf("\nfirst_operand = %d\n", first_operand);
                }
                if (operand_success == 1) {
                    second_operand = makeOperand(char_response, second_operand);
                    // printf("\nsecond_operand = %d\n", second_operand);
                }
                end_of_operand_flag = 1;
            }
        }
        if (!isNumChecker(char_response) && end_of_operand_flag == 1) {
            operand_success++;
            end_of_operand_flag = 0;
        }
        if (isOperator(char_response)) {
            if (operation_success == 0 && operand_success == 1) operation = char_response;
            // printf ("\noperator = %c\n", operation);
            operation_success++;
        }
        if (char_response == '\n') {
            // printf("Successful operands = %d\nSuccessful operations = %d\n", operand_success, operation_success);
            if (operation == 0 || operation_success > 1) printf("Invalid expression.\nPlease input a valid expression: ");
            if (operand_success == 2 && operation_success == 1) {
                if (operation == '+') add(first_operand, second_operand);
                if (operation == '-') subtract(first_operand, second_operand);
                if (operation == '*') multiply(first_operand, second_operand);
                if (operation == '/') divide(first_operand, second_operand);
                if (operation == '%') modulo(first_operand, second_operand);
            }

            /* Reset all variables */
            first_operand = 0;
            second_operand = 0;
            end_of_operand_flag = 0;
            operand_success = 0;
            operation_success = 0;
            operation = 0;
        }
    }
    
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
unsigned int makeOperand( char digit, unsigned int operand ) {
    return (operand * 10) + (digit - '0');
}
void add( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a + b;
    printf("%d + %d = %d\nPlease input an expression: ", a, b, total);
}
void subtract( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    if (a >= b) {
        total =  a - b;
        printf("%d - %d = %d\nPlease input an expression: ", a, b, total);
    } else printf("This calculator isn't capable of handling negative numbers.\nPlease input an expression: ");
}
void multiply( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total =  a * b;
    printf("%d * %d = %d\nPlease input an expression: ", a, b, total);
}
void divide( unsigned int a, unsigned int b ) {
    double total = 0.0;
    
    if (b == 0) printf("Undefined.\nPlease input an expression: ");
    else {
        total = (a + 0.0) / b;
        printf("%d / %d = %g\nPlease input an expression: ", a, b, total);
    }
}
void modulo( unsigned int a, unsigned int b ) {
    unsigned int total = 0;
    
    total = a % b;
    printf("%d %% %d = %d\nPlease input an expression: ", a, b, total);
}
