//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

matrix_t MultNumber(matrix_t *A, double number) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS) {
    new_matrix = CreateMatrix(A->rows, A->columns);
    new_matrix.matrix_type = CORRECT_MATRIX;
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        new_matrix.matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }

  return new_matrix;
}
matrix_t MultMatrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS && NullCheck(B) == SUCCESS) {
    if (CheckMult(A, B) == SUCCESS) {
      new_matrix = CreateMatrix(A->rows, B->columns);
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

int CheckMult(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->columns != B->rows) { flag = FAILURE; }
  return flag;
}
