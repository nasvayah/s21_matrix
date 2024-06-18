#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_iscorrect_matrix(A)) return INCORRECT_MATRIX;
  int exit = OK;
  if (s21_create_matrix(A->rows, A->columns, result))
    exit = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        ;
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (isfinite(result->matrix[i][j]) == 0) exit = CALC_ERROR;
      }
    }
  }

  return exit;
}