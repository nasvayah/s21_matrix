#include "s21_matrix.h"


int main(){
    matrix_t A = {0, 0, 0};
    matrix_t B = {0, 0, 0};
    matrix_t C = {0, 0, 0};
    s21_create_matrix(3, 3, &A);
    s21_fill_matrix(&A);

    s21_create_matrix(3, 3, &B);
    s21_fill_matrix(&B);
    A.matrix[0][0] = 1;
    s21_print_matrix(&A);
    //s21_print_matrix(&B);
    double x = 0;

    printf("%d\n", s21_determinant(&A, &x));
    printf("%lf", x);
    // s21_print_matrix(&C);
    s21_remove_matrix(&C);
    return 0;
}