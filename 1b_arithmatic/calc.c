#include<stdio.h>

// Using %g format specifier to truncate floating numbers

void main() {
    float operand1, operand2;
    printf("Enter your two operands: ");
    scanf("%g%g", &operand1, &operand2);

    int operator_choice;
    printf("Enter the operator choice:\n");
    printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n\n");
    scanf("%d", &operator_choice);

    float result;
    switch(operator_choice) {
        case 1:
            result = operand1 + operand2;
            break;
        case 2:
            result = operand1 - operand2;
            break;
        case 3:
            result = operand1 * operand2;
            break;
        case 4:
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid choice\n");
            return;
    }

    printf("Your result is: %g\n", result);
}
