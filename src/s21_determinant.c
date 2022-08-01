//
// Created by roman on 27.01.2022.
//

#include "s21_matrix.h"

double s21_determinant(matrix_t *A) {
  double det = NAN;
  if (null_check(A) == SUCCESS) {
    if (check_square_matrix(A) == SUCCESS) {det = matrix_det(A->matrix, A->rows);}
  }

  return det;
}

int check_square_matrix(matrix_t *A) {
  int flag = SUCCESS;
  if (A->rows != A->columns) { flag = FAILURE; }

  return flag;
}

double matrix_det(double **matrix, int size) {
  double det = 0;
  int degree = 1;
  if (size == 1) {
    return matrix[0][0];
  } else if (size == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    matrix_t new_matrix = s21_create_matrix(size - 1, size - 1);
    new_matrix.matrix_type = CORRECT_MATRIX;
    for (int j = 0; j < size; j++) {
      matrix_minor(matrix, size, 0, j, new_matrix.matrix);
      det = det + (degree * matrix[0][j] * matrix_det(new_matrix.matrix, size - 1));
      degree = -degree;
    }
    s21_remove_matrix(&new_matrix);
  }
  return det;
}

void matrix_minor(double **matrix, int size, int rows, int columns, double **new_matrix) {
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
