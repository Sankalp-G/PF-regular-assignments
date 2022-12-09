#include <stdio.h>
#include <stdbool.h>

int string_length(char* string) {
    int result = 0;
    while (*string != '\0') {
        result++;
        string++;
    }
    return result;
}

bool is_palindrome(char* string) {
    int length = string_length(string);

    int l_limit = 0;
    int r_limit = length - 1;

    while (l_limit < r_limit) {
        if (string[l_limit] != string[r_limit]) { return false; }
        l_limit++;
        r_limit--;
    }
    return true;
}

int main(int argc, char* argv[]) {
    // argument handling
    if (argc != 2) {
        printf("Invalid argument count\n");
        printf("Usage: executable <string>\n");
        return -1;
    }

    char* input_string = argv[1];

    printf("Length is: %d\n", string_length(input_string));

    if (is_palindrome(input_string)) {
        printf("String is a palindrome!\n");
    }
    else {
        printf("String is not a palindrome.\n");
    }
}