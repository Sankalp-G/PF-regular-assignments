#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[20];
    char designation[20];
    char gender[10];
    char join_date[10];
    int salary;
};

void employee_constructor(struct Employee* employee, char* name, char* designation, char* gender, char* join_date, int salary) {
    strncpy(employee->name, name, 20);
    strncpy(employee->designation, designation, 20);
    strncpy(employee->gender, gender, 10);
    strncpy(employee->join_date, join_date, 10);

    employee->salary = salary;
}

// returns a pointer to an array of 10 employees
struct Employee* employee_array_10() {
    // dynamically allocating memory so that our poor employees don't get destroyed when the function returns
    struct Employee* employee_arr = (struct Employee*)calloc(sizeof(struct Employee), 10);

    employee_constructor(&employee_arr[0], "John", "Sys Admin", "male", "11/4/2017", 8900);
    employee_constructor(&employee_arr[2], "April", "Sys Architect", "female", "19/8/2020", 9630);
    employee_constructor(&employee_arr[1], "Jack", "IT", "male", "15/3/2018", 9370);
    employee_constructor(&employee_arr[3], "Jill", "DevOps", "female", "18/3/2018", 8213);
    employee_constructor(&employee_arr[4], "Romeo", "AI/ML", "male", "21/6/2019", 12312);
    employee_constructor(&employee_arr[5], "Juliet", "ML/AI", "female", "22/6/2019", 9932);
    employee_constructor(&employee_arr[6], "Superman", "Lead Dev", "male", "17/3/2009", 17343);
    employee_constructor(&employee_arr[7], "Jackie Chan", "Manager", "male", "2/7/2015", 13593);
    employee_constructor(&employee_arr[8], "Michelle Obama", "President", "female", "2/11/2010", 23432);
    employee_constructor(&employee_arr[9], "Salman Khan", "Jr. Dev", "male", "7/9/2022", 99999999);

    return employee_arr;
}

// counts number of employees in given employee array of size 10
int male_employee_count(struct Employee* employee_array) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        struct Employee employee = employee_array[i];
        if (strcmp(employee.gender, "male") == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    struct Employee* employee_array = employee_array_10();

    int male_count = male_employee_count(employee_array);

    printf("Employee gender count: \n");
    printf("Male: %d\n", male_count);
    printf("Female: %d\n\n", 10 - male_count);


    printf("The following employees have over 10,000 salary: \n");
    for (int i = 0; i < 10; i++) {
        if (employee_array[i].salary > 10000) {
            printf("%s - %s\n", employee_array[i].name, employee_array[i].designation);
        }
    }

    // freeing dynamically allocated memory
    free(employee_array);
}