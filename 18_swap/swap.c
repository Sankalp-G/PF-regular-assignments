// Name:     Sankalp Gawali
// Roll No:  35
// Division: 1

#include <stdio.h>

void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    // print values here since swapped nums cannot be accessed outside
    printf("Value of a: %d, Value of b: %d\n\n", a, b);
}

void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int num_a, num_b;
    printf("Enter num a and num b: ");
    scanf("%d%d", &num_a, &num_b);

    printf("Swap by value:\n");
    swap_by_value(num_a, num_b);

    printf("Swap by reference:\n");
    swap_by_reference(&num_a, &num_b);
    printf("Value of a: %d, Value of b: %d\n\n", num_a, num_b);

}