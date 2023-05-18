/*
T1_I:32
T1_J:128
T1_K:128
T1_Ia:1024
T1_Ja:1024
T1_Ka:128
U_I:6
U_J:1
U_K:2
SCREP:True
VEC:False
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
   Coordinate: [2, 4, 4, 5, 5, 2, 3, 0, 1, 1, 0, 0, 1] 
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
      for (int ii = iii; ii <= min(M - 1,iii + 992); ii = ii + 32) {
        for (int i = ii; i <= min(M - 1,ii + 31) - 5; i = i + 6) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 896); jj = jj + 128) {
              for (int j = jj; j <= min(N - 1,jj + 127); j = j + 1) {
                double scv_4, scv_5, scv_6, scv_7, scv_8, scv_9;
                scv_4 = C[i][j];
                scv_5 = C[(i + 1)][j];
                scv_6 = C[(i + 2)][j];
                scv_7 = C[(i + 3)][j];
                scv_8 = C[(i + 4)][j];
                scv_9 = C[(i + 5)][j];
                for (int kk = 0; kk <= K - 1; kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127) - 1; k = k + 2) {
                    double scv_1, scv_2;
                    scv_1 = B[k][j];
                    scv_2 = B[(k + 1)][j];
                    scv_4 = scv_4 + A[i][k] * scv_1;
                    scv_4 = scv_4 + A[i][(k + 1)] * scv_2;
                    scv_5 = scv_5 + A[(i + 1)][k] * scv_1;
                    scv_5 = scv_5 + A[(i + 1)][(k + 1)] * scv_2;
                    scv_6 = scv_6 + A[(i + 2)][k] * scv_1;
                    scv_6 = scv_6 + A[(i + 2)][(k + 1)] * scv_2;
                    scv_7 = scv_7 + A[(i + 3)][k] * scv_1;
                    scv_7 = scv_7 + A[(i + 3)][(k + 1)] * scv_2;
                    scv_8 = scv_8 + A[(i + 4)][k] * scv_1;
                    scv_8 = scv_8 + A[(i + 4)][(k + 1)] * scv_2;
                    scv_9 = scv_9 + A[(i + 5)][k] * scv_1;
                    scv_9 = scv_9 + A[(i + 5)][(k + 1)] * scv_2;
                  }
                  for (int k = (min(K - 1,kk + 127)) - (((min(K - 1,kk + 127)) - (kk) + 1) % 2) + 1; k <= min(K - 1,kk + 127); k = k + 1) {
                    double scv_3;
                    scv_3 = B[k][j];
                    scv_4 = scv_4 + A[i][k] * scv_3;
                    scv_5 = scv_5 + A[(i + 1)][k] * scv_3;
                    scv_6 = scv_6 + A[(i + 2)][k] * scv_3;
                    scv_7 = scv_7 + A[(i + 3)][k] * scv_3;
                    scv_8 = scv_8 + A[(i + 4)][k] * scv_3;
                    scv_9 = scv_9 + A[(i + 5)][k] * scv_3;
                  }
                }
                C[i][j] = scv_4;
                C[(i + 1)][j] = scv_5;
                C[(i + 2)][j] = scv_6;
                C[(i + 3)][j] = scv_7;
                C[(i + 4)][j] = scv_8;
                C[(i + 5)][j] = scv_9;
              }
            }
          }
        }
        for (int i = (min(M - 1,ii + 31)) - (((min(M - 1,ii + 31)) - (ii) + 1) % 6) + 1; i <= min(M - 1,ii + 31); i = i + 1) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 896); jj = jj + 128) {
              for (int j = jj; j <= min(N - 1,jj + 127); j = j + 1) {
                double scv_10;
                scv_10 = C[i][j];
                for (int kk = 0; kk <= K - 1; kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127) - 1; k = k + 2) {
                    scv_10 = scv_10 + A[i][k] * B[k][j];
                    scv_10 = scv_10 + A[i][(k + 1)] * B[(k + 1)][j];
                  }
                  for (int k = (min(K - 1,kk + 127)) - (((min(K - 1,kk + 127)) - (kk) + 1) % 2) + 1; k <= min(K - 1,kk + 127); k = k + 1) {
                    scv_10 = scv_10 + A[i][k] * B[k][j];
                  }
                }
                C[i][j] = scv_10;
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
    printf("{'[2, 4, 4, 5, 5, 2, 3, 0, 1, 1, 0, 0, 1]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
