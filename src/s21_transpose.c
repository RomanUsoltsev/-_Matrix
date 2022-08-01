//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

matrix_t s21_transpose(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS) {
    new_matrix = s21_create_matrix(A->columns, A->rows);
    new_matrix.matrix_type = CORRECT_MATRIX;
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        new_matrix.matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    new_matrix.matrix_type = INCORRECT_MATRIX;
  }
  return new_matrix;
}
