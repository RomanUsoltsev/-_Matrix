//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {free(A->matrix); }
}
