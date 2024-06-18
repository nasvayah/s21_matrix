#ifndef S21_MATRIX
#define S21_MATRIX

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

void s21_fill_matrix(matrix_t *result);
void s21_print_matrix(matrix_t *result);
int s21_iscorrect_matrix(matrix_t *A);

#endif