#ifndef S21_MATRIX
#define S21_MATRIX

#include <stdio.h>
#include <stdlib.h>
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

#endif