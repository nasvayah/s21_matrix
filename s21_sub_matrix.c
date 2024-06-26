#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_iscorrect_matrix(A) || s21_iscorrect_matrix(B))
    return INCORRECT_MATRIX;
  int exit = OK;
  if (A->rows != B->rows || A->columns != B->columns)
    exit = CALC_ERROR;
  else if (s21_create_matrix(A->rows, A->columns, result))
    exit = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        ;
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (isfinite(result->matrix[i][j]) == 0) exit = CALC_ERROR;
      }
    }
  }

  return exit;
}