//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

matrix_t Transpose(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS) {
    new_matrix = CreateMatrix(A->columns, A->rows);
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
