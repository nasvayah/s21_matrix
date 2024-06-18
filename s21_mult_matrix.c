#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(s21_iscorrect_matrix(A) || s21_iscorrect_matrix(B))
        return INCORRECT_MATRIX;
    int exit = OK;
    if (A->columns != B->rows)
        exit = CALC_ERROR;
    else if (s21_create_matrix(A->rows, B->columns, result)){
        exit = INCORRECT_MATRIX;
    }
    if (!exit){
        for (int i = 0; i < A->rows; i++){
            for (int j = 0; j < B->columns; j++){
                result->matrix[i][j] = 0;
                for (int k = 0; k < A->columns; k++)
                    result->matrix[i][j] += A->matrix[i][k]*B->matrix[k][j];
            }
        }
    }
    return exit;
}