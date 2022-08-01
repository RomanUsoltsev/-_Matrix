//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

void RemoveMatrix(matrix_t *A) {
  if (A->matrix != NULL) {free(A->matrix); }
}
