//
// Created by roman on 27.01.2022.
//
#include "CMatrix.h"

int EqMatrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (NullCheck(A) == SUCCESS && NullCheck(B) == SUCCESS) {
    flag = CheckSizeMatrix(A, B);
    if (flag == SUCCESS) { flag = CheckMatrixNumbers(A, B); }
  } else { flag = FAILURE; }
  return flag;
}

int CheckSizeMatrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) { flag = FAILURE; }
  return flag;
}

int CheckMatrixNumbers(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (MyFabs(A->matrix[i][j] - B->matrix[i][j]) > epsilon) { flag = FAILURE; break;}
    }
    if (flag != SUCCESS) { break;}
  }
  return flag;
}

int NullCheck(matrix_t *A) {
  int flag = SUCCESS;
  if (A != NULL) {
    if (A->matrix == NULL) { flag = FAILURE; }
    if (A->matrix_type == INCORRECT_MATRIX) { flag = FAILURE; }
  } else { flag = FAILURE; }

  return flag;
}

double MyFabs(double num) {
  return num = num < 0 ? -num : num;
}
