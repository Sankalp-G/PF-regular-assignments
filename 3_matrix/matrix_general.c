#include <stdio.h>

void get_matrix_values_from_user(int m, int n, int matrix[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("Enter %d numbers for row %d : ", n, i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void get_two_matrices_from_user(int m, int n, int matrix_a[m][n], int matrix_b[m][n]) {
    printf("\nEnter Values for matrix a:\n");
    get_matrix_values_from_user(m, n, matrix_a);
    printf("\n\n");
    printf("Enter Values for matrix b:\n");
    get_matrix_values_from_user(m, n, matrix_b);
}

void add_matrix(int m, int n, int matrix_a[m][n], int matrix_b[m][n], int result_matrix[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
}

void print_matrix(int m, int n, int matrix[m][n]) {
    for (int i = 0; i < m; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void main(){
    int m, n;
    printf("Enter the sizes for your two matrices (m, n) : ");
    scanf("%d%d", &m, &n);

    int matrix_a[m][n];
    int matrix_b[m][n];

    get_two_matrices_from_user(m, n, matrix_a, matrix_b);

    int added_matrix[m][n];
    add_matrix(m, n, matrix_a, matrix_b, added_matrix);

    print_matrix(m, n, added_matrix);
}