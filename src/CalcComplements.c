//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

matrix_t CalcComplements(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS) {
    if (CheckSquareMatrix(A) == SUCCESS) {
      new_matrix = CreateMatrix(A->rows, A->columns);
      new_matrix.matrix_type = CORRECT_MATRIX;
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          int degree = SignPower(i, j);
          matrix_t minor = CreateMatrix(A->rows - 1, A->columns - 1);
            MatrixMinor(A->matrix, A->rows, i, j, minor.matrix);
          double det_minor = Determinant(&minor);
          new_matrix.matrix[i][j] = degree * det_minor;
            RemoveMatrix(&minor);
        }
      }
    } else { new_matrix.matrix_type = INCORRECT_MATRIX;}
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  return new_matrix;
}

int SignPower(int row_i, int col_j) {
  int sign = 1;
  if ((row_i + col_j) % 2 != 0) {sign = -sign;}
  return sign;
}
