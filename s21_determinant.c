#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result){
    if(s21_iscorrect_matrix(A))
        return INCORRECT_MATRIX;
    int exit = OK;
    if (A->rows != A->columns)
        return CALC_ERROR;

    if (A ->rows == 1)
        *result = A->matrix[0][0];
    else{
        for (int i = 0; i < A->columns; i++){
            double tmp_res = 0;
            matrix_t tmp_matr;
            exit = s21_create_minimatr(A, &tmp_matr, i);
            if (!exit){
                int tmp_exit = s21_determinant(&tmp_matr, &tmp_res);
                if (tmp_exit)
                    exit=tmp_exit;
                *result += pow(-1,i)*A->matrix[0][i]*tmp_res;
            }
            s21_remove_matrix(&tmp_matr);
        }
    }

    return exit;
}

