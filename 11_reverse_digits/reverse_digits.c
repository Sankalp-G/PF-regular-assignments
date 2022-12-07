#include <stdio.h>
#include <stdlib.h>

// taking modulus by 10 and dividing always gives the least significant digit,
// by which we can reverse the number
void print_num_digits(int num) {
    // negative number edge case
    if (num < 0) {
        printf("-");
        num *= -1;
    }

    while (num) {
        printf("%d", num % 10);
        num /= 10;
    }
}

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 2) {
        printf("Invalid argument count\n");
        printf("Usage: executable <num_to_be_reversed>\n");
        return -1;
    }

    int input_num = atoi(argv[1]);
    if (input_num == 0) {
        printf("Argument must be a non-zero integer");
        return -2;
    }

    printf("Reversed digits are: ");
    print_num_digits(input_num);
    printf("\n");
}