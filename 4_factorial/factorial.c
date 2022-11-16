// Name:     Sankalp Gawali
// Roll No:  35
// Division: 1

#include <stdio.h>

int factorial_itr(int num) {
    if (num <= 1) { return 1; }

    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int factorial_rec(int num) {
    if (num <= 1) { return 1; }

    return factorial_rec(num - 1) * num;
}

void main(){
    int num;
    printf("Enter the number you want to factorial: ");
    scanf("%d", &num);

    printf("Iterative factorial: %d\n", factorial_itr(num));
    printf("Recursive factorial: %d\n", factorial_rec(num));
}