#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 2) {
        printf("Invalid argument count\n");
        printf("Usage: executable <num_to_be_converted>\n");
        return -1;
    }

    int input_num = atoi(argv[1]);
    if (input_num == 0) {
        printf("Argument must be a non-zero integer");
        return -2;
    }

    int result = 0;
    int power = 0;
    while (input_num) {
        // if not divisible by 10, aka when first digit is 1
        if (!(input_num % 10 == 0)) {
            result += pow(2, power);
        }
        input_num /= 10;
        power++;
    }

    printf("Decimal conversions is: %d\n", result);
}