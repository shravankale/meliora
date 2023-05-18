/*
T1_I:256
T1_J:128
T2_I:512
T2_J:1024
ACOPY_A:False
U_I:2
U_J:6
SCREP:False
VEC:True
OMP:False
PAR1i:True
PAR1j:True
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define MSIZE 1000
#define NSIZE 1000
#define M 1000
#define N 1000
double a[M][N];
double y_1[N];
double x1[M];
void malloc_arrays() {

}
void init_input_vars() {
  int i1,i2;
  for (i1=0; i1<M; i1++)
   for (i2=0; i2<N; i2++)
    a[i1][i2] = (i1+i2) % 5 + 1;
  for (i1=0; i1<N; i1++)
   y_1[i1] = (i1) % 5 + 1;
  for (i1=0; i1<M; i1++)
   x1[i1] = 0;
}
int main (int argc, char *argv[]) {

double orio_t_start, orio_t_end, orio_t = (double)LONG_MAX;





extern double getClock(); 

//int main(int argc, char *argv[]) { // part of declaration generation
  
#ifdef MAIN_DECLARATIONS
  MAIN_DECLARATIONS()
#endif  
  malloc_arrays();
  init_input_vars();


  int orio_i;

  /*
   Coordinate: [5, 4, 4, 5, 0, 1, 3, 0, 1, 0, 1, 1] 
  */
  
  
  for (orio_i=0; orio_i<ORIO_REPS; orio_i++) {
    orio_t_start = getClock();
    
    

int i, j;
int ii, jj;
int iii, jjj;

#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))



/*@ begin Loop(
  transform Composite(
    tile = [('i',T1_I,'ii'),('j',T1_J,'jj'),(('ii','i'),T2_I,'iii'),(('jj','j'),T2_J,'jjj')],
    arrcopy = [(ACOPY_A,'a[i][j]',[(T1_I if T1_I>1 else T2_I),(T1_J if T1_J>1 else T2_J)],'_copy')],
    scalarreplace = (SCREP, 'double', 'scv_'),
    vector = (VEC, ['ivdep','vector always']),
    unrolljam = (['i','j'],[U_I,U_J]),
    openmp = (OMP, 'omp parallel for private(iii,jjj,ii,jj,i,j,a_copy)')
  )
for (i=0;i<=N-1;i++)
  for (j=0;j<=N-1;j++) 
  { 
    x1[i]=x1[i]+a[i][j]*y_1[j]; 
  } 

) @*/
{
  double a_copy;
  for (int iii = 0; iii <= N - 1; iii = iii + 512) 
    for (int ii = iii; ii <= min(N - 1,iii + 256); ii = ii + 256) {
      for (int i = ii; i <= min(N - 1,ii + 255) - 1; i = i + 2) {
        for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
          for (int jj = jjj; jj <= min(N - 1,jjj + 896); jj = jj + 128) {
            register int cbv_1;
            cbv_1 = min(N - 1,jj + 127) - 5;
#pragma ivdep
#pragma vector always
            for (int j = jj; j <= cbv_1; j = j + 6) {
              x1[i] = x1[i] + a[i][j] * y_1[j];
              x1[i] = x1[i] + a[i][(j + 1)] * y_1[(j + 1)];
              x1[i] = x1[i] + a[i][(j + 2)] * y_1[(j + 2)];
              x1[i] = x1[i] + a[i][(j + 3)] * y_1[(j + 3)];
              x1[i] = x1[i] + a[i][(j + 4)] * y_1[(j + 4)];
              x1[i] = x1[i] + a[i][(j + 5)] * y_1[(j + 5)];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][j] * y_1[j];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][(j + 1)] * y_1[(j + 1)];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][(j + 2)] * y_1[(j + 2)];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][(j + 3)] * y_1[(j + 3)];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][(j + 4)] * y_1[(j + 4)];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][(j + 5)] * y_1[(j + 5)];
            }
            register int cbv_2, cbv_3;
            cbv_2 = (min(N - 1,jj + 127)) - (((min(N - 1,jj + 127)) - (jj) + 1) % 6) + 1;
            cbv_3 = min(N - 1,jj + 127);
#pragma ivdep
#pragma vector always
            for (int j = cbv_2; j <= cbv_3; j = j + 1) {
              x1[i] = x1[i] + a[i][j] * y_1[j];
              x1[(i + 1)] = x1[(i + 1)] + a[(i + 1)][j] * y_1[j];
            }
          }
        }
      }
      for (int i = (min(N - 1,ii + 255)) - (((min(N - 1,ii + 255)) - (ii) + 1) % 2) + 1; i <= min(N - 1,ii + 255); i = i + 1) 
        for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) 
          for (int jj = jjj; jj <= min(N - 1,jjj + 896); jj = jj + 128) {
            register int cbv_4;
            cbv_4 = min(N - 1,jj + 127) - 5;
#pragma ivdep
#pragma vector always
            for (int j = jj; j <= cbv_4; j = j + 6) {
              x1[i] = x1[i] + a[i][j] * y_1[j];
              x1[i] = x1[i] + a[i][(j + 1)] * y_1[(j + 1)];
              x1[i] = x1[i] + a[i][(j + 2)] * y_1[(j + 2)];
              x1[i] = x1[i] + a[i][(j + 3)] * y_1[(j + 3)];
              x1[i] = x1[i] + a[i][(j + 4)] * y_1[(j + 4)];
              x1[i] = x1[i] + a[i][(j + 5)] * y_1[(j + 5)];
            }
            register int cbv_5, cbv_6;
            cbv_5 = (min(N - 1,jj + 127)) - (((min(N - 1,jj + 127)) - (jj) + 1) % 6) + 1;
            cbv_6 = min(N - 1,jj + 127);
#pragma ivdep
#pragma vector always
            for (int j = cbv_5; j <= cbv_6; j = j + 1) 
              x1[i] = x1[i] + a[i][j] * y_1[j];
          }
    }
}
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[5, 4, 4, 5, 0, 1, 3, 0, 1, 0, 1, 1]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
