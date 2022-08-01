//
// Created by roman on 27.01.2022.
//
#include "../CMatrix.h"
#include "../debug_fun/DebugFun.h"

int main() {
  matrix_t matrix_1 = CreateMatrix(3, 3);
  matrix_t matrix_2 = CreateMatrix(3, 3);
  rand_fill(&matrix_1, &matrix_2, SAME, 22, 0.0000001, FLT);
  output_matrix(&matrix_1);
  printf("\n\n");
  output_matrix(&matrix_2);
  printf("\nmat_1\n");

  int flag = EqMatrix(&matrix_1, &matrix_2);
  printf("flg - |%d|\n", flag);
  rand_fill(&matrix_1, NULL, ONE, 23, 0, FLT);
  rand_fill(&matrix_2, NULL, ONE, 456, 0, FLT);

  output_matrix(&matrix_1);
  printf("\nmat_2\n");
  output_matrix(&matrix_2);
  printf("\n\n");

  matrix_t matrix_3 = SumMatrix(&matrix_1, &matrix_2);
  matrix_t matrix_4 = SubMatrix(&matrix_1, &matrix_2);
  printf("\nsum\n");
  output_matrix(&matrix_3);
  printf("\nsub\n");
  output_matrix(&matrix_4);

  matrix_t matrix_5 = MultNumber(&matrix_1, 1);
  printf("\n\n");
  output_matrix(&matrix_5);

  matrix_t n_1 = CreateMatrix(3, 5);
  matrix_t n_2 = CreateMatrix(5, 4);
  rand_fill(&n_1, NULL, ONE, 23, 0, FLT);
  rand_fill(&n_2, NULL, ONE, 34, 0, FLT);


  printf("\n\n");
  output_matrix(&n_1);
  printf("\n\n");
  output_matrix(&n_2);

  matrix_t n_3 = MultMatrix(&n_1, &n_2);
  printf("\nmult\n");
  output_matrix(&n_3);

  matrix_t trans = Transpose(&n_3);
  printf("\ntrans\n");
  output_matrix(&trans);

  matrix_t det_matr = CreateMatrix(4, 4);
  rand_fill(&det_matr, NULL, ONE, 455, 0, INT);
  printf("\ndeter\n");
  output_matrix(&det_matr);

  double det = Determinant(&det_matr);
  printf("\ndet - |%f|", det);

  matrix_t minor_comp = CalcComplements(&det_matr);
  printf("\nminor_comp\n");
  output_matrix(&minor_comp);


  matrix_t inverse = InverseMatrix(&det_matr);
  printf("\ninverse\n");
  output_matrix(&inverse);

  matrix_t identity = MultMatrix(&det_matr, &inverse);
  printf("\nident\n");
  output_matrix(&identity);


    RemoveMatrix(&matrix_1);
    RemoveMatrix(&matrix_2);
    RemoveMatrix(&matrix_3);
    RemoveMatrix(&matrix_4);
    RemoveMatrix(&matrix_5);

    RemoveMatrix(&n_1);
    RemoveMatrix(&n_2);
    RemoveMatrix(&n_3);

    RemoveMatrix(&trans);

    RemoveMatrix(&det_matr);

    RemoveMatrix(&minor_comp);

    RemoveMatrix(&inverse);
    RemoveMatrix(&identity);

  return 0;
}
