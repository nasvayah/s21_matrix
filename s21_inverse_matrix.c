#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_iscorrect_matrix(A)) return INCORRECT_MATRIX;

  int exit = OK;

  if (A->rows != A->columns)
    exit = CALC_ERROR;
  else if (A->rows == 1 && A->columns == 1) {
    if (A->matrix[0][0] != 0) {
      exit = s21_create_matrix(1, 1, result);
      if (!exit) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      }
    }
  } else {
    double det = 0;
    exit = s21_determinant(A, &det);
    if (det == 0) exit = CALC_ERROR;
    if (!exit && det != 0) {
      matrix_t calc_complements = {0, 0, 0};
      exit = s21_calc_complements(A, &calc_complements);
      if (!exit) {
        matrix_t transpose = {0, 0, 0};
        exit = s21_transpose(&calc_complements, &transpose);
        if (!exit) {
          s21_mult_number(&transpose, 1 / det, result);
        }
        s21_remove_matrix(&transpose);
      }
      s21_remove_matrix(&calc_complements);
    }
  }

  return exit;
}