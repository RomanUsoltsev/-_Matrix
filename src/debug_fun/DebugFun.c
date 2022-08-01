//
// Created by roman on 28.01.2022.
//

#include "DebugFun.h"

#define DIVIDER 100000000
void output_matrix(matrix_t *matrix) {
  if (matrix->matrix != NULL) {
    for (int j = 0; j < matrix->rows; j++) {
      for (int i = 0; i < matrix->columns; i++) {
        if (i + 1 != matrix->columns) {
          printf("|%12.8f| ", matrix->matrix[j][i]);
        } else {
          printf("|%12.8f|", matrix->matrix[j][i]);
        }
      }
      if (j + 1!= matrix->rows) {
        printf("\n");
      }
    }
  }
}

void rand_fill(matrix_t *A, matrix_t *B, int mode, unsigned int seed, double error, int typo) {
  if (mode == SAME && A->matrix != NULL && B->matrix != NULL) {
    for (int j = 0; j < A->rows; ++j) {
      for (int k = 0; k < A->columns; ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        A->matrix[j][k] = r;
        B->matrix[j][k] = r + error;
        if (typo == INT) {
          A->matrix[j][k] = (int)A->matrix[j][k];
          B->matrix[j][k] = (int)B->matrix[j][k];
        }
      }
    }
    A->matrix_type = CORRECT_MATRIX;
    B->matrix_type = CORRECT_MATRIX;
  } else if (mode == DIFF && A->matrix != NULL && B->matrix != NULL) {
    for (int j = 0; j < A->rows; ++j) {
      for (int k = 0; k < A->columns; ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        A->matrix[j][k] = r;
        double r1 = rand_r(&seed);
        r1 = r1 / DIVIDER * 10 + r;
        B->matrix[j][k] = r1;
        if (typo == INT) {
          A->matrix[j][k] = (int)A->matrix[j][k];
          B->matrix[j][k] = (int)B->matrix[j][k];
        }
      }
    }
    A->matrix_type = CORRECT_MATRIX;
    B->matrix_type = CORRECT_MATRIX;
  } else if (mode == ONE && A->matrix != NULL) {
    for (int j = 0; j < A->rows; ++j) {
      for (int k = 0; k < A->columns; ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        if (typo == INT) {
          A->matrix[j][k] = (int)(r + (error * rand_r(&seed) / DIVIDER));
        } else if (typo == FLT) {
          A->matrix[j][k] = (r + (error * rand_r(&seed) / DIVIDER));
        }
      }
    }
    A->matrix_type = CORRECT_MATRIX;
  }
}

