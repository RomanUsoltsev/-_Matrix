//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

matrix_t InverseMatrix(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (NullCheck(A) == SUCCESS) {
    double det = Determinant(A);
    double inverse_det = 1.0f / det;
    if (det > 0.000000001f && det != NAN) {
      matrix_t matrix_comp = CalcComplements(A);
      matrix_t matrix_comp_transpose = Transpose(&matrix_comp);
      new_matrix = MultNumber(&matrix_comp_transpose, inverse_det);
      RemoveMatrix(&matrix_comp);
      RemoveMatrix(&matrix_comp_transpose);
    } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  return new_matrix;
}
