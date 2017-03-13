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
    Evaluates valid expression and prints solution, else, print invalid expression.
*/
void testExpression();
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
    subtract() returns a double because it is possible to evaluate a valid expression to a negative number.
    Returns a - b.
*/
double subtract(unsigned, unsigned);
/*
    Returns a * b.
*/
unsigned multiply(unsigned, unsigned);
/*
    divide() returns a double because it is possible to evaluate a valid expression to a fractional number.
    Returns -1 if b == 0 to catch special case of "Undefined.\n"
    Returns a / b.
*/
double divide(unsigned, unsigned);
/*
    Returns a % b.
*/
unsigned modulo(unsigned, unsigned);

int main(){
    int loop_again = 0;
    char c = NULL;

    do {
        printf("Enter a simple expression (a [+-*/%%] c): ");
        testExpression();
        printf("Would you like to enter a new expression (Y/N)? ");
        c = getchar();
        putchar(c);
        printf("\n");
        if (c == 'Y' || c == 'y'){
            loop_again = 1;
            getchar(); /* To clear the lingering '\n' */
        }
        else loop_again = 0;
    } while (loop_again);

    return 0;
}

void testExpression(){
    char c = NULL;
    char operation = NULL;
    unsigned first_operand = 0;
    unsigned second_operand = 0;
    unsigned number_of_operands = 0;
    unsigned number_of_operations = 0;
    int is_operand = 0;

    while ((c = getchar()) != EOF){
        if (c != '\n') putchar(c);

        if (isDigit(c)){
            if (number_of_operands == 0) first_operand = makeOperand(c, first_operand);
            if (number_of_operands == 1) second_operand = makeOperand(c, second_operand);
            is_operand = 1;
        }
        if (!isDigit(c) && is_operand == 1){
            number_of_operands++;
            is_operand = 0;
        }
        if (isValidOperator(c)){
            number_of_operations++;
            if (number_of_operands == 1) operation = c; /* The operation that follows the first operand is the only important operation. */
        }

        if (c == '\n'){
            if (!operation || number_of_operations != 1 || number_of_operands != 2){
                printf(" Invalid expression.\n");
                break;
            }

            if (operation == '+') printf(" = %d\n", add(first_operand, second_operand));
            if (operation == '-') printf(" = %d\n", subtract(first_operand, second_operand));
            if (operation == '*') printf(" = %d\n", multiply(first_operand, second_operand));
            if (operation == '/'){
                if (divide(first_operand, second_operand) == -1) printf(" = Undefined.\n");
                else printf(" = %f\n", divide(first_operand, second_operand));
            }
            if (operation == '%') printf(" = %d\n", modulo(first_operand, second_operand));

            break;
        }
    }
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