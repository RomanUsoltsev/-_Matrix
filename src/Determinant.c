//
// Created by roman on 27.01.2022.
//

#include "CMatrix.h"

double Determinant(matrix_t *A) {
  double det = NAN;
  if (NullCheck(A) == SUCCESS) {
    if (CheckSquareMatrix(A) == SUCCESS) { det = MatrixDet(A->matrix, A->rows);}
  }

  return det;
}

int CheckSquareMatrix(matrix_t *A) {
  int flag = SUCCESS;
  if (A->rows != A->columns) { flag = FAILURE; }

  return flag;
}

double MatrixDet(double **matrix, int size) {
  double det = 0;
  int degree = 1;
  if (size == 1) {
    return matrix[0][0];
  } else if (size == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    matrix_t new_matrix = CreateMatrix(size - 1, size - 1);
    new_matrix.matrix_type = CORRECT_MATRIX;
    for (int j = 0; j < size; j++) {
        MatrixMinor(matrix, size, 0, j, new_matrix.matrix);
      det = det + (degree * matrix[0][j] * MatrixDet(new_matrix.matrix, size - 1));
      degree = -degree;
    }
      RemoveMatrix(&new_matrix);
  }
  return det;
}

void MatrixMinor(double **matrix, int size, int rows, int columns, double **new_matrix) {
  int offsetRow = 0;
  int offsetCol = 0;
  for (int i = 0; i < size-1; i++) {
    if (i == rows) { offsetRow = 1; }
    offsetCol = 0;
    for (int j = 0; j < size-1; j++) {
      if (j == columns) { offsetCol = 1; }
      new_matrix[i][j] = matrix[i + offsetRow][j + offsetCol];
    }
  }
}
