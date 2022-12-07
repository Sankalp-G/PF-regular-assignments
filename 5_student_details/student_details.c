#include <stdio.h>

struct Student {
    char name[20];
    char branch[20];
    int age;
    int id;
};

void get_student_details_from_user(struct Student* student) {
    printf("Enter student details: \n");

    printf("Name: ");
    // using fgets to get string with spaces (for full names)
    fgets(student->name, 20, stdin);

    printf("Branch: ");
    fgets(student->branch, 20, stdin);

    printf("Age: ");
    scanf("%d", &student->age);

    printf("Id: ");
    scanf("%d", &student->id);

    // clear stdin buffer
    char delimiters[5];
    fgets(delimiters, 5, stdin);
}

void print_student_details(struct Student* student) {
    printf("Student details are: \n");

    printf("Name: %s", student->name);
    printf("Branch: %s", student->branch);
    printf("Age: %d\n", student->age);
    printf("Id: %d\n\n", student->id);
}

int main() {
    struct Student students[5];

    printf("Enter details for 5 students: \n\n");
    for (int i = 0; i < 5; i++) {
        get_student_details_from_user(&students[i]);
        printf("\n");
    }

    printf("======================================\n");

    printf("Received student details are: \n");
    for (int j = 0; j < 5; j++) {
        print_student_details(&students[j]);
    }
}