#include<stdio.h>

void main() {
    int operand1, operand2;
    printf("Enter your two operands: ");
    scanf("%d%d", &operand1, &operand2);

    int operator_choice;
    printf("Enter the operator choice:\n");
    printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n\n");
    scanf("%d", &operator_choice);

    int result;
    switch(operator_choice) {
        case 1:
            result = operand1 + operand2;
        case 2:
            result = operand1 - operand2;
        case 3:
            result = operand1 * operand2;
        case 4:
            result = operand1 / operand2;
    }

    printf("Your result is: %d\n", result);
}

