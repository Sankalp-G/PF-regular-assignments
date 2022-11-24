#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_is_prime(int num) {
    if (is_prime(num)) {
        printf("The number is prime!\n");
    }
    else {
        printf("The number is not prime.\n");
    }
}

unsigned long factorial(int num) {
    if (num < 0) { return 0;} // factorials aren't defined for negative nums

    unsigned long result = 1;
    while(num > 0) {
        result *= num;
        num--;
    }
    return result;
}

void print_factorial(int num) {
    // factorials above 20 overflow even with longs
    if (num > 20) {
        printf("Factorial unknown (number too big)\n");
        return;
    }

    unsigned long fact = factorial(num);
    if (fact == 0) {
        printf("Factorial is not defined.\n");
    }
    else {
        printf("Factorial: %li\n", fact);
    }
}

// prints all prime factors for a number in the format:
// <factor> => <number of times factor occurred>
void print_prime_factors(int num) {
    printf("\nPrime factors are: \n");

    // edge case for negative numbers
    if (num < 0) {
        num /= -1;
        printf("-1 => 1\n");
    }

    int count = 0;
    int factor = 2;
    // loop until number is divided down to 1
    while (num != 1) {
        // if number is a factor increment counter and divide num
        if (num % factor == 0) {
            count++;
            num /= factor;
        }
        // if number is not a factor print current count, reset counter,
        // and then check for next factor
        else {
            // dont print if this factor number was never divisible
            if (count != 0) {
                printf("%d => %d times\n", factor, count);
            }

            count = 0;
            factor++;
        }
    }
    // print for the last factor
    printf("%d => %d times\n", factor, count);
}

int main(int argc, char* argv[]) {
    // Argument handling
    if (argc != 2) {
        printf("Invalid Argument Count\n");
        printf("Usage: executable <integer>\n");
        return -1;
    }

    int given_num = atoi(argv[1]);

    // print all the various pieces of info for the given number

    printf("\n===== Number Info =====\n");

    printf("Square root: %g\n", sqrt(given_num));

    printf("Square: %d\n", given_num * given_num);

    printf("Cube: %d\n", (int)pow(given_num, 3));

    print_is_prime(given_num);

    print_factorial(given_num);

    print_prime_factors(given_num);

    printf("=======================\n");

    return 0;
}