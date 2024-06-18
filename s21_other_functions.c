#include "s21_matrix.h"

void s21_fill_matrix(matrix_t *result){
    for (int i = 0; i < result->rows; i++){
        for (int j = 0; j < result->columns; j++)
            result->matrix[i][j] = i*result->columns + j;
    }
}

void s21_print_matrix(matrix_t *result){
    for (int i = 0; i < result->rows; i++){
        for (int j = 0; j < result->columns; j++){
            if (j != 0)
                printf(" ");
            printf("%lf", result->matrix[i][j]);
        }
        printf("\n");
    }
}

int s21_iscorrect_matrix(matrix_t *A){
    int exit = OK;
    if (A == NULL || A-> matrix == NULL || A->rows < 1 || A->columns < 1)
        exit = INCORRECT_MATRIX;
    return exit;
}
