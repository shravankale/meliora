/*
T1_I:64
T1_J:256
T1_K:16
T1_Ia:1024
T1_Ja:1024
T1_Ka:128
U_I:1
U_J:12
U_K:4
SCREP:True
VEC:True
OMP:False
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
   Coordinate: [3, 5, 1, 5, 5, 2, 0, 6, 2, 1, 1, 0, 0] 
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
    for (int iii = 0; iii <= M - 1; iii = iii + 1024) {
      for (int ii = iii; ii <= min(M - 1,iii + 960); ii = ii + 64) {
        for (int i = ii; i <= min(M - 1,ii + 63); i = i + 1) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 768); jj = jj + 256) {
              for (int j = jj; j <= min(N - 1,jj + 255) - 11; j = j + 12) {
                double scv_6, scv_7, scv_8, scv_9, scv_10, scv_11, scv_12, scv_13;
                double scv_14, scv_15, scv_16, scv_17;
                scv_6 = C[i][j];
                scv_7 = C[i][(j + 1)];
                scv_8 = C[i][(j + 2)];
                scv_9 = C[i][(j + 3)];
                scv_10 = C[i][(j + 4)];
                scv_11 = C[i][(j + 5)];
                scv_12 = C[i][(j + 6)];
                scv_13 = C[i][(j + 7)];
                scv_14 = C[i][(j + 8)];
                scv_15 = C[i][(j + 9)];
                scv_16 = C[i][(j + 10)];
                scv_17 = C[i][(j + 11)];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 128) {
                  for (int kk = kkk; kk <= min(K - 1,kkk + 112); kk = kk + 16) {
                    register int cbv_1;
                    cbv_1 = min(K - 1,kk + 15) - 3;
#pragma ivdep
#pragma vector always
                    for (int k = kk; k <= cbv_1; k = k + 4) {
                      double scv_1, scv_2, scv_3, scv_4;
                      scv_1 = A[i][k];
                      scv_2 = A[i][(k + 1)];
                      scv_3 = A[i][(k + 2)];
                      scv_4 = A[i][(k + 3)];
                      scv_6 = scv_6 + scv_1 * B[k][j];
                      scv_6 = scv_6 + scv_2 * B[(k + 1)][j];
                      scv_6 = scv_6 + scv_3 * B[(k + 2)][j];
                      scv_6 = scv_6 + scv_4 * B[(k + 3)][j];
                      scv_7 = scv_7 + scv_1 * B[k][(j + 1)];
                      scv_7 = scv_7 + scv_2 * B[(k + 1)][(j + 1)];
                      scv_7 = scv_7 + scv_3 * B[(k + 2)][(j + 1)];
                      scv_7 = scv_7 + scv_4 * B[(k + 3)][(j + 1)];
                      scv_8 = scv_8 + scv_1 * B[k][(j + 2)];
                      scv_8 = scv_8 + scv_2 * B[(k + 1)][(j + 2)];
                      scv_8 = scv_8 + scv_3 * B[(k + 2)][(j + 2)];
                      scv_8 = scv_8 + scv_4 * B[(k + 3)][(j + 2)];
                      scv_9 = scv_9 + scv_1 * B[k][(j + 3)];
                      scv_9 = scv_9 + scv_2 * B[(k + 1)][(j + 3)];
                      scv_9 = scv_9 + scv_3 * B[(k + 2)][(j + 3)];
                      scv_9 = scv_9 + scv_4 * B[(k + 3)][(j + 3)];
                      scv_10 = scv_10 + scv_1 * B[k][(j + 4)];
                      scv_10 = scv_10 + scv_2 * B[(k + 1)][(j + 4)];
                      scv_10 = scv_10 + scv_3 * B[(k + 2)][(j + 4)];
                      scv_10 = scv_10 + scv_4 * B[(k + 3)][(j + 4)];
                      scv_11 = scv_11 + scv_1 * B[k][(j + 5)];
                      scv_11 = scv_11 + scv_2 * B[(k + 1)][(j + 5)];
                      scv_11 = scv_11 + scv_3 * B[(k + 2)][(j + 5)];
                      scv_11 = scv_11 + scv_4 * B[(k + 3)][(j + 5)];
                      scv_12 = scv_12 + scv_1 * B[k][(j + 6)];
                      scv_12 = scv_12 + scv_2 * B[(k + 1)][(j + 6)];
                      scv_12 = scv_12 + scv_3 * B[(k + 2)][(j + 6)];
                      scv_12 = scv_12 + scv_4 * B[(k + 3)][(j + 6)];
                      scv_13 = scv_13 + scv_1 * B[k][(j + 7)];
                      scv_13 = scv_13 + scv_2 * B[(k + 1)][(j + 7)];
                      scv_13 = scv_13 + scv_3 * B[(k + 2)][(j + 7)];
                      scv_13 = scv_13 + scv_4 * B[(k + 3)][(j + 7)];
                      scv_14 = scv_14 + scv_1 * B[k][(j + 8)];
                      scv_14 = scv_14 + scv_2 * B[(k + 1)][(j + 8)];
                      scv_14 = scv_14 + scv_3 * B[(k + 2)][(j + 8)];
                      scv_14 = scv_14 + scv_4 * B[(k + 3)][(j + 8)];
                      scv_15 = scv_15 + scv_1 * B[k][(j + 9)];
                      scv_15 = scv_15 + scv_2 * B[(k + 1)][(j + 9)];
                      scv_15 = scv_15 + scv_3 * B[(k + 2)][(j + 9)];
                      scv_15 = scv_15 + scv_4 * B[(k + 3)][(j + 9)];
                      scv_16 = scv_16 + scv_1 * B[k][(j + 10)];
                      scv_16 = scv_16 + scv_2 * B[(k + 1)][(j + 10)];
                      scv_16 = scv_16 + scv_3 * B[(k + 2)][(j + 10)];
                      scv_16 = scv_16 + scv_4 * B[(k + 3)][(j + 10)];
                      scv_17 = scv_17 + scv_1 * B[k][(j + 11)];
                      scv_17 = scv_17 + scv_2 * B[(k + 1)][(j + 11)];
                      scv_17 = scv_17 + scv_3 * B[(k + 2)][(j + 11)];
                      scv_17 = scv_17 + scv_4 * B[(k + 3)][(j + 11)];
                    }
                    register int cbv_2, cbv_3;
                    cbv_2 = (min(K - 1,kk + 15)) - (((min(K - 1,kk + 15)) - (kk) + 1) % 4) + 1;
                    cbv_3 = min(K - 1,kk + 15);
#pragma ivdep
#pragma vector always
                    for (int k = cbv_2; k <= cbv_3; k = k + 1) {
                      double scv_5;
                      scv_5 = A[i][k];
                      scv_6 = scv_6 + scv_5 * B[k][j];
                      scv_7 = scv_7 + scv_5 * B[k][(j + 1)];
                      scv_8 = scv_8 + scv_5 * B[k][(j + 2)];
                      scv_9 = scv_9 + scv_5 * B[k][(j + 3)];
                      scv_10 = scv_10 + scv_5 * B[k][(j + 4)];
                      scv_11 = scv_11 + scv_5 * B[k][(j + 5)];
                      scv_12 = scv_12 + scv_5 * B[k][(j + 6)];
                      scv_13 = scv_13 + scv_5 * B[k][(j + 7)];
                      scv_14 = scv_14 + scv_5 * B[k][(j + 8)];
                      scv_15 = scv_15 + scv_5 * B[k][(j + 9)];
                      scv_16 = scv_16 + scv_5 * B[k][(j + 10)];
                      scv_17 = scv_17 + scv_5 * B[k][(j + 11)];
                    }
                  }
                }
                C[i][j] = scv_6;
                C[i][(j + 1)] = scv_7;
                C[i][(j + 2)] = scv_8;
                C[i][(j + 3)] = scv_9;
                C[i][(j + 4)] = scv_10;
                C[i][(j + 5)] = scv_11;
                C[i][(j + 6)] = scv_12;
                C[i][(j + 7)] = scv_13;
                C[i][(j + 8)] = scv_14;
                C[i][(j + 9)] = scv_15;
                C[i][(j + 10)] = scv_16;
                C[i][(j + 11)] = scv_17;
              }
              for (int j = (min(N - 1,jj + 255)) - (((min(N - 1,jj + 255)) - (jj) + 1) % 12) + 1; j <= min(N - 1,jj + 255); j = j + 1) {
                double scv_18;
                scv_18 = C[i][j];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 128) {
                  for (int kk = kkk; kk <= min(K - 1,kkk + 112); kk = kk + 16) {
                    register int cbv_4;
                    cbv_4 = min(K - 1,kk + 15) - 3;
#pragma ivdep
#pragma vector always
                    for (int k = kk; k <= cbv_4; k = k + 4) {
                      scv_18 = scv_18 + A[i][k] * B[k][j];
                      scv_18 = scv_18 + A[i][(k + 1)] * B[(k + 1)][j];
                      scv_18 = scv_18 + A[i][(k + 2)] * B[(k + 2)][j];
                      scv_18 = scv_18 + A[i][(k + 3)] * B[(k + 3)][j];
                    }
                    register int cbv_5, cbv_6;
                    cbv_5 = (min(K - 1,kk + 15)) - (((min(K - 1,kk + 15)) - (kk) + 1) % 4) + 1;
                    cbv_6 = min(K - 1,kk + 15);
#pragma ivdep
#pragma vector always
                    for (int k = cbv_5; k <= cbv_6; k = k + 1) {
                      scv_18 = scv_18 + A[i][k] * B[k][j];
                    }
                  }
                }
                C[i][j] = scv_18;
              }
            }
          }
        }
      }
    }
  }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[3, 5, 1, 5, 5, 2, 0, 6, 2, 1, 1, 0, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
