#include <stdio.h>

void get_matrix_values_from_user(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("Enter 3 numbers for row %d : ", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void get_two_matrices_from_user(int matrix_a[3][3], int matrix_b[3][3]) {
    printf("\nEnter Values for matrix a:\n");
    get_matrix_values_from_user(matrix_a);
    printf("\n\n");
    printf("Enter Values for matrix b:\n");
    get_matrix_values_from_user(matrix_b);
}

void add_matrix(int matrix_a[3][3], int matrix_b[3][3], int result_matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
}

void print_matrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

int min_in_arr(int length, int arr[length]) {
    int min = arr[0];
    for(int i = 0; i < length; i++) {
        int curr = arr[i];
        if (curr < min) { min = curr; }
    }
    return min;
}

int max_in_arr(int length, int arr[length]) {
    int max = arr[0];
    for(int i = 0; i < length; i++) {
        int curr = arr[i];
        if (curr > max) { max = curr; }
    }
    return max;
}

void main(){
    int matrix_a[3][3];
    int matrix_b[3][3];

    get_two_matrices_from_user(matrix_a, matrix_b);

    int added_matrix[3][3];
    add_matrix(matrix_a, matrix_b, added_matrix);

    print_matrix(added_matrix);
}