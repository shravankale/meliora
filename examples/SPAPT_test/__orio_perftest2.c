/*
T1_I:1
T1_J:64
T1_K:1
T1_Ia:2048
T1_Ja:256
T1_Ka:256
U_I:1
U_J:14
U_K:8
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
   Coordinate: [0, 3, 0, 6, 3, 3, 0, 7, 4, 0, 0, 1, 0] 
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
    for (int iii = 0; iii <= cbv_1; iii = iii + 2048) 
      for (int i = iii; i <= min(M - 1,iii + 2047); i = i + 1) 
        for (int jjj = 0; jjj <= N - 1; jjj = jjj + 256) 
          for (int jj = jjj; jj <= min(N - 1,jjj + 192); jj = jj + 64) {
            for (int j = jj; j <= min(N - 1,jj + 63) - 13; j = j + 14) {
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int k = kkk; k <= min(K - 1,kkk + 255) - 7; k = k + 8) {
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
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][k] * B[k][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 1)] * B[(k + 1)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 2)] * B[(k + 2)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 3)] * B[(k + 3)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 4)] * B[(k + 4)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 5)] * B[(k + 5)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 6)] * B[(k + 6)][(j + 2)];
                  C[i][(j + 2)] = C[i][(j + 2)] + A[i][(k + 7)] * B[(k + 7)][(j + 2)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][k] * B[k][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 1)] * B[(k + 1)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 2)] * B[(k + 2)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 3)] * B[(k + 3)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 4)] * B[(k + 4)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 5)] * B[(k + 5)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 6)] * B[(k + 6)][(j + 3)];
                  C[i][(j + 3)] = C[i][(j + 3)] + A[i][(k + 7)] * B[(k + 7)][(j + 3)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][k] * B[k][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 1)] * B[(k + 1)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 2)] * B[(k + 2)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 3)] * B[(k + 3)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 4)] * B[(k + 4)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 5)] * B[(k + 5)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 6)] * B[(k + 6)][(j + 4)];
                  C[i][(j + 4)] = C[i][(j + 4)] + A[i][(k + 7)] * B[(k + 7)][(j + 4)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][k] * B[k][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 1)] * B[(k + 1)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 2)] * B[(k + 2)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 3)] * B[(k + 3)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 4)] * B[(k + 4)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 5)] * B[(k + 5)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 6)] * B[(k + 6)][(j + 5)];
                  C[i][(j + 5)] = C[i][(j + 5)] + A[i][(k + 7)] * B[(k + 7)][(j + 5)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][k] * B[k][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 1)] * B[(k + 1)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 2)] * B[(k + 2)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 3)] * B[(k + 3)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 4)] * B[(k + 4)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 5)] * B[(k + 5)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 6)] * B[(k + 6)][(j + 6)];
                  C[i][(j + 6)] = C[i][(j + 6)] + A[i][(k + 7)] * B[(k + 7)][(j + 6)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][k] * B[k][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 1)] * B[(k + 1)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 2)] * B[(k + 2)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 3)] * B[(k + 3)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 4)] * B[(k + 4)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 5)] * B[(k + 5)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 6)] * B[(k + 6)][(j + 7)];
                  C[i][(j + 7)] = C[i][(j + 7)] + A[i][(k + 7)] * B[(k + 7)][(j + 7)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][k] * B[k][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 1)] * B[(k + 1)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 2)] * B[(k + 2)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 3)] * B[(k + 3)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 4)] * B[(k + 4)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 5)] * B[(k + 5)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 6)] * B[(k + 6)][(j + 8)];
                  C[i][(j + 8)] = C[i][(j + 8)] + A[i][(k + 7)] * B[(k + 7)][(j + 8)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][k] * B[k][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 1)] * B[(k + 1)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 2)] * B[(k + 2)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 3)] * B[(k + 3)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 4)] * B[(k + 4)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 5)] * B[(k + 5)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 6)] * B[(k + 6)][(j + 9)];
                  C[i][(j + 9)] = C[i][(j + 9)] + A[i][(k + 7)] * B[(k + 7)][(j + 9)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][k] * B[k][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 1)] * B[(k + 1)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 2)] * B[(k + 2)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 3)] * B[(k + 3)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 4)] * B[(k + 4)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 5)] * B[(k + 5)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 6)] * B[(k + 6)][(j + 10)];
                  C[i][(j + 10)] = C[i][(j + 10)] + A[i][(k + 7)] * B[(k + 7)][(j + 10)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][k] * B[k][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 1)] * B[(k + 1)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 2)] * B[(k + 2)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 3)] * B[(k + 3)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 4)] * B[(k + 4)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 5)] * B[(k + 5)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 6)] * B[(k + 6)][(j + 11)];
                  C[i][(j + 11)] = C[i][(j + 11)] + A[i][(k + 7)] * B[(k + 7)][(j + 11)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][k] * B[k][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 1)] * B[(k + 1)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 2)] * B[(k + 2)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 3)] * B[(k + 3)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 4)] * B[(k + 4)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 5)] * B[(k + 5)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 6)] * B[(k + 6)][(j + 12)];
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][(k + 7)] * B[(k + 7)][(j + 12)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][k] * B[k][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 1)] * B[(k + 1)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 2)] * B[(k + 2)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 3)] * B[(k + 3)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 4)] * B[(k + 4)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 5)] * B[(k + 5)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 6)] * B[(k + 6)][(j + 13)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][(k + 7)] * B[(k + 7)][(j + 13)];
                }
                for (int k = (min(K - 1,kkk + 255)) - (((min(K - 1,kkk + 255)) - (kkk) + 1) % 8) + 1; k <= min(K - 1,kkk + 255); k = k + 1) {
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
                  C[i][(j + 12)] = C[i][(j + 12)] + A[i][k] * B[k][(j + 12)];
                  C[i][(j + 13)] = C[i][(j + 13)] + A[i][k] * B[k][(j + 13)];
                }
              }
            }
            for (int j = (min(N - 1,jj + 63)) - (((min(N - 1,jj + 63)) - (jj) + 1) % 14) + 1; j <= min(N - 1,jj + 63); j = j + 1) 
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int k = kkk; k <= min(K - 1,kkk + 255) - 7; k = k + 8) {
                  C[i][j] = C[i][j] + A[i][k] * B[k][j];
                  C[i][j] = C[i][j] + A[i][(k + 1)] * B[(k + 1)][j];
                  C[i][j] = C[i][j] + A[i][(k + 2)] * B[(k + 2)][j];
                  C[i][j] = C[i][j] + A[i][(k + 3)] * B[(k + 3)][j];
                  C[i][j] = C[i][j] + A[i][(k + 4)] * B[(k + 4)][j];
                  C[i][j] = C[i][j] + A[i][(k + 5)] * B[(k + 5)][j];
                  C[i][j] = C[i][j] + A[i][(k + 6)] * B[(k + 6)][j];
                  C[i][j] = C[i][j] + A[i][(k + 7)] * B[(k + 7)][j];
                }
                for (int k = (min(K - 1,kkk + 255)) - (((min(K - 1,kkk + 255)) - (kkk) + 1) % 8) + 1; k <= min(K - 1,kkk + 255); k = k + 1) 
                  C[i][j] = C[i][j] + A[i][k] * B[k][j];
              }
          }
  }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[0, 3, 0, 6, 3, 3, 0, 7, 4, 0, 0, 1, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
