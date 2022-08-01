// Created by roman on 29.01.2022.
//

#ifndef SRC_DEBUG_FUN_DEBUG_FUN_H_
#define SRC_DEBUG_FUN_DEBUG_FUN_H_
#include "../s21_matrix.h"

// ____DEBUG_________________________DEBUG
void output_matrix(matrix_t *matrix);
#define SAME 1
#define DIFF 2
#define ONE 3
#define INT 0
#define FLT 1
void rand_fill(matrix_t *A, matrix_t *B, int mode, unsigned int seed, double error, int typo);
// ____DEBUG_________________________DEBUG
#endif  // SRC_DEBUG_FUN_DEBUG_FUN_H_
