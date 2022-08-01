//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

matrix_t s21_inverse_matrix(matrix_t *A) {
  matrix_t new_matrix;
  new_matrix.matrix = NULL;
  if (null_check(A) == SUCCESS) {
    double det = s21_determinant(A);
    double inverse_det = 1.0f / det;
    if (det > 0.000000001f && det != NAN) {
      matrix_t matrix_comp = s21_calc_complements(A);
      matrix_t matrix_comp_transpose = s21_transpose(&matrix_comp);
      new_matrix = s21_mult_number(&matrix_comp_transpose, inverse_det);
      s21_remove_matrix(&matrix_comp);
      s21_remove_matrix(&matrix_comp_transpose);
    } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  } else { new_matrix.matrix_type = INCORRECT_MATRIX; }
  return new_matrix;
}
