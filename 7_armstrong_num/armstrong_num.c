#include <stdio.h>
#include <stdlib.h>

// returns length of given number
int num_length(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

// enters each digit of num into the given digits array
// entered numbers would be backwards i.e. from least significant to most significant digit
void separate_3_digits(int num, int digits[3]) {
    for (int i = 0; i < 3; i++) {
        digits[i] = num % 10;
        num /= 10;
    }
}

// cubes each digit and returns sum of cubes
int cube_sum(int digits[3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += digits[i] * digits[i] * digits[i];
    }
    return sum;
}

int main(int argc, char* argv[]) {
    // Argument handling
    if (argc != 2) {
        printf("Invalid Argument Count\n");
        printf("Usage: executable 3_digit_number\n");
        return -1;
    }

    int input_num = atoi(argv[1]);
    if (num_length(input_num) != 3) {
        printf("\nNumber must be of 3 digits\n");
        return -2;
    }
    //

    int digits[3];
    separate_3_digits(input_num, digits);

    if (cube_sum(digits) == input_num) {
        printf("\nNumber is an armstrong number!\n");
    }
    else {
        printf("\nNumber is not an armstrong number.\n");
    }

    return 0;
}