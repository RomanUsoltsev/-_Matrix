//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS && null_check(B) == SUCCESS) {
    int flag = check_size_matrix(A, B);
    if (flag == SUCCESS) {
      new_matrix = s21_create_matrix(A->rows, A->columns);
      new_matrix.matrix_type = CORRECT_MATRIX;
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          new_matrix.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }

  return new_matrix;
}
matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS && null_check(B) == SUCCESS) {
    int flag = check_size_matrix(A, B);
    if (flag == SUCCESS) {
      new_matrix = s21_create_matrix(A->rows, A->columns);
      new_matrix.matrix_type = CORRECT_MATRIX;
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          new_matrix.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  return new_matrix;
}
