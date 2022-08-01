//
// Created by roman on 27.01.2022.
//
#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (null_check(A) == SUCCESS && null_check(B) == SUCCESS) {
    flag = check_size_matrix(A, B);
    if (flag == SUCCESS) { flag = check_matrix_numbers(A, B); }
  } else { flag = FAILURE; }
  return flag;
}

int check_size_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) { flag = FAILURE; }
  return flag;
}

int check_matrix_numbers(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (my_fabs(A->matrix[i][j] - B->matrix[i][j]) > epsilon) { flag = FAILURE; break;}
    }
    if (flag != SUCCESS) { break;}
  }
  return flag;
}

int null_check(matrix_t *A) {
  int flag = SUCCESS;
  if (A != NULL) {
    if (A->matrix == NULL) { flag = FAILURE; }
    if (A->matrix_type == INCORRECT_MATRIX) { flag = FAILURE; }
  } else { flag = FAILURE; }

  return flag;
}

double my_fabs(double num) {
  return num = num < 0 ? -num : num;
}
