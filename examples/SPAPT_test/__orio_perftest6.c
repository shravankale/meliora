/*
T1_I:32
T1_J:32
T1_K:128
T1_Ia:512
T1_Ja:1
T1_Ka:256
U_I:8
U_J:2
U_K:1
SCREP:True
VEC:False
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
   Coordinate: [2, 2, 4, 4, 0, 3, 4, 1, 0, 1, 0, 0, 0] 
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
    for (int iii = 0; iii <= M - 1; iii = iii + 512) {
      for (int ii = iii; ii <= min(M - 1,iii + 480); ii = ii + 32) {
        for (int i = ii; i <= min(M - 1,ii + 31) - 7; i = i + 8) {
          for (int jj = 0; jj <= N - 1; jj = jj + 32) {
            for (int j = jj; j <= min(N - 1,jj + 31) - 1; j = j + 2) {
              double scv_11, scv_12, scv_13, scv_14, scv_15, scv_16, scv_17, scv_18;
              double scv_19, scv_20, scv_21, scv_22, scv_23, scv_24, scv_25, scv_26;
              scv_11 = C[i][j];
              scv_12 = C[i][(j + 1)];
              scv_13 = C[(i + 1)][j];
              scv_14 = C[(i + 1)][(j + 1)];
              scv_15 = C[(i + 2)][j];
              scv_16 = C[(i + 2)][(j + 1)];
              scv_17 = C[(i + 3)][j];
              scv_18 = C[(i + 3)][(j + 1)];
              scv_19 = C[(i + 4)][j];
              scv_20 = C[(i + 4)][(j + 1)];
              scv_21 = C[(i + 5)][j];
              scv_22 = C[(i + 5)][(j + 1)];
              scv_23 = C[(i + 6)][j];
              scv_24 = C[(i + 6)][(j + 1)];
              scv_25 = C[(i + 7)][j];
              scv_26 = C[(i + 7)][(j + 1)];
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int kk = kkk; kk <= min(K - 1,kkk + 128); kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127); k = k + 1) {
                    double scv_1, scv_2, scv_3, scv_4, scv_5, scv_6, scv_7, scv_8;
                    double scv_9, scv_10;
                    scv_1 = A[i][k];
                    scv_2 = B[k][j];
                    scv_3 = B[k][(j + 1)];
                    scv_4 = A[(i + 1)][k];
                    scv_5 = A[(i + 2)][k];
                    scv_6 = A[(i + 3)][k];
                    scv_7 = A[(i + 4)][k];
                    scv_8 = A[(i + 5)][k];
                    scv_9 = A[(i + 6)][k];
                    scv_10 = A[(i + 7)][k];
                    scv_11 = scv_11 + scv_1 * scv_2;
                    scv_12 = scv_12 + scv_1 * scv_3;
                    scv_13 = scv_13 + scv_4 * scv_2;
                    scv_14 = scv_14 + scv_4 * scv_3;
                    scv_15 = scv_15 + scv_5 * scv_2;
                    scv_16 = scv_16 + scv_5 * scv_3;
                    scv_17 = scv_17 + scv_6 * scv_2;
                    scv_18 = scv_18 + scv_6 * scv_3;
                    scv_19 = scv_19 + scv_7 * scv_2;
                    scv_20 = scv_20 + scv_7 * scv_3;
                    scv_21 = scv_21 + scv_8 * scv_2;
                    scv_22 = scv_22 + scv_8 * scv_3;
                    scv_23 = scv_23 + scv_9 * scv_2;
                    scv_24 = scv_24 + scv_9 * scv_3;
                    scv_25 = scv_25 + scv_10 * scv_2;
                    scv_26 = scv_26 + scv_10 * scv_3;
                  }
                }
              }
              C[i][j] = scv_11;
              C[i][(j + 1)] = scv_12;
              C[(i + 1)][j] = scv_13;
              C[(i + 1)][(j + 1)] = scv_14;
              C[(i + 2)][j] = scv_15;
              C[(i + 2)][(j + 1)] = scv_16;
              C[(i + 3)][j] = scv_17;
              C[(i + 3)][(j + 1)] = scv_18;
              C[(i + 4)][j] = scv_19;
              C[(i + 4)][(j + 1)] = scv_20;
              C[(i + 5)][j] = scv_21;
              C[(i + 5)][(j + 1)] = scv_22;
              C[(i + 6)][j] = scv_23;
              C[(i + 6)][(j + 1)] = scv_24;
              C[(i + 7)][j] = scv_25;
              C[(i + 7)][(j + 1)] = scv_26;
            }
            for (int j = (min(N - 1,jj + 31)) - (((min(N - 1,jj + 31)) - (jj) + 1) % 2) + 1; j <= min(N - 1,jj + 31); j = j + 1) {
              double scv_28, scv_29, scv_30, scv_31, scv_32, scv_33, scv_34, scv_35;
              scv_28 = C[i][j];
              scv_29 = C[(i + 1)][j];
              scv_30 = C[(i + 2)][j];
              scv_31 = C[(i + 3)][j];
              scv_32 = C[(i + 4)][j];
              scv_33 = C[(i + 5)][j];
              scv_34 = C[(i + 6)][j];
              scv_35 = C[(i + 7)][j];
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int kk = kkk; kk <= min(K - 1,kkk + 128); kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127); k = k + 1) {
                    double scv_27;
                    scv_27 = B[k][j];
                    scv_28 = scv_28 + A[i][k] * scv_27;
                    scv_29 = scv_29 + A[(i + 1)][k] * scv_27;
                    scv_30 = scv_30 + A[(i + 2)][k] * scv_27;
                    scv_31 = scv_31 + A[(i + 3)][k] * scv_27;
                    scv_32 = scv_32 + A[(i + 4)][k] * scv_27;
                    scv_33 = scv_33 + A[(i + 5)][k] * scv_27;
                    scv_34 = scv_34 + A[(i + 6)][k] * scv_27;
                    scv_35 = scv_35 + A[(i + 7)][k] * scv_27;
                  }
                }
              }
              C[i][j] = scv_28;
              C[(i + 1)][j] = scv_29;
              C[(i + 2)][j] = scv_30;
              C[(i + 3)][j] = scv_31;
              C[(i + 4)][j] = scv_32;
              C[(i + 5)][j] = scv_33;
              C[(i + 6)][j] = scv_34;
              C[(i + 7)][j] = scv_35;
            }
          }
        }
        for (int i = (min(M - 1,ii + 31)) - (((min(M - 1,ii + 31)) - (ii) + 1) % 8) + 1; i <= min(M - 1,ii + 31); i = i + 1) {
          for (int jj = 0; jj <= N - 1; jj = jj + 32) {
            for (int j = jj; j <= min(N - 1,jj + 31) - 1; j = j + 2) {
              double scv_37, scv_38;
              scv_37 = C[i][j];
              scv_38 = C[i][(j + 1)];
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int kk = kkk; kk <= min(K - 1,kkk + 128); kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127); k = k + 1) {
                    double scv_36;
                    scv_36 = A[i][k];
                    scv_37 = scv_37 + scv_36 * B[k][j];
                    scv_38 = scv_38 + scv_36 * B[k][(j + 1)];
                  }
                }
              }
              C[i][j] = scv_37;
              C[i][(j + 1)] = scv_38;
            }
            for (int j = (min(N - 1,jj + 31)) - (((min(N - 1,jj + 31)) - (jj) + 1) % 2) + 1; j <= min(N - 1,jj + 31); j = j + 1) {
              double scv_39;
              scv_39 = C[i][j];
              for (int kkk = 0; kkk <= K - 1; kkk = kkk + 256) {
                for (int kk = kkk; kk <= min(K - 1,kkk + 128); kk = kk + 128) {
                  for (int k = kk; k <= min(K - 1,kk + 127); k = k + 1) {
                    scv_39 = scv_39 + A[i][k] * B[k][j];
                  }
                }
              }
              C[i][j] = scv_39;
            }
          }
        }
      }
    }
  }
/*@ end @*/


    
    orio_t_end = getClock();
    orio_t = orio_t_end - orio_t_start;
    printf("{'[2, 2, 4, 4, 0, 3, 4, 1, 0, 1, 0, 0, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
