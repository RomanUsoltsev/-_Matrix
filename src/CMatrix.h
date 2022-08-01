//
// Created by roman on 27.01.2022.
//

#ifndef SRC_CMATRIX_H_
#define SRC_CMATRIX_H_

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

matrix_t CreateMatrix(int rows, int columns);
void PointerAllocated(double **pointer_el, double *matrix, int rows, int columns);

void RemoveMatrix(matrix_t *A);

#define epsilon 0.0000001
int EqMatrix(matrix_t *A, matrix_t *B);
int NullCheck(matrix_t *A);
double MyFabs(double num);
int CheckSizeMatrix(matrix_t *A, matrix_t *B);
int CheckMatrixNumbers(matrix_t *A, matrix_t *B);

matrix_t SumMatrix(matrix_t *A, matrix_t *B);
matrix_t SubMatrix(matrix_t *A, matrix_t *B);

matrix_t MultNumber(matrix_t *A, double number);
matrix_t MultMatrix(matrix_t *A, matrix_t *B);
int CheckMult(matrix_t *A, matrix_t *B);

matrix_t Transpose(matrix_t *A);

matrix_t CalcComplements(matrix_t *A);
int SignPower(int row_i, int col_j);

double Determinant(matrix_t *A);
int CheckSquareMatrix(matrix_t *A);
double MatrixDet(double **matrix, int size);
void MatrixMinor(double **matrix, int size, int rows, int columns, double **new_matrix);

matrix_t InverseMatrix(matrix_t *A);

#endif  // SRC_CMATRIX_H_
