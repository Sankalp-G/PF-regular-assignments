#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 2) {
        printf("Invalid argument count\n");
        printf("Usage: executable <amount_of_random_numbers>\n");
        return -1;
    }

    int amount_of_nums = atoi(argv[1]);
    if (amount_of_nums <= 0) {
        printf("Argument must be a positive integer\n");
        return -2;
    }

    printf("%d random integers are: \n", amount_of_nums);

    for (int i = 0; i < amount_of_nums; i++) {
        printf("%d\n", rand());
    }
    // rand() produces really big numbers by default (upto RAND_MAX)
    // you can use the modulus operator (%) to limit that
}