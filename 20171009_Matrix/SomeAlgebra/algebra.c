// algebra.c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef double (*func_t)(double);

void vector_apply(func_t f, double vect[], size_t size, double res[]){
  for(size_t i = 0; i < size; i++)
    res[i] = f(vect[i]);
}
 
/*
 * product(M, v, m, n, res)
 * computes res = M * v
 * where M is a m X n matrix, v is of length n and res of length m
 */
void product(double M[], double v[], size_t m, size_t n, double res[]){
  for(size_t i = 0; i < m; i++){
    double sum = 0;
    for(size_t j = 0; j < n; j++){
      sum += M[i * m + j] * v[j];
    }
    res[i] = sum;
  }
}
 
/*
 * vector_sum(v1, v2, size, res)
 * computes res = v1 + v2
 * with res, v1 and v2 three vector of lenght size
 */
void vector_sum(double v1[], double v2[], size_t size, double res[]){
  for(size_t i = 0; i < size; i++)
    res[i] = v1[i] + v2[i];
}
