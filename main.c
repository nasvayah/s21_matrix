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

void s21_fill_matrix(matrix_t *result){
    for (int i = 0; i < result->rows; i++){
        for (int j = 0; j < result->columns; j++)
            result->matrix[i][j] = i*result->columns + j;
    }
}

void s21_print_matrix(matrix_t *result){
    for (int i = 0; i < result->rows; i++){
        for (int j = 0; j < result->columns; j++){
            if (j != 0)
                printf(" ");
            printf("%lf", result->matrix[i][j]);
        }
        printf("\n");
    }
}
void s21_remove_matrix(matrix_t *A){
    if (A != NULL && A->matrix != NULL){
        free(A->matrix);
        A->matrix = NULL;
    }
}

int s21_iscorrect_matrix(matrix_t *A){
    int exit = OK;
    if (A == NULL || A-> matrix == NULL || A->rows < 1 || A->columns < 1)
        exit = INCORRECT_MATRIX;
    return exit;
}

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

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(s21_iscorrect_matrix(A) || s21_iscorrect_matrix(B))
        return INCORRECT_MATRIX;
    int exit = OK;
    if (A->rows != B->rows || A->columns != B->columns )
        exit = CALC_ERROR;
    else{
        if (s21_create_matrix(A->rows, A->columns, result))
            exit = INCORRECT_MATRIX;
        else{
            for (int i = 0; i < A->rows; i++){
                for (int j = 0; j < A->columns; j++){;
                    result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                }
            }
        }

    }
    return exit;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(s21_iscorrect_matrix(A) || s21_iscorrect_matrix(B))
        return INCORRECT_MATRIX;
    int exit = OK;
    if (A->rows != B->rows || A->columns != B->columns )
        exit = CALC_ERROR;
    else{
        if (s21_create_matrix(A->rows, A->columns, result))
            exit = INCORRECT_MATRIX;
        else{
            for (int i = 0; i < A->rows; i++){
                for (int j = 0; j < A->columns; j++){;
                    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                }
            }
        }

    }
    return exit;
}

int main(){
    matrix_t A = {0, 0, 0};
    matrix_t B = {0, 0, 0};
    matrix_t C = {0, 0, 0};
    s21_create_matrix(3, 3, &A);
    s21_fill_matrix(&A);

    s21_create_matrix(3, 3, &B);
    s21_fill_matrix(&B);
    B.matrix[0][0] = 0.1;
    s21_sub_matrix(&A, &B, &C);
    s21_print_matrix(&C);
    s21_remove_matrix(&C);
    return 0;
}