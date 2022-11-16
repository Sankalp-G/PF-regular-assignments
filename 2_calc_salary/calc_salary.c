// Name:     Sankalp Gawali
// Roll No:  35
// Division: 1

#include <stdio.h>

void main(){
    float base_sal;
    printf("Enter the base salary: ");
    scanf("%f", &base_sal);

    float HRA = base_sal * 10.0 / 100.0;
    float TA  = base_sal * 5.0 / 100.0;
    float tax = base_sal * 2.0 / 100.0;

    float net_salary = base_sal - HRA - TA - tax;

    printf("Net salary is: %.2f\n", net_salary);
}