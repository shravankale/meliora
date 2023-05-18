/*
T1_I:32
T1_J:16
T1_K:256
T1_Ia:64
T1_Ja:2048
T1_Ka:256
U_I:8
U_J:1
U_K:12
SCREP:False
VEC:False
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
   Coordinate: [2, 1, 5, 1, 6, 3, 4, 0, 6, 0, 0, 1, 0] 
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
    for (int iii = 0; iii <= cbv_1; iii = iii + 64) 
      for (int ii = iii; ii <= min(M - 1,iii + 32); ii = ii + 32) {
        for (int i = ii; i <= min(M - 1,ii + 31) - 7; i = i + 8) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 2048) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 2032); jj = jj + 16) {
              for (int j = jj; j <= min(N - 1,jj + 15); j = j + 1) {
                for (int kk = 0; kk <= K - 1; kk = kk + 256) {
                  for (int k = kk; k <= min(K - 1,kk + 255) - 11; k = k + 12) {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                    C[i][j] = C[i][j] + A[i][(k + 1)] * B[(k + 1)][j];
                    C[i][j] = C[i][j] + A[i][(k + 2)] * B[(k + 2)][j];
                    C[i][j] = C[i][j] + A[i][(k + 3)] * B[(k + 3)][j];
                    C[i][j] = C[i][j] + A[i][(k + 4)] * B[(k + 4)][j];
                    C[i][j] = C[i][j] + A[i][(k + 5)] * B[(k + 5)][j];
                    C[i][j] = C[i][j] + A[i][(k + 6)] * B[(k + 6)][j];
                    C[i][j] = C[i][j] + A[i][(k + 7)] * B[(k + 7)][j];
                    C[i][j] = C[i][j] + A[i][(k + 8)] * B[(k + 8)][j];
                    C[i][j] = C[i][j] + A[i][(k + 9)] * B[(k + 9)][j];
                    C[i][j] = C[i][j] + A[i][(k + 10)] * B[(k + 10)][j];
                    C[i][j] = C[i][j] + A[i][(k + 11)] * B[(k + 11)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][k] * B[k][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][k] * B[k][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][k] * B[k][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][k] * B[k][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][k] * B[k][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][k] * B[k][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][(k + 11)] * B[(k + 11)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][k] * B[k][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 1)] * B[(k + 1)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 2)] * B[(k + 2)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 3)] * B[(k + 3)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 4)] * B[(k + 4)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 5)] * B[(k + 5)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 6)] * B[(k + 6)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 7)] * B[(k + 7)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 8)] * B[(k + 8)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 9)] * B[(k + 9)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 10)] * B[(k + 10)][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][(k + 11)] * B[(k + 11)][j];
                  }
                  for (int k = (min(K - 1,kk + 255)) - (((min(K - 1,kk + 255)) - (kk) + 1) % 12) + 1; k <= min(K - 1,kk + 255); k = k + 1) {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                    C[(i + 1)][j] = C[(i + 1)][j] + A[(i + 1)][k] * B[k][j];
                    C[(i + 2)][j] = C[(i + 2)][j] + A[(i + 2)][k] * B[k][j];
                    C[(i + 3)][j] = C[(i + 3)][j] + A[(i + 3)][k] * B[k][j];
                    C[(i + 4)][j] = C[(i + 4)][j] + A[(i + 4)][k] * B[k][j];
                    C[(i + 5)][j] = C[(i + 5)][j] + A[(i + 5)][k] * B[k][j];
                    C[(i + 6)][j] = C[(i + 6)][j] + A[(i + 6)][k] * B[k][j];
                    C[(i + 7)][j] = C[(i + 7)][j] + A[(i + 7)][k] * B[k][j];
                  }
                }
              }
            }
          }
        }
        for (int i = (min(M - 1,ii + 31)) - (((min(M - 1,ii + 31)) - (ii) + 1) % 8) + 1; i <= min(M - 1,ii + 31); i = i + 1) 
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 2048) 
            for (int jj = jjj; jj <= min(N - 1,jjj + 2032); jj = jj + 16) 
              for (int j = jj; j <= min(N - 1,jj + 15); j = j + 1) 
                for (int kk = 0; kk <= K - 1; kk = kk + 256) {
                  for (int k = kk; k <= min(K - 1,kk + 255) - 11; k = k + 12) {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                    C[i][j] = C[i][j] + A[i][(k + 1)] * B[(k + 1)][j];
                    C[i][j] = C[i][j] + A[i][(k + 2)] * B[(k + 2)][j];
                    C[i][j] = C[i][j] + A[i][(k + 3)] * B[(k + 3)][j];
                    C[i][j] = C[i][j] + A[i][(k + 4)] * B[(k + 4)][j];
                    C[i][j] = C[i][j] + A[i][(k + 5)] * B[(k + 5)][j];
                    C[i][j] = C[i][j] + A[i][(k + 6)] * B[(k + 6)][j];
                    C[i][j] = C[i][j] + A[i][(k + 7)] * B[(k + 7)][j];
                    C[i][j] = C[i][j] + A[i][(k + 8)] * B[(k + 8)][j];
                    C[i][j] = C[i][j] + A[i][(k + 9)] * B[(k + 9)][j];
                    C[i][j] = C[i][j] + A[i][(k + 10)] * B[(k + 10)][j];
                    C[i][j] = C[i][j] + A[i][(k + 11)] * B[(k + 11)][j];
                  }
                  for (int k = (min(K - 1,kk + 255)) - (((min(K - 1,kk + 255)) - (kk) + 1) % 12) + 1; k <= min(K - 1,kk + 255); k = k + 1) 
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
      }
  }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[2, 1, 5, 1, 6, 3, 4, 0, 6, 0, 0, 1, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
