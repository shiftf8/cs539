/*
Lamog-Doiel, Robert
Lab 3B
3/21/2017
Simple 2 unsigned int operand expression calculator using getchar() and putchar() for input/output of user input.
*/

#include <stdio.h>

void test_expression();
int is_number(char);
int is_valid_operator(char);
unsigned make_operand(char, unsigned);
void add(unsigned, unsigned);
void subtract(unsigned, unsigned);
void multiply(unsigned, unsigned);
void divide(unsigned, unsigned);
void modulo(unsigned, unsigned);

int main(){
    int loopAgain;
    char inputChar;

    // do {
    //     printf("Enter a simple expression (a (+-*/%%) c): ");
    //     test_expression();
    //     printf("Would you like to enter a new expression (Y/N)? ");
    //     inputChar = getchar();
    //     if (inputChar == 'Y' || inputChar == 'y') loopAgain = 1;
    //     else loopAgain = 0;
    // } while (loopAgain);

    divide(4, 2);

    return 0;
}

void test_expression(){
    char inputChar, operation;
    unsigned firstOperand, secondOperand;
    unsigned numberOfOperands;
    int isOperand;

    while ((inputChar = getchar()) != EOF){
        putchar(inputChar);

        if (is_number(inputChar)){
            if (numberOfOperands == 0) make_operand(c, firstOperand);
            if (numberOfOperands == 1) make_operand(c, secondOperand);
            isOperand++;
        }
    }
}
int is_number(char c){
    if ((c >= '0') && (c <= '9')) return 1;
    return 0;
}
int is_valid_operator(char c){
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%')) return 1;
    return 0;
}
unsigned make_operand(char c, unsigned operand){
    return (operand * 10) + (c - '0');
}
void add(unsigned a, unsigned b){
    printf(" = %d\n", (a + b));
}
void subtract(unsigned a, unsigned b){
    printf(" = %d\n", (a - b));
}
void multiply(unsigned a, unsigned b){
    printf(" = %d\n", (a * b));
}
void divide(unsigned a, unsigned b){
    if (b == 0) printf(" = Undefined\n");
    else printf(" = %f\n", ((a * 1.0) / b));
}
void modulo(unsigned a, unsigned b){
    printf(" = %d\n", (a % b));
}