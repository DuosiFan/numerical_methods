#include <stdio.h>
#include <stdlib.h>

/* int betain2out(int betain, int *numin, int nin, */
/* 	       int betaout, int *numout, int nout); */
int beta2dec(int *numin, int beta, int n);


int main(void) {


  // test Horner's method
  int a[] = {1, 1, 1, 0};
  printf("In decimal a = %d\n", beta2dec(a, 2, 3));


  /* int betain = 10; */
  /* int *numin = NULL; */
  /* int nin = 0; */

  /* int betaout = 10; */
  /* int *numout = NULL; */
  /* int nout = 0; */

  /* Binary 1010 to Decimal 10*/
  /* nin = 4; */
  /* nout = 2; */
  
  
  return 0;
}

/* int betain2out(int betain, int *numin, int nin, */
/* 	       int betaout, int *numout, int nout) { */
  

  
/*   return 0; */
/* } */

/* 
   numin: array of length n > 0
   Horner's method
   numin = {an, ..., a0}
*/
int beta2dec(int *numin, int beta, int n) {
  int b = numin[0];
  for (size_t i = 1; i < n + 1; ++i) b = numin[i] + b * beta;
  return b;
}
