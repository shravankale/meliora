/*
T1_I:1
T1_J:1
T1_K:256
T1_Ia:512
T1_Ja:1
T1_Ka:256
U_I:6
U_J:12
U_K:1
SCREP:False
VEC:True
OMP:True
PAR:False
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
   Coordinate: [0, 0, 5, 4, 0, 3, 3, 6, 0, 0, 1, 1, 0] 
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
for (int loop_87=0; loop_87 < 1; loop_87++)  {
    register int cbv_1;
    cbv_1 = M - 1;
#pragma omp parallel for private(iii,jjj,kkk,ii,jj,kk,i,j,k)
    for (int iii = 0; iii <= cbv_1; iii = iii + 512) {
      for (int i = iii; i <= min(M - 1,iii + 511) - 5; i = i + 6) {
        for (int j = 0; j <= N - 12; j = j + 12) {
          for (int kk = 0; kk <= K - 1; kk = kk + 256) {
            register int cbv_2;
            cbv_2 = min(K - 1,kk + 255);
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_2; k = k + 1) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][k] * B[k][(j + 1)];
              C[i][(j + 2)] = C[i][(j + 2)] + A[i][k] * B[k][(j + 2)];
              C[i][(j + 3)] = C[i][(j + 3)] + A[i][k] * B[k][(j + 3)];
              C[i][(j + 4)] = C[i][(j + 4)] + A[i][k] * B[k][(j + 4)];
              C[i][(j + 5)] = C[i][(j + 5)] + A[i][k] * B[k][(j + 5)];
              C[i][(j + 6)] = C[i][(j + 6)] + A[i][k] * B[k][(j + 6)];
              C[i][(j + 7)] = C[i][(j + 7)] + A[i][k] * B[k][(j + 7)];
              C[i][(j + 8)] = C[i][(j + 8)] + A[i][k] * B[k][(j + 8)];
              C[i][(j + 9)] = C[i][(j + 9)] + A[i][k] * B[k][(j + 9)];
              C[i][(j + 10)] = C[i][(j + 10)] + A[i][k] * B[k][(j + 10)];
              C[i][(j + 11)] = C[i][(j + 11)] + A[i][k] * B[k][(j + 11)];
              C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][k] * B[k][j];
              C[(i + 1)][(j + 1)] = C[(i + 1)][(j + 1)] + A[(i + 1)][k] * B[k][(j + 1)];
              C[(i + 1)][(j + 2)] = C[(i + 1)][(j + 2)] + A[(i + 1)][k] * B[k][(j + 2)];
              C[(i + 1)][(j + 3)] = C[(i + 1)][(j + 3)] + A[(i + 1)][k] * B[k][(j + 3)];
              C[(i + 1)][(j + 4)] = C[(i + 1)][(j + 4)] + A[(i + 1)][k] * B[k][(j + 4)];
              C[(i + 1)][(j + 5)] = C[(i + 1)][(j + 5)] + A[(i + 1)][k] * B[k][(j + 5)];
              C[(i + 1)][(j + 6)] = C[(i + 1)][(j + 6)] + A[(i + 1)][k] * B[k][(j + 6)];
              C[(i + 1)][(j + 7)] = C[(i + 1)][(j + 7)] + A[(i + 1)][k] * B[k][(j + 7)];
              C[(i + 1)][(j + 8)] = C[(i + 1)][(j + 8)] + A[(i + 1)][k] * B[k][(j + 8)];
              C[(i + 1)][(j + 9)] = C[(i + 1)][(j + 9)] + A[(i + 1)][k] * B[k][(j + 9)];
              C[(i + 1)][(j + 10)] = C[(i + 1)][(j + 10)] + A[(i + 1)][k] * B[k][(j + 10)];
              C[(i + 1)][(j + 11)] = C[(i + 1)][(j + 11)] + A[(i + 1)][k] * B[k][(j + 11)];
              C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][k] * B[k][j];
              C[(i + 2)][(j + 1)] = C[(i + 2)][(j + 1)] + A[(i + 2)][k] * B[k][(j + 1)];
              C[(i + 2)][(j + 2)] = C[(i + 2)][(j + 2)] + A[(i + 2)][k] * B[k][(j + 2)];
              C[(i + 2)][(j + 3)] = C[(i + 2)][(j + 3)] + A[(i + 2)][k] * B[k][(j + 3)];
              C[(i + 2)][(j + 4)] = C[(i + 2)][(j + 4)] + A[(i + 2)][k] * B[k][(j + 4)];
              C[(i + 2)][(j + 5)] = C[(i + 2)][(j + 5)] + A[(i + 2)][k] * B[k][(j + 5)];
              C[(i + 2)][(j + 6)] = C[(i + 2)][(j + 6)] + A[(i + 2)][k] * B[k][(j + 6)];
              C[(i + 2)][(j + 7)] = C[(i + 2)][(j + 7)] + A[(i + 2)][k] * B[k][(j + 7)];
              C[(i + 2)][(j + 8)] = C[(i + 2)][(j + 8)] + A[(i + 2)][k] * B[k][(j + 8)];
              C[(i + 2)][(j + 9)] = C[(i + 2)][(j + 9)] + A[(i + 2)][k] * B[k][(j + 9)];
              C[(i + 2)][(j + 10)] = C[(i + 2)][(j + 10)] + A[(i + 2)][k] * B[k][(j + 10)];
              C[(i + 2)][(j + 11)] = C[(i + 2)][(j + 11)] + A[(i + 2)][k] * B[k][(j + 11)];
              C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][k] * B[k][j];
              C[(i + 3)][(j + 1)] = C[(i + 3)][(j + 1)] + A[(i + 3)][k] * B[k][(j + 1)];
              C[(i + 3)][(j + 2)] = C[(i + 3)][(j + 2)] + A[(i + 3)][k] * B[k][(j + 2)];
              C[(i + 3)][(j + 3)] = C[(i + 3)][(j + 3)] + A[(i + 3)][k] * B[k][(j + 3)];
              C[(i + 3)][(j + 4)] = C[(i + 3)][(j + 4)] + A[(i + 3)][k] * B[k][(j + 4)];
              C[(i + 3)][(j + 5)] = C[(i + 3)][(j + 5)] + A[(i + 3)][k] * B[k][(j + 5)];
              C[(i + 3)][(j + 6)] = C[(i + 3)][(j + 6)] + A[(i + 3)][k] * B[k][(j + 6)];
              C[(i + 3)][(j + 7)] = C[(i + 3)][(j + 7)] + A[(i + 3)][k] * B[k][(j + 7)];
              C[(i + 3)][(j + 8)] = C[(i + 3)][(j + 8)] + A[(i + 3)][k] * B[k][(j + 8)];
              C[(i + 3)][(j + 9)] = C[(i + 3)][(j + 9)] + A[(i + 3)][k] * B[k][(j + 9)];
              C[(i + 3)][(j + 10)] = C[(i + 3)][(j + 10)] + A[(i + 3)][k] * B[k][(j + 10)];
              C[(i + 3)][(j + 11)] = C[(i + 3)][(j + 11)] + A[(i + 3)][k] * B[k][(j + 11)];
              C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][k] * B[k][j];
              C[(i + 4)][(j + 1)] = C[(i + 4)][(j + 1)] + A[(i + 4)][k] * B[k][(j + 1)];
              C[(i + 4)][(j + 2)] = C[(i + 4)][(j + 2)] + A[(i + 4)][k] * B[k][(j + 2)];
              C[(i + 4)][(j + 3)] = C[(i + 4)][(j + 3)] + A[(i + 4)][k] * B[k][(j + 3)];
              C[(i + 4)][(j + 4)] = C[(i + 4)][(j + 4)] + A[(i + 4)][k] * B[k][(j + 4)];
              C[(i + 4)][(j + 5)] = C[(i + 4)][(j + 5)] + A[(i + 4)][k] * B[k][(j + 5)];
              C[(i + 4)][(j + 6)] = C[(i + 4)][(j + 6)] + A[(i + 4)][k] * B[k][(j + 6)];
              C[(i + 4)][(j + 7)] = C[(i + 4)][(j + 7)] + A[(i + 4)][k] * B[k][(j + 7)];
              C[(i + 4)][(j + 8)] = C[(i + 4)][(j + 8)] + A[(i + 4)][k] * B[k][(j + 8)];
              C[(i + 4)][(j + 9)] = C[(i + 4)][(j + 9)] + A[(i + 4)][k] * B[k][(j + 9)];
              C[(i + 4)][(j + 10)] = C[(i + 4)][(j + 10)] + A[(i + 4)][k] * B[k][(j + 10)];
              C[(i + 4)][(j + 11)] = C[(i + 4)][(j + 11)] + A[(i + 4)][k] * B[k][(j + 11)];
              C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][k] * B[k][j];
              C[(i + 5)][(j + 1)] = C[(i + 5)][(j + 1)] + A[(i + 5)][k] * B[k][(j + 1)];
              C[(i + 5)][(j + 2)] = C[(i + 5)][(j + 2)] + A[(i + 5)][k] * B[k][(j + 2)];
              C[(i + 5)][(j + 3)] = C[(i + 5)][(j + 3)] + A[(i + 5)][k] * B[k][(j + 3)];
              C[(i + 5)][(j + 4)] = C[(i + 5)][(j + 4)] + A[(i + 5)][k] * B[k][(j + 4)];
              C[(i + 5)][(j + 5)] = C[(i + 5)][(j + 5)] + A[(i + 5)][k] * B[k][(j + 5)];
              C[(i + 5)][(j + 6)] = C[(i + 5)][(j + 6)] + A[(i + 5)][k] * B[k][(j + 6)];
              C[(i + 5)][(j + 7)] = C[(i + 5)][(j + 7)] + A[(i + 5)][k] * B[k][(j + 7)];
              C[(i + 5)][(j + 8)] = C[(i + 5)][(j + 8)] + A[(i + 5)][k] * B[k][(j + 8)];
              C[(i + 5)][(j + 9)] = C[(i + 5)][(j + 9)] + A[(i + 5)][k] * B[k][(j + 9)];
              C[(i + 5)][(j + 10)] = C[(i + 5)][(j + 10)] + A[(i + 5)][k] * B[k][(j + 10)];
              C[(i + 5)][(j + 11)] = C[(i + 5)][(j + 11)] + A[(i + 5)][k] * B[k][(j + 11)];
            }
          }
        }
        for (int j = N - ((N - (0)) % 12); j <= N - 1; j = j + 1) {
          for (int kk = 0; kk <= K - 1; kk = kk + 256) {
            register int cbv_3;
            cbv_3 = min(K - 1,kk + 255);
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_3; k = k + 1) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][k] * B[k][j];
              C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][k] * B[k][j];
              C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][k] * B[k][j];
              C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][k] * B[k][j];
              C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][k] * B[k][j];
            }
          }
        }
      }
      for (int i = (min(M - 1,iii + 511)) - (((min(M - 1,iii + 511)) - (iii) + 1) % 6) + 1; i <= min(M - 1,iii + 511); i = i + 1) {
        for (int j = 0; j <= N - 12; j = j + 12) {
          for (int kk = 0; kk <= K - 1; kk = kk + 256) {
            register int cbv_4;
            cbv_4 = min(K - 1,kk + 255);
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_4; k = k + 1) {
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
              C[i][(j + 1)] = C[i][(j + 1)] + A[i][k] * B[k][(j + 1)];
              C[i][(j + 2)] = C[i][(j + 2)] + A[i][k] * B[k][(j + 2)];
              C[i][(j + 3)] = C[i][(j + 3)] + A[i][k] * B[k][(j + 3)];
              C[i][(j + 4)] = C[i][(j + 4)] + A[i][k] * B[k][(j + 4)];
              C[i][(j + 5)] = C[i][(j + 5)] + A[i][k] * B[k][(j + 5)];
              C[i][(j + 6)] = C[i][(j + 6)] + A[i][k] * B[k][(j + 6)];
              C[i][(j + 7)] = C[i][(j + 7)] + A[i][k] * B[k][(j + 7)];
              C[i][(j + 8)] = C[i][(j + 8)] + A[i][k] * B[k][(j + 8)];
              C[i][(j + 9)] = C[i][(j + 9)] + A[i][k] * B[k][(j + 9)];
              C[i][(j + 10)] = C[i][(j + 10)] + A[i][k] * B[k][(j + 10)];
              C[i][(j + 11)] = C[i][(j + 11)] + A[i][k] * B[k][(j + 11)];
            }
          }
        }
        for (int j = N - ((N - (0)) % 12); j <= N - 1; j = j + 1) 
          for (int kk = 0; kk <= K - 1; kk = kk + 256) {
            register int cbv_5;
            cbv_5 = min(K - 1,kk + 255);
#pragma ivdep
#pragma vector always
            for (int k = kk; k <= cbv_5; k = k + 1) 
              C[i][j] = C[i][j] + A[i][k] * B[k][j];
          }
      }
    }
  }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[0, 0, 5, 4, 0, 3, 3, 6, 0, 0, 1, 1, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
