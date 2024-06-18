#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_iscorrect_matrix(A)) return INCORRECT_MATRIX;

  int exit = OK;

  if (s21_create_matrix(A->columns, A->rows, result))
    exit = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    exit = CALC_ERROR;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0, 0, 0};
        exit = s21_minor(A, &minor, i, j);
        double det = 0;
        if (!exit) exit = s21_determinant(&minor, &det);
        if (!exit) result->matrix[i][j] = pow(-1, i + j) * det;
        s21_remove_matrix(&minor);
      }
    }
  }

  return exit;
}