#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B){
    if(s21_iscorrect_matrix(A) || s21_iscorrect_matrix(B))
        return FAILURE;
    int exit = SUCCESS; 
    if (A->rows != B->rows || A->columns != B->columns)
        exit = FAILURE;
    else{
        for (int i = 0; i < A->rows; i++){
            for (int j = 0; j < A->columns; j++){;
                if (fabs(A->matrix[i][j] - B->matrix[i][j])*1e7 > 0.0)
                    exit = FAILURE;
            }
        }
    }
    return exit;  
}