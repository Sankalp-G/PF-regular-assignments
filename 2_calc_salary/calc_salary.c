#include <stdio.h>

void main(){
    int base_sal;
    printf("Enter the multiplier: ");
    scanf("%d", &base_sal);

    int HRA = base_sal * 10 / 100;
    int TA  = base_sal * 5 / 100;
    int tax = base_sal * 2 / 100;

    int net_salary = base_sal - HRA - TA - tax;

    printf("Net salary is: %d\n", net_salary);
}