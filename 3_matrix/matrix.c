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

void matrix_cols(int matrix[3][3], int cols[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cols[j][i] = matrix[i][j];
        }
    }
}

int min_in_arr(int arr[3]) {
    int min = arr[0];
    for(int i = 0; i < 3; i++) {
        int curr = arr[i];
        if (curr < min) { min = curr; }
    }
    return min;
}

int max_in_arr(int arr[3]) {
    int max = arr[0];
    for(int i = 0; i < 3; i++) {
        int curr = arr[i];
        if (curr > max) { max = curr; }
    }
    return max;
}

void print_saddle_point(int matrix[3][3]) {
    int col_matrix[3][3];
    matrix_cols(matrix, col_matrix);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int row_min = min_in_arr(matrix[i]);
            int col_max = max_in_arr(col_matrix[j]);

            if (row_min == col_max) {
                printf("Saddle point in matrix is (%d) at index [%d, %d]\n", row_min, i + 1, j + 1);
                return;
            }
        }
    }
    printf("There is no saddle point in this array\n");
    return;
}

void main(){
    int matrix_a[3][3];
    int matrix_b[3][3];

    get_two_matrices_from_user(matrix_a, matrix_b);

    int added_matrix[3][3];
    add_matrix(matrix_a, matrix_b, added_matrix);
    printf("\nAddition of matrix a and b is:\n");
    print_matrix(added_matrix);

    printf("\nFor matrix a: \n");
    print_saddle_point(matrix_a);

    printf("\nFor matrix b: \n");
    print_saddle_point(matrix_b);
}