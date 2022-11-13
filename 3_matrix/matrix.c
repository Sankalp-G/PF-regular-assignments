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

void print_float_matrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %g ", matrix[i][j]);
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

int determinant_3x3(int matrix[3][3]) {
    int term1 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    int term2 = -matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    int term3 = matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return term1 + term2 + term3;
}

int determinant_2x2(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

int minor_at_coordinate(int i, int j, int matrix[3][3]) {
    int minor_matrix[2][2];
    int mm_index_i = 0;
    int mm_index_j = 0;

    // enters values into minor_matrix array skipping row i and col j
    for (int row = 0; row < 3; row++) {
        if (row == i) { continue; }
        for (int col = 0; col < 3; col++) {
            if (col == j) { continue; }

            minor_matrix[mm_index_i][mm_index_j] = matrix[row][col];
            mm_index_j++;
        }
        mm_index_i++;
        mm_index_j = 0;
    }

    return determinant_2x2(minor_matrix);
}

int cofactor_at_coordinate(int i, int j, int matrix[3][3]) {
    int minor = minor_at_coordinate(i, j, matrix);

    if ((i + j) % 2 == 0) {
        return minor;
    }
    else {
        return -minor;
    }
}

void print_inverse_matrix(int matrix[3][3]) {

    int determinant = determinant_3x3(matrix);

    if (determinant == 0) { printf("\nInverse does not exist\n"); return; }

    int cofactor_matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cofactor_matrix[i][j] = cofactor_at_coordinate(i, j, matrix);
        }
    }

    int transpose_matrix[3][3];
    matrix_cols(cofactor_matrix, transpose_matrix);

    printf("\nInverse matrix is:\n");
    print_matrix(transpose_matrix);
    printf("Divided by %d\n\n", determinant);
}

void main(){
    int matrix_a[3][3];
    int matrix_b[3][3];

    get_two_matrices_from_user(matrix_a, matrix_b);

    int added_matrix[3][3];
    add_matrix(matrix_a, matrix_b, added_matrix);
    printf("\nAddition of matrix a and b is:\n");
    print_matrix(added_matrix);

    printf("\n\nFor matrix a: \n");
    print_saddle_point(matrix_a);
    print_inverse_matrix(matrix_a);

    printf("\n\nFor matrix b: \n");
    print_saddle_point(matrix_b);
    print_inverse_matrix(matrix_b);
}