//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

matrix_t s21_calc_complements(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS) {
    if (check_square_matrix(A) == SUCCESS) {
      new_matrix = s21_create_matrix(A->rows, A->columns);
      new_matrix.matrix_type = CORRECT_MATRIX;
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          int degree = sign_power(i, j);
          matrix_t minor = s21_create_matrix(A->rows - 1, A->columns - 1);
          matrix_minor(A->matrix, A->rows, i, j, minor.matrix);
          double det_minor = s21_determinant(&minor);
          new_matrix.matrix[i][j] = degree * det_minor;
          s21_remove_matrix(&minor);
        }
      }
    } else { new_matrix.matrix_type = INCORRECT_MATRIX;}
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  return new_matrix;
}

int sign_power(int row_i, int col_j) {
  int sign = 1;
  if ((row_i + col_j) % 2 != 0) {sign = -sign;}
  return sign;
}
