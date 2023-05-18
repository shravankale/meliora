/*
T1_I:1
T1_J:1
T1_K:16
T1_Ia:64
T1_Ja:64
T1_Ka:64
U_I:1
U_J:2
U_K:8
SCREP:False
VEC:True
OMP:False
PAR:True
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define CONT 500
#define NCONT 500
#define M 500
#define N 500
#define K 500
double A[M][K];
double B[K][N];
double C[M][N];
void malloc_arrays() {

}
void init_input_vars() {
  int i1,i2;
  for (i1=0; i1<M; i1++)
   for (i2=0; i2<K; i2++)
    A[i1][i2] = (i1+i2) % 5 + 1;
  for (i1=0; i1<K; i1++)
   for (i2=0; i2<N; i2++)
    B[i1][i2] = (i1+i2) % 5 + 1;
  for (i1=0; i1<M; i1++)
   for (i2=0; i2<N; i2++)
    C[i1][i2] = 0;
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
   Coordinate: [0, 0, 1, 1, 1, 1, 0, 1, 4, 0, 1, 0, 1] 
  */
  
  
  for (orio_i=0; orio_i<ORIO_REPS; orio_i++) {
    orio_t_start = getClock();
    
    

int i, j, k;
int ii, jj, kk;
int iii, jjj, kkk;

#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

/*@ begin Loop(
  transform Composite(
    tile = [('i',T1_I,'ii'),('j',T1_J,'jj'),('k',T1_K,'kk'),
            (('ii','i'),T1_Ia,'iii'),(('jj','j'),T1_Ja,'jjj'),(('kk','k'),T1_Ka,'kkk')],
    unrolljam = (['i','j','k'],[U_I,U_J,U_K]),
    scalarreplace = (SCREP, 'double', 'scv_'),
    vector = (VEC, ['ivdep','vector always']),
    openmp = (OMP, 'omp parallel for private(iii,jjj,kkk,ii,jj,kk,i,j,k)')
  )
  for(i=0; i<=M-1; i++) 
    for(j=0; j<=N-1; j++)   
      for(k=0; k<=K-1; k++) 
        C[i][j] = C[i][j] + A[i][k] * B[k][j]; 

) @*/
for (int iii = 0; iii <= M - 1; iii = iii + 64) 
  for (int i = iii; i <= min(M - 1,iii + 63); i = i + 1) 
    for (int jjj = 0; jjj <= N - 1; jjj = jjj + 64) {
      for (int j = jjj; j <= min(N - 1,jjj + 63) - 1; j = j + 2) {
        for (int kkk = 0; kkk <= K - 1; kkk = kkk + 64) {
          for (int kk = kkk; kk <= min(K - 1,kkk + 48); kk = kk + 16) {
            register int cbv_1;
            cbv_1 = min(K - 1,kk + 15) - 7;
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_1; k = k + 8) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[i][j] = C[i][j] + A[i][(k + 1)] * B[(k + 1)][j];
              C[i][j] = C[i][j] + A[i][(k + 2)] * B[(k + 2)][j];
              C[i][j] = C[i][j] + A[i][(k + 3)] * B[(k + 3)][j];
              C[i][j] = C[i][j] + A[i][(k + 4)] * B[(k + 4)][j];
              C[i][j] = C[i][j] + A[i][(k + 5)] * B[(k + 5)][j];
              C[i][j] = C[i][j] + A[i][(k + 6)] * B[(k + 6)][j];
              C[i][j] = C[i][j] + A[i][(k + 7)] * B[(k + 7)][j];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][k] * B[k][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 1)] * B[(k + 1)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 2)] * B[(k + 2)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 3)] * B[(k + 3)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 4)] * B[(k + 4)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 5)] * B[(k + 5)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 6)] * B[(k + 6)][(j + 1)];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][(k + 7)] * B[(k + 7)][(j + 1)];
            }
            register int cbv_2, cbv_3;
            cbv_2 = (min(K - 1,kk + 15)) - (((min(K - 1,kk + 15)) - (kk) + 1) % 8) + 1;
            cbv_3 = min(K - 1,kk + 15);
#pragma ivdep
#pragma vector always
            for (int k = cbv_2; k <= cbv_3; k = k + 1) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][k] * B[k][(j + 1)];
            }
          }
        }
      }
      for (int j = (min(N - 1,jjj + 63)) - (((min(N - 1,jjj + 63)) - (jjj) + 1) % 2) + 1; j <= min(N - 1,jjj + 63); j = j + 1) 
        for (int kkk = 0; kkk <= K - 1; kkk = kkk + 64) 
          for (int kk = kkk; kk <= min(K - 1,kkk + 48); kk = kk + 16) {
            register int cbv_4;
            cbv_4 = min(K - 1,kk + 15) - 7;
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_4; k = k + 8) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[i][j] = C[i][j] + A[i][(k + 1)] * B[(k + 1)][j];
              C[i][j] = C[i][j] + A[i][(k + 2)] * B[(k + 2)][j];
              C[i][j] = C[i][j] + A[i][(k + 3)] * B[(k + 3)][j];
              C[i][j] = C[i][j] + A[i][(k + 4)] * B[(k + 4)][j];
              C[i][j] = C[i][j] + A[i][(k + 5)] * B[(k + 5)][j];
              C[i][j] = C[i][j] + A[i][(k + 6)] * B[(k + 6)][j];
              C[i][j] = C[i][j] + A[i][(k + 7)] * B[(k + 7)][j];
            }
            register int cbv_5, cbv_6;
            cbv_5 = (min(K - 1,kk + 15)) - (((min(K - 1,kk + 15)) - (kk) + 1) % 8) + 1;
            cbv_6 = min(K - 1,kk + 15);
#pragma ivdep
#pragma vector always
            for (int k = cbv_5; k <= cbv_6; k = k + 1) 
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
          }
    }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[0, 0, 1, 1, 1, 1, 0, 1, 4, 0, 1, 0, 1]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
