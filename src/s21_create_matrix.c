//
// Created by roman on 27.01.2022.
//

#include "s21_matrix.h"

matrix_t s21_create_matrix(int rows, int columns) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  new_matrix.rows = rows;
  new_matrix.columns = columns;
  new_matrix.matrix_type = ZERO_MATRIX;
  if (rows > 0 && columns > 0) {
    new_matrix.matrix = (double **) malloc( rows * sizeof(double *) + rows * columns * sizeof(double));
    pointer_allocated(new_matrix.matrix, (double *)(new_matrix.matrix + rows), rows, columns);
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }

  return new_matrix;
}

void pointer_allocated(double **pointer_el, double *matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    pointer_el[i] = matrix + i * columns;
    for (int j = 0; j < columns; j++) {
      pointer_el[i][j] = 0;
    }
  }
}
