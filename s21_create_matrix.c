#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result){
    if (result == NULL || rows < 1 || columns < 1)
        return INCORRECT_MATRIX;
    int exit = OK;
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)calloc(rows + rows*columns, sizeof(double));
    if (result->matrix == NULL)
        exit = INCORRECT_MATRIX;
    else{
        for (int i = 0; i < rows; i++){
            result->matrix[i] = (double *)(result->matrix + rows) + i*columns;
        }
    }
    return exit;
}

