//
// Created by roman on 27.01.2022.
//

#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0


typedef enum {
  CORRECT_MATRIX = 0,
  INCORRECT_MATRIX = 1,
  IDENTITY_MATRIX = 2,
  ZERO_MATRIX = 3
} matrix_type_t;


typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
  matrix_type_t matrix_type;
} matrix_t;

matrix_t s21_create_matrix(int rows, int columns);
void pointer_allocated(double **pointer_el, double *matrix, int rows, int columns);

void s21_remove_matrix(matrix_t *A);

#define epsilon 0.0000001
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int null_check(matrix_t *A);
double my_fabs(double num);
int check_size_matrix(matrix_t *A, matrix_t *B);
int check_matrix_numbers(matrix_t *A, matrix_t *B);

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B);
matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B);

matrix_t s21_mult_number(matrix_t *A, double number);
matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B);
int check_mult(matrix_t *A, matrix_t *B);

matrix_t s21_transpose(matrix_t *A);

matrix_t s21_calc_complements(matrix_t *A);
int sign_power(int row_i, int col_j);

double s21_determinant(matrix_t *A);
int check_square_matrix(matrix_t *A);
double matrix_det(double **matrix, int size);
void matrix_minor(double **matrix, int size, int rows, int columns, double **new_matrix);

matrix_t s21_inverse_matrix(matrix_t *A);

#endif  // SRC_S21_MATRIX_H_
