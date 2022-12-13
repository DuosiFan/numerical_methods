#include <stdio.h>
#include <stdlib.h>

#include "fftw3.h"

#define RE 0
#define IM 1

int main(void) {
  /* allocate work array */
  int n = 8;
  fftw_complex *in, *out;
  in  = (fftw_complex*) fftw_malloc(sizeof(*in) * n);
  out = (fftw_complex*) fftw_malloc(sizeof(*out) * n);

  /* create plan for the DFT
     ---------------------------------------------------------------------------
     Arguments are self-contained except flag (unsigned). It can be
     1. FFTW_MEASURE  : trial run will be executed to find the optimal plan
     2. FFTW_ESTIMATE : no trial
   */
  int dir = FFTW_FORWARD;
  unsigned flag = FFTW_ESTIMATE;
  fftw_plan plan = fftw_plan_dft_1d(n, in, out, dir, flag);

  /* !WARNING
     ALWAYS initialize work array after the plan is created. Since the plan may
     override the initialization.
   */
  for (int i = 0; i < n; ++i) {
    in[i][RE] = 1.0;
    in[i][IM] = 0.0;
  }
  
  /* execute the plan */
  fftw_execute(plan);

  /* display the forward transform result */
  FILE* log = fopen("log", "a");
  fprintf(log, "Processing cmplx2complx_1d.out\n");
  for (int i = 0; i < n; ++i)
    fprintf(log, "out[%02d] = %9.4f+%9.4fi\n", i, out[i][RE], out[i][IM]);

  fclose(log);
  
  /* destroy plan and release memory */
  fftw_destroy_plan(plan);
  fftw_free(in);
  fftw_free(out);
  
  return EXIT_SUCCESS;
}
