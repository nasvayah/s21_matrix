#include "s21_matrix.h"

void s21_fill_matrix(matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++)
      result->matrix[i][j] = i * result->columns + j;
  }
}

void s21_print_matrix(matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      if (j != 0) printf(" ");
      printf("%lf", result->matrix[i][j]);
    }
    printf("\n");
  }
}

int s21_iscorrect_matrix(matrix_t *A) {
  int exit = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    exit = INCORRECT_MATRIX;
  return exit;
}

int s21_minor(matrix_t *A, matrix_t *result, int iter, int jter) {
  int exit = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  if (exit) {
    return exit;
  }
  int i = 0;
  for (int m = 0; m < A->rows; m++) {
    if (m != iter) {
      int j = 0;
      for (int n = 0; n < A->columns; n++) {
        if (n != jter) {
          result->matrix[i][j] = A->matrix[m][n];
          j++;
        }
      }
      i++;
    }
  }
  return exit;
}