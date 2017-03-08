/*
Lamog-Doiel, Robert
Lab 3B
3/21/2017
Simple, 2 unsigned operand expression calculator using getchar() and putchar() for input/output of user input.
Valid operations include '+', '-', '*', '/', '%'.
*/

#include <stdio.h>

/*
    Uses getchar() and putchar() via loop to input/output user input.
    Analyzes input for valid expression which includes unsigned int, valid operator, unsigned int. e.g. a + b
    NOT white space dependent. e.g.     a%   b
    Evaluates valid expression and prints it, else, print "Invalid expression.\n"
*/
void testExpression();
/*
    My own isSpace().
    Return 1 if char is ' ', '\f', '\n', '\r', '\t', '\v'.
    Return 0 if char is NOT valid.
*/
int isSpace(char);
/*
    My own isDigit().
    Return 1 if char is in range of '0' to '9'.
    Return 0 if char is NOT in range.
*/
int isDigit(char);
/*
    Checks char for valid operator.
    Return 1 if char is '+', '-', '*', '/', '%'.
    Return 0 if char is NOT valid.
*/
int isValidOperator(char);
/*
    Converts char to unsigned int digit and appends it to existing unsigned int.
    Returns appended unsigned int.
*/
unsigned makeOperand(char, unsigned);
/*
    Returns a + b.
*/
unsigned add(unsigned, unsigned);
/*
    Returns a - b.
    subtract() returns an int because it is possible to evaluate a valid expression to a negative number.
*/
int subtract(unsigned, unsigned);
/*
    Returns a * b.
*/
unsigned multiply(unsigned, unsigned);
/*
    Returns -1 if b == 0 to catch special case of "Undefined.\n"
    Returns a / b.
    divide() returns a double because it is possible to evaluate a valid expression to a fractional number.
*/
double divide(unsigned, unsigned);
/*
    Returns a % b.
*/
unsigned modulo(unsigned, unsigned);

int main(){
    int loop_again;
    char input_char;

    do {
        printf("Enter a simple expression (a [+-*/%%] c): ");
        testExpression();
        printf("Would you like to enter a new expression (Y/N)? ");
        input_char = getchar();
        if (input_char == 'Y' || input_char == 'y'){
            putchar(input_char);
            loop_again = 1;
        } else loop_again = 0;
    } while (loop_again);

    return 0;
}

void testExpression(){
    char input_char, operation;
    unsigned first_operand = 0;
    unsigned second_operand = 0;
    unsigned number_of_operands = 0;
    unsigned number_of_operations = 0;
    int is_operand;

    while ((input_char = getchar()) != '\n' || input_char != EOF){
        putchar(input_char);

        if (!isSpace(input_char) && !isDigit(input_char) && !isValidOperator(input_char)){
            printf("Invalid expression.\n");
            break;
        }
        if (isDigit(input_char)){
            if (number_of_operands == 0) first_operand = makeOperand(input_char, first_operand);
            if (number_of_operands == 1) second_operand = makeOperand(input_char, second_operand);
            is_operand = 1;
        }
        if (!isDigit(input_char) && is_operand == 1){
            number_of_operands++;
            is_operand = 0;
        }
        if (isValidOperator(input_char)){
            if (number_of_operands == 1 && number_of_operations == 0) operation = input_char;
            number_of_operations++;
        }
    }

    if (number_of_operands == 2 && number_of_operations == 1){

    } else printf("Invalid expression.\n");
}
int isSpace(char c){
    if ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r') || (c == '\t') || (c == '\v')) return 1;
    return 0;
}
int isDigit(char c){
    if ((c >= '0') && (c <= '9')) return 1;
    return 0;
}
int isValidOperator(char c){
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%')) return 1;
    return 0;
}
unsigned makeOperand(char c, unsigned operand){
    return (operand * 10) + (c - '0');
}
unsigned add(unsigned a, unsigned b){
    return a + b;
}
int subtract(unsigned a, unsigned b){
    return a - b;
}
unsigned multiply(unsigned a, unsigned b){
    return a * b;
}
double divide(unsigned a, unsigned b){
    if (b == 0) return -1;
    return (a * 1.0) / b;
}
unsigned modulo(unsigned a, unsigned b){
    return a % b;
}