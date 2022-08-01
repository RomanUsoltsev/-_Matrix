//
// Created by roman on 27.01.2022.
//
#include "../s21_matrix.h"
#include "../debug_fun/debug_fun.h"

int main() {
  matrix_t matrix_1 = s21_create_matrix(3, 3);
  matrix_t matrix_2 = s21_create_matrix(3, 3);
  rand_fill(&matrix_1, &matrix_2, SAME, 22, 0.0000001, FLT);
  output_matrix(&matrix_1);
  printf("\n\n");
  output_matrix(&matrix_2);
  printf("\nmat_1\n");

  int flag = s21_eq_matrix(&matrix_1, &matrix_2);
  printf("flg - |%d|\n", flag);
  rand_fill(&matrix_1, NULL, ONE, 23, 0, FLT);
  rand_fill(&matrix_2, NULL, ONE, 456, 0, FLT);

  output_matrix(&matrix_1);
  printf("\nmat_2\n");
  output_matrix(&matrix_2);
  printf("\n\n");

  matrix_t matrix_3 = s21_sum_matrix(&matrix_1, &matrix_2);
  matrix_t matrix_4 = s21_sub_matrix(&matrix_1, &matrix_2);
  printf("\nsum\n");
  output_matrix(&matrix_3);
  printf("\nsub\n");
  output_matrix(&matrix_4);

  matrix_t matrix_5 = s21_mult_number(&matrix_1, 1);
  printf("\n\n");
  output_matrix(&matrix_5);

  matrix_t n_1 = s21_create_matrix(3, 5);
  matrix_t n_2 = s21_create_matrix(5, 4);
  rand_fill(&n_1, NULL, ONE, 23, 0, FLT);
  rand_fill(&n_2, NULL, ONE, 34, 0, FLT);


  printf("\n\n");
  output_matrix(&n_1);
  printf("\n\n");
  output_matrix(&n_2);

  matrix_t n_3 = s21_mult_matrix(&n_1, &n_2);
  printf("\nmult\n");
  output_matrix(&n_3);

  matrix_t trans = s21_transpose(&n_3);
  printf("\ntrans\n");
  output_matrix(&trans);

  matrix_t det_matr = s21_create_matrix(4, 4);
  rand_fill(&det_matr, NULL, ONE, 455, 0, INT);
  printf("\ndeter\n");
  output_matrix(&det_matr);

  double det = s21_determinant(&det_matr);
  printf("\ndet - |%f|", det);

  matrix_t minor_comp = s21_calc_complements(&det_matr);
  printf("\nminor_comp\n");
  output_matrix(&minor_comp);


  matrix_t inverse = s21_inverse_matrix(&det_matr);
  printf("\ninverse\n");
  output_matrix(&inverse);

  matrix_t identity = s21_mult_matrix(&det_matr, &inverse);
  printf("\nident\n");
  output_matrix(&identity);





  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&matrix_3);
  s21_remove_matrix(&matrix_4);
  s21_remove_matrix(&matrix_5);

  s21_remove_matrix(&n_1);
  s21_remove_matrix(&n_2);
  s21_remove_matrix(&n_3);

  s21_remove_matrix(&trans);

  s21_remove_matrix(&det_matr);

  s21_remove_matrix(&minor_comp);

  s21_remove_matrix(&inverse);
  s21_remove_matrix(&identity);

  return 0;
}
