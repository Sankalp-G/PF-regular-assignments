#include <stdio.h>
#include <stdlib.h>

// convert numeric string to integer using atoi along with error handling
int to_num(char* num_str) {
    int num = atoi(num_str);
    if (num == 0) {
        fprintf(stderr, "Invalid Argument '%s', Argument must be non-zero integers.\n", num_str);
        exit(-2);
    }
    return num;
}

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void print_smallest_divisor(int num_1, int num_2) {
    int smaller_number = min(num_1, num_2);

    for (int i = 2; i <= smaller_number; i++) {
        // if i is divisible to both nums
        if (num_1 % i == 0 && num_2 % i == 0) {
            printf("Smallest divisor is: %d\n", i);
            return;
        }
    }

    printf("Smallest Divisor does not exist.\n");
}

void print_largest_divisor(int num_1, int num_2) {
    int smaller_number = min(num_1, num_2);

    for (int i = smaller_number; i >= 2; i--) {
        // if i is divisible to both nums
        if (num_1 % i == 0 && num_2 % i == 0) {
            printf("Largest divisor is: %d\n", i);
            return;
        }
    }

    printf("Largest Divisor does not exist.\n");
}

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 3) {
        printf("Invalid Argument count.\n");
        printf("Usage: executable <num_1> <num_2>\n");
        printf("Numbers must be non-zero\n");
        return -1;
    }

    int num_1 = to_num(argv[1]);
    int num_2 = to_num(argv[2]);

    print_smallest_divisor(num_1, num_2);

    print_largest_divisor(num_1, num_2);

    return 0;
}
