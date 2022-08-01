//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

matrix_t s21_mult_number(matrix_t *A, double number) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS) {
    new_matrix = s21_create_matrix(A->rows, A->columns);
    new_matrix.matrix_type = CORRECT_MATRIX;
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        new_matrix.matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }

  return new_matrix;
}
matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS && null_check(B) == SUCCESS) {
    if (check_mult(A, B) == SUCCESS) {
      new_matrix = s21_create_matrix(A->rows, B->columns);
      new_matrix.matrix_type = CORRECT_MATRIX;

      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->columns; ++j) {
          for (int k = 0; k < A->columns; ++k) {
            new_matrix.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }

  return new_matrix;
}

int check_mult(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->columns != B->rows) { flag = FAILURE; }
  return flag;
}
