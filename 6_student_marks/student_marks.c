#include <stdio.h>
#include <stdbool.h>

bool is_passing(int marks[5]) {
    for (int i = 0; i < 5; i++) {
        if (marks[i] < 40) {
            return false;
        }
    }
    return true;
}

int average_marks(int marks[5]) {
    int sum =  marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
    return sum / 5;
}

void print_division(int marks[5]) {
    int aggregate = average_marks(marks);

    if (aggregate > 75) {
        printf("You got a Distinction! Congrats!");
    }
    else if (aggregate > 60) {
        printf("You are in the First Div!");
    }
    else if (aggregate > 50) {
        printf("You are in the Second Div.");
    }
    else if (aggregate > 40) {
        printf("You are in the Third Div");
    }
    printf("\n");
}

int main() {
    int marks[5];
    printf("Enter 5 course marks: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
    }

    if (is_passing(marks)) {
        printf("\nYou Pass!\n");
    }
    else {
        printf("\nYou failed. :(\n");
        return 0;
    }

    print_division(marks);
    return 0;
}
