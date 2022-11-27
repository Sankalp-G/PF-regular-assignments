#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int factorial(int num) {
    int result = 1;
    while(num) {
        result *= num;
        num--;
    }
    return result;
}

// convert numeric string to integer using atoi along with error handling
int to_num(char* num_str) {
    int num = atoi(num_str);
    if (num == 0) {
        fprintf(stderr, "Invalid Argument '%s', Argument must be a non-zero integer.\n", num_str);
        exit(-2);
    }
    return num;
}

// to_num function along with factorial support
int extended_to_num(char* num_str) {
    char last_char = num_str[strlen(num_str) - 1];

    if (last_char == '!') {
        // atoi works even with the ! character at the end
        int num = to_num(num_str);
        return factorial(num);
    }
    else {
        return to_num(num_str);
    }
}

// checks if the given string is an operator
bool is_operator(char* opr_str) {
    char* operators[4] = {"+", "-", "/", "x"};

    for (int i = 0; i < 4; i++) {
        if (*operators[i] == *opr_str) return true;
    }
    return false;
}

// returns the resulting integer 
int calculate(int operand_1, char* operator, int operand_2) {
    // using string compare function to choose correct operator
    if      (strcmp(operator, "+") == 0) return operand_1 + operand_2;
    else if (strcmp(operator, "-") == 0) return operand_1 - operand_2;
    else if (strcmp(operator, "x") == 0) return operand_1 * operand_2;
    else if (strcmp(operator, "/") == 0) return operand_1 / operand_2;

    printf("Error: Invalid operand: %s", operator);
    exit(-2);
}

int main(int argc, char *argv[]) {
    // argument handling
    if (argc != 4) {
        printf("Invalid Argument Count.\n");
        printf("Usage: executable <operand_1> <operator> <operand_2>\n");
        printf("Numbers must be non-zero. To use factorials append the number with a exclamation mark (!)\n");
        return -1;
    }

    if (!is_operator(argv[2])) {
        printf("Invalid Argument '%s'.\n", argv[2]);
        printf("The second argument must be an operator. operators include: + - x /\n");
        return -1;
    }
    // -----

    char* operator = argv[2];

    int operand_1 = extended_to_num(argv[1]);
    int operand_2 = extended_to_num(argv[3]);

    printf("Result is: %d\n", calculate(operand_1, operator, operand_2));

    return 0;
}