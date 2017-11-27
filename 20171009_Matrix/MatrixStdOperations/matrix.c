#include <stdio.h>
#include <stdlib.h>

/*
 * transpose(mat, lines, cols, res)
 * transpose the lines X cols matrix mat into a cols X lines matrix
 * result will be stored in res
 */
void transpose(double mat[], size_t lines, size_t cols, double res[]){
  for(size_t i = 0; i < lines; i++)
  {
    for(size_t j = 0; j < cols; j++){
      res[i + j * lines] = mat[j + i * cols];
    }
  }
}
 
/*
 * add(mat1, mat2, lines, cols, res)
 * computes res = mat1 + mat2
 * All 3 matrices have the form lines X cols
 */
void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[]){
  for(size_t i = 0; i < lines; i++)
  {
    for(size_t j = 0; j < cols; j++){
      res[j + i * cols] = mat1[j + i * cols] + mat2[j + i * cols];
    }
  }
}
 
/*
 * mul(m1, m2, n, m, p, res)
 * computes res = m1 * m2
 * Where:
 *        m1 is a n X m matrix
 *        m2 is a m X p matrix
 *        res is a n X p matrix
 */

void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[]){
  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = 0; j < p; j++){
      res[j + i * p] = 0;
      for(size_t k = 0; k < m; k++)
        res[j + i * p] += m1[k + i * m] * m2[j + k * p];
    }
  }
}
 
/*
 * print_matrix(mat, lines, cols)
 * prints the lines X cols matrix mat
 * All coeficient will be printed using the format " %4g ", line by line
 */
void print_matrix(double mat[], size_t lines, size_t cols){
  for(size_t i = 0; i < lines; i++)
  {
    for(size_t j = 0; j < cols; j++){
      printf("%4g ", mat[j + i * cols]);
    }
    printf("\n");
  }
}
