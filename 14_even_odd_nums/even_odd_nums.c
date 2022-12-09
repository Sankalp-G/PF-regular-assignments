#include <stdio.h>
#include <stdlib.h>

// convert numeric string to integer using atoi along with error handling
int to_num(char* num_str) {
    int num = atoi(num_str);
    if (num == 0) {
        fprintf(stderr, "Invalid Argument '%s', Arguments must be non-zero integers.\n", num_str);
        exit(-2);
    }
    return num;
}

int main(int argc, char* argv[]) {
    // argument handling
    if (argc <= 1) {
        printf("Invalid argument count\n");
        printf("Usage: executable <nums> ...\n");
        return -1;
    }

    printf("Even numbers: \n");
    for (int i = 1; i < argc; i++) {
        int num = to_num(argv[i]);

        // print num if even
        if (num % 2 == 0) {
            printf("%d\n", num);
        }
    }

    printf("\nOdd numbers: \n");
    for (int j = 1; j < argc; j++) {
        int num = to_num(argv[j]);

        // print num if odd
        if (num % 2 != 0) {
            printf("%d\n", num);
        }
    }
}