//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

matrix_t SumMatrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS && NullCheck(B) == SUCCESS) {
    int flag = CheckSizeMatrix(A, B);
    if (flag == SUCCESS) {
      new_matrix = CreateMatrix(A->rows, A->columns);
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
matrix_t SubMatrix(matrix_t *A, matrix_t *B) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS && NullCheck(B) == SUCCESS) {
    int flag = CheckSizeMatrix(A, B);
    if (flag == SUCCESS) {
      new_matrix = CreateMatrix(A->rows, A->columns);
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
