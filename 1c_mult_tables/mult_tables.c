#include <stdio.h>

void main(){
    int multiplier;
    printf("Enter the multiplier: ");
    scanf("%d", &multiplier);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", multiplier, i, multiplier * i);
    }
}