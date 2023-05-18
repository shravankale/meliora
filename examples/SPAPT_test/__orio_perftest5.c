/*
T1_I:128
T1_J:256
T1_K:1
T1_Ia:256
T1_Ja:1024
T1_Ka:512
U_I:10
U_J:12
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
   Coordinate: [4, 5, 0, 3, 5, 4, 5, 6, 0, 1, 0, 0, 0] 
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
    for (int iii = 0; iii <= M - 1; iii = iii + 256) {
      for (int ii = iii; ii <= min(M - 1,iii + 128); ii = ii + 128) {
        for (int i = ii; i <= min(M - 1,ii + 127) - 9; i = i + 10) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 768); jj = jj + 256) {
              for (int j = jj; j <= min(N - 1,jj + 255) - 11; j = j + 12) {
                double scv_23, scv_24, scv_25, scv_26, scv_27, scv_28, scv_29, scv_30;
                double scv_31, scv_32, scv_33, scv_34, scv_35, scv_36, scv_37, scv_38;
                double scv_39, scv_40, scv_41, scv_42, scv_43, scv_44, scv_45, scv_46;
                double scv_47, scv_48, scv_49, scv_50, scv_51, scv_52, scv_53, scv_54;
                double scv_55, scv_56, scv_57, scv_58, scv_59, scv_60, scv_61, scv_62;
                double scv_63, scv_64, scv_65, scv_66, scv_67, scv_68, scv_69, scv_70;
                double scv_71, scv_72, scv_73, scv_74, scv_75, scv_76, scv_77, scv_78;
                double scv_79, scv_80, scv_81, scv_82, scv_83, scv_84, scv_85, scv_86;
                double scv_87, scv_88, scv_89, scv_90, scv_91, scv_92, scv_93, scv_94;
                double scv_95, scv_96, scv_97, scv_98, scv_99, scv_100, scv_101, scv_102;
                double scv_103, scv_104, scv_105, scv_106, scv_107, scv_108, scv_109, scv_110;
                double scv_111, scv_112, scv_113, scv_114, scv_115, scv_116, scv_117, scv_118;
                double scv_119, scv_120, scv_121, scv_122, scv_123, scv_124, scv_125, scv_126;
                double scv_127, scv_128, scv_129, scv_130, scv_131, scv_132, scv_133, scv_134;
                double scv_135, scv_136, scv_137, scv_138, scv_139, scv_140, scv_141, scv_142;
                scv_23 = C[i][j];
                scv_24 = C[i][(j + 1)];
                scv_25 = C[i][(j + 2)];
                scv_26 = C[i][(j + 3)];
                scv_27 = C[i][(j + 4)];
                scv_28 = C[i][(j + 5)];
                scv_29 = C[i][(j + 6)];
                scv_30 = C[i][(j + 7)];
                scv_31 = C[i][(j + 8)];
                scv_32 = C[i][(j + 9)];
                scv_33 = C[i][(j + 10)];
                scv_34 = C[i][(j + 11)];
                scv_35 = C[(i + 1)][j];
                scv_36 = C[(i + 1)][(j + 1)];
                scv_37 = C[(i + 1)][(j + 2)];
                scv_38 = C[(i + 1)][(j + 3)];
                scv_39 = C[(i + 1)][(j + 4)];
                scv_40 = C[(i + 1)][(j + 5)];
                scv_41 = C[(i + 1)][(j + 6)];
                scv_42 = C[(i + 1)][(j + 7)];
                scv_43 = C[(i + 1)][(j + 8)];
                scv_44 = C[(i + 1)][(j + 9)];
                scv_45 = C[(i + 1)][(j + 10)];
                scv_46 = C[(i + 1)][(j + 11)];
                scv_47 = C[(i + 2)][j];
                scv_48 = C[(i + 2)][(j + 1)];
                scv_49 = C[(i + 2)][(j + 2)];
                scv_50 = C[(i + 2)][(j + 3)];
                scv_51 = C[(i + 2)][(j + 4)];
                scv_52 = C[(i + 2)][(j + 5)];
                scv_53 = C[(i + 2)][(j + 6)];
                scv_54 = C[(i + 2)][(j + 7)];
                scv_55 = C[(i + 2)][(j + 8)];
                scv_56 = C[(i + 2)][(j + 9)];
                scv_57 = C[(i + 2)][(j + 10)];
                scv_58 = C[(i + 2)][(j + 11)];
                scv_59 = C[(i + 3)][j];
                scv_60 = C[(i + 3)][(j + 1)];
                scv_61 = C[(i + 3)][(j + 2)];
                scv_62 = C[(i + 3)][(j + 3)];
                scv_63 = C[(i + 3)][(j + 4)];
                scv_64 = C[(i + 3)][(j + 5)];
                scv_65 = C[(i + 3)][(j + 6)];
                scv_66 = C[(i + 3)][(j + 7)];
                scv_67 = C[(i + 3)][(j + 8)];
                scv_68 = C[(i + 3)][(j + 9)];
                scv_69 = C[(i + 3)][(j + 10)];
                scv_70 = C[(i + 3)][(j + 11)];
                scv_71 = C[(i + 4)][j];
                scv_72 = C[(i + 4)][(j + 1)];
                scv_73 = C[(i + 4)][(j + 2)];
                scv_74 = C[(i + 4)][(j + 3)];
                scv_75 = C[(i + 4)][(j + 4)];
                scv_76 = C[(i + 4)][(j + 5)];
                scv_77 = C[(i + 4)][(j + 6)];
                scv_78 = C[(i + 4)][(j + 7)];
                scv_79 = C[(i + 4)][(j + 8)];
                scv_80 = C[(i + 4)][(j + 9)];
                scv_81 = C[(i + 4)][(j + 10)];
                scv_82 = C[(i + 4)][(j + 11)];
                scv_83 = C[(i + 5)][j];
                scv_84 = C[(i + 5)][(j + 1)];
                scv_85 = C[(i + 5)][(j + 2)];
                scv_86 = C[(i + 5)][(j + 3)];
                scv_87 = C[(i + 5)][(j + 4)];
                scv_88 = C[(i + 5)][(j + 5)];
                scv_89 = C[(i + 5)][(j + 6)];
                scv_90 = C[(i + 5)][(j + 7)];
                scv_91 = C[(i + 5)][(j + 8)];
                scv_92 = C[(i + 5)][(j + 9)];
                scv_93 = C[(i + 5)][(j + 10)];
                scv_94 = C[(i + 5)][(j + 11)];
                scv_95 = C[(i + 6)][j];
                scv_96 = C[(i + 6)][(j + 1)];
                scv_97 = C[(i + 6)][(j + 2)];
                scv_98 = C[(i + 6)][(j + 3)];
                scv_99 = C[(i + 6)][(j + 4)];
                scv_100 = C[(i + 6)][(j + 5)];
                scv_101 = C[(i + 6)][(j + 6)];
                scv_102 = C[(i + 6)][(j + 7)];
                scv_103 = C[(i + 6)][(j + 8)];
                scv_104 = C[(i + 6)][(j + 9)];
                scv_105 = C[(i + 6)][(j + 10)];
                scv_106 = C[(i + 6)][(j + 11)];
                scv_107 = C[(i + 7)][j];
                scv_108 = C[(i + 7)][(j + 1)];
                scv_109 = C[(i + 7)][(j + 2)];
                scv_110 = C[(i + 7)][(j + 3)];
                scv_111 = C[(i + 7)][(j + 4)];
                scv_112 = C[(i + 7)][(j + 5)];
                scv_113 = C[(i + 7)][(j + 6)];
                scv_114 = C[(i + 7)][(j + 7)];
                scv_115 = C[(i + 7)][(j + 8)];
                scv_116 = C[(i + 7)][(j + 9)];
                scv_117 = C[(i + 7)][(j + 10)];
                scv_118 = C[(i + 7)][(j + 11)];
                scv_119 = C[(i + 8)][j];
                scv_120 = C[(i + 8)][(j + 1)];
                scv_121 = C[(i + 8)][(j + 2)];
                scv_122 = C[(i + 8)][(j + 3)];
                scv_123 = C[(i + 8)][(j + 4)];
                scv_124 = C[(i + 8)][(j + 5)];
                scv_125 = C[(i + 8)][(j + 6)];
                scv_126 = C[(i + 8)][(j + 7)];
                scv_127 = C[(i + 8)][(j + 8)];
                scv_128 = C[(i + 8)][(j + 9)];
                scv_129 = C[(i + 8)][(j + 10)];
                scv_130 = C[(i + 8)][(j + 11)];
                scv_131 = C[(i + 9)][j];
                scv_132 = C[(i + 9)][(j + 1)];
                scv_133 = C[(i + 9)][(j + 2)];
                scv_134 = C[(i + 9)][(j + 3)];
                scv_135 = C[(i + 9)][(j + 4)];
                scv_136 = C[(i + 9)][(j + 5)];
                scv_137 = C[(i + 9)][(j + 6)];
                scv_138 = C[(i + 9)][(j + 7)];
                scv_139 = C[(i + 9)][(j + 8)];
                scv_140 = C[(i + 9)][(j + 9)];
                scv_141 = C[(i + 9)][(j + 10)];
                scv_142 = C[(i + 9)][(j + 11)];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 512) {
                  for (int k = kkk; k <= min(K - 1,kkk + 511); k = k + 1) {
                    double scv_1, scv_2, scv_3, scv_4, scv_5, scv_6, scv_7, scv_8;
                    double scv_9, scv_10, scv_11, scv_12, scv_13, scv_14, scv_15, scv_16;
                    double scv_17, scv_18, scv_19, scv_20, scv_21, scv_22;
                    scv_1 = A[i][k];
                    scv_2 = B[k][j];
                    scv_3 = B[k][(j + 1)];
                    scv_4 = B[k][(j + 2)];
                    scv_5 = B[k][(j + 3)];
                    scv_6 = B[k][(j + 4)];
                    scv_7 = B[k][(j + 5)];
                    scv_8 = B[k][(j + 6)];
                    scv_9 = B[k][(j + 7)];
                    scv_10 = B[k][(j + 8)];
                    scv_11 = B[k][(j + 9)];
                    scv_12 = B[k][(j + 10)];
                    scv_13 = B[k][(j + 11)];
                    scv_14 = A[(i + 1)][k];
                    scv_15 = A[(i + 2)][k];
                    scv_16 = A[(i + 3)][k];
                    scv_17 = A[(i + 4)][k];
                    scv_18 = A[(i + 5)][k];
                    scv_19 = A[(i + 6)][k];
                    scv_20 = A[(i + 7)][k];
                    scv_21 = A[(i + 8)][k];
                    scv_22 = A[(i + 9)][k];
                    scv_23 = scv_23 + scv_1 * scv_2;
                    scv_24 = scv_24 + scv_1 * scv_3;
                    scv_25 = scv_25 + scv_1 * scv_4;
                    scv_26 = scv_26 + scv_1 * scv_5;
                    scv_27 = scv_27 + scv_1 * scv_6;
                    scv_28 = scv_28 + scv_1 * scv_7;
                    scv_29 = scv_29 + scv_1 * scv_8;
                    scv_30 = scv_30 + scv_1 * scv_9;
                    scv_31 = scv_31 + scv_1 * scv_10;
                    scv_32 = scv_32 + scv_1 * scv_11;
                    scv_33 = scv_33 + scv_1 * scv_12;
                    scv_34 = scv_34 + scv_1 * scv_13;
                    scv_35 = scv_35 + scv_14 * scv_2;
                    scv_36 = scv_36 + scv_14 * scv_3;
                    scv_37 = scv_37 + scv_14 * scv_4;
                    scv_38 = scv_38 + scv_14 * scv_5;
                    scv_39 = scv_39 + scv_14 * scv_6;
                    scv_40 = scv_40 + scv_14 * scv_7;
                    scv_41 = scv_41 + scv_14 * scv_8;
                    scv_42 = scv_42 + scv_14 * scv_9;
                    scv_43 = scv_43 + scv_14 * scv_10;
                    scv_44 = scv_44 + scv_14 * scv_11;
                    scv_45 = scv_45 + scv_14 * scv_12;
                    scv_46 = scv_46 + scv_14 * scv_13;
                    scv_47 = scv_47 + scv_15 * scv_2;
                    scv_48 = scv_48 + scv_15 * scv_3;
                    scv_49 = scv_49 + scv_15 * scv_4;
                    scv_50 = scv_50 + scv_15 * scv_5;
                    scv_51 = scv_51 + scv_15 * scv_6;
                    scv_52 = scv_52 + scv_15 * scv_7;
                    scv_53 = scv_53 + scv_15 * scv_8;
                    scv_54 = scv_54 + scv_15 * scv_9;
                    scv_55 = scv_55 + scv_15 * scv_10;
                    scv_56 = scv_56 + scv_15 * scv_11;
                    scv_57 = scv_57 + scv_15 * scv_12;
                    scv_58 = scv_58 + scv_15 * scv_13;
                    scv_59 = scv_59 + scv_16 * scv_2;
                    scv_60 = scv_60 + scv_16 * scv_3;
                    scv_61 = scv_61 + scv_16 * scv_4;
                    scv_62 = scv_62 + scv_16 * scv_5;
                    scv_63 = scv_63 + scv_16 * scv_6;
                    scv_64 = scv_64 + scv_16 * scv_7;
                    scv_65 = scv_65 + scv_16 * scv_8;
                    scv_66 = scv_66 + scv_16 * scv_9;
                    scv_67 = scv_67 + scv_16 * scv_10;
                    scv_68 = scv_68 + scv_16 * scv_11;
                    scv_69 = scv_69 + scv_16 * scv_12;
                    scv_70 = scv_70 + scv_16 * scv_13;
                    scv_71 = scv_71 + scv_17 * scv_2;
                    scv_72 = scv_72 + scv_17 * scv_3;
                    scv_73 = scv_73 + scv_17 * scv_4;
                    scv_74 = scv_74 + scv_17 * scv_5;
                    scv_75 = scv_75 + scv_17 * scv_6;
                    scv_76 = scv_76 + scv_17 * scv_7;
                    scv_77 = scv_77 + scv_17 * scv_8;
                    scv_78 = scv_78 + scv_17 * scv_9;
                    scv_79 = scv_79 + scv_17 * scv_10;
                    scv_80 = scv_80 + scv_17 * scv_11;
                    scv_81 = scv_81 + scv_17 * scv_12;
                    scv_82 = scv_82 + scv_17 * scv_13;
                    scv_83 = scv_83 + scv_18 * scv_2;
                    scv_84 = scv_84 + scv_18 * scv_3;
                    scv_85 = scv_85 + scv_18 * scv_4;
                    scv_86 = scv_86 + scv_18 * scv_5;
                    scv_87 = scv_87 + scv_18 * scv_6;
                    scv_88 = scv_88 + scv_18 * scv_7;
                    scv_89 = scv_89 + scv_18 * scv_8;
                    scv_90 = scv_90 + scv_18 * scv_9;
                    scv_91 = scv_91 + scv_18 * scv_10;
                    scv_92 = scv_92 + scv_18 * scv_11;
                    scv_93 = scv_93 + scv_18 * scv_12;
                    scv_94 = scv_94 + scv_18 * scv_13;
                    scv_95 = scv_95 + scv_19 * scv_2;
                    scv_96 = scv_96 + scv_19 * scv_3;
                    scv_97 = scv_97 + scv_19 * scv_4;
                    scv_98 = scv_98 + scv_19 * scv_5;
                    scv_99 = scv_99 + scv_19 * scv_6;
                    scv_100 = scv_100 + scv_19 * scv_7;
                    scv_101 = scv_101 + scv_19 * scv_8;
                    scv_102 = scv_102 + scv_19 * scv_9;
                    scv_103 = scv_103 + scv_19 * scv_10;
                    scv_104 = scv_104 + scv_19 * scv_11;
                    scv_105 = scv_105 + scv_19 * scv_12;
                    scv_106 = scv_106 + scv_19 * scv_13;
                    scv_107 = scv_107 + scv_20 * scv_2;
                    scv_108 = scv_108 + scv_20 * scv_3;
                    scv_109 = scv_109 + scv_20 * scv_4;
                    scv_110 = scv_110 + scv_20 * scv_5;
                    scv_111 = scv_111 + scv_20 * scv_6;
                    scv_112 = scv_112 + scv_20 * scv_7;
                    scv_113 = scv_113 + scv_20 * scv_8;
                    scv_114 = scv_114 + scv_20 * scv_9;
                    scv_115 = scv_115 + scv_20 * scv_10;
                    scv_116 = scv_116 + scv_20 * scv_11;
                    scv_117 = scv_117 + scv_20 * scv_12;
                    scv_118 = scv_118 + scv_20 * scv_13;
                    scv_119 = scv_119 + scv_21 * scv_2;
                    scv_120 = scv_120 + scv_21 * scv_3;
                    scv_121 = scv_121 + scv_21 * scv_4;
                    scv_122 = scv_122 + scv_21 * scv_5;
                    scv_123 = scv_123 + scv_21 * scv_6;
                    scv_124 = scv_124 + scv_21 * scv_7;
                    scv_125 = scv_125 + scv_21 * scv_8;
                    scv_126 = scv_126 + scv_21 * scv_9;
                    scv_127 = scv_127 + scv_21 * scv_10;
                    scv_128 = scv_128 + scv_21 * scv_11;
                    scv_129 = scv_129 + scv_21 * scv_12;
                    scv_130 = scv_130 + scv_21 * scv_13;
                    scv_131 = scv_131 + scv_22 * scv_2;
                    scv_132 = scv_132 + scv_22 * scv_3;
                    scv_133 = scv_133 + scv_22 * scv_4;
                    scv_134 = scv_134 + scv_22 * scv_5;
                    scv_135 = scv_135 + scv_22 * scv_6;
                    scv_136 = scv_136 + scv_22 * scv_7;
                    scv_137 = scv_137 + scv_22 * scv_8;
                    scv_138 = scv_138 + scv_22 * scv_9;
                    scv_139 = scv_139 + scv_22 * scv_10;
                    scv_140 = scv_140 + scv_22 * scv_11;
                    scv_141 = scv_141 + scv_22 * scv_12;
                    scv_142 = scv_142 + scv_22 * scv_13;
                  }
                }
                C[i][j] = scv_23;
                C[i][(j + 1)] = scv_24;
                C[i][(j + 2)] = scv_25;
                C[i][(j + 3)] = scv_26;
                C[i][(j + 4)] = scv_27;
                C[i][(j + 5)] = scv_28;
                C[i][(j + 6)] = scv_29;
                C[i][(j + 7)] = scv_30;
                C[i][(j + 8)] = scv_31;
                C[i][(j + 9)] = scv_32;
                C[i][(j + 10)] = scv_33;
                C[i][(j + 11)] = scv_34;
                C[(i + 1)][j] = scv_35;
                C[(i + 1)][(j + 1)] = scv_36;
                C[(i + 1)][(j + 2)] = scv_37;
                C[(i + 1)][(j + 3)] = scv_38;
                C[(i + 1)][(j + 4)] = scv_39;
                C[(i + 1)][(j + 5)] = scv_40;
                C[(i + 1)][(j + 6)] = scv_41;
                C[(i + 1)][(j + 7)] = scv_42;
                C[(i + 1)][(j + 8)] = scv_43;
                C[(i + 1)][(j + 9)] = scv_44;
                C[(i + 1)][(j + 10)] = scv_45;
                C[(i + 1)][(j + 11)] = scv_46;
                C[(i + 2)][j] = scv_47;
                C[(i + 2)][(j + 1)] = scv_48;
                C[(i + 2)][(j + 2)] = scv_49;
                C[(i + 2)][(j + 3)] = scv_50;
                C[(i + 2)][(j + 4)] = scv_51;
                C[(i + 2)][(j + 5)] = scv_52;
                C[(i + 2)][(j + 6)] = scv_53;
                C[(i + 2)][(j + 7)] = scv_54;
                C[(i + 2)][(j + 8)] = scv_55;
                C[(i + 2)][(j + 9)] = scv_56;
                C[(i + 2)][(j + 10)] = scv_57;
                C[(i + 2)][(j + 11)] = scv_58;
                C[(i + 3)][j] = scv_59;
                C[(i + 3)][(j + 1)] = scv_60;
                C[(i + 3)][(j + 2)] = scv_61;
                C[(i + 3)][(j + 3)] = scv_62;
                C[(i + 3)][(j + 4)] = scv_63;
                C[(i + 3)][(j + 5)] = scv_64;
                C[(i + 3)][(j + 6)] = scv_65;
                C[(i + 3)][(j + 7)] = scv_66;
                C[(i + 3)][(j + 8)] = scv_67;
                C[(i + 3)][(j + 9)] = scv_68;
                C[(i + 3)][(j + 10)] = scv_69;
                C[(i + 3)][(j + 11)] = scv_70;
                C[(i + 4)][j] = scv_71;
                C[(i + 4)][(j + 1)] = scv_72;
                C[(i + 4)][(j + 2)] = scv_73;
                C[(i + 4)][(j + 3)] = scv_74;
                C[(i + 4)][(j + 4)] = scv_75;
                C[(i + 4)][(j + 5)] = scv_76;
                C[(i + 4)][(j + 6)] = scv_77;
                C[(i + 4)][(j + 7)] = scv_78;
                C[(i + 4)][(j + 8)] = scv_79;
                C[(i + 4)][(j + 9)] = scv_80;
                C[(i + 4)][(j + 10)] = scv_81;
                C[(i + 4)][(j + 11)] = scv_82;
                C[(i + 5)][j] = scv_83;
                C[(i + 5)][(j + 1)] = scv_84;
                C[(i + 5)][(j + 2)] = scv_85;
                C[(i + 5)][(j + 3)] = scv_86;
                C[(i + 5)][(j + 4)] = scv_87;
                C[(i + 5)][(j + 5)] = scv_88;
                C[(i + 5)][(j + 6)] = scv_89;
                C[(i + 5)][(j + 7)] = scv_90;
                C[(i + 5)][(j + 8)] = scv_91;
                C[(i + 5)][(j + 9)] = scv_92;
                C[(i + 5)][(j + 10)] = scv_93;
                C[(i + 5)][(j + 11)] = scv_94;
                C[(i + 6)][j] = scv_95;
                C[(i + 6)][(j + 1)] = scv_96;
                C[(i + 6)][(j + 2)] = scv_97;
                C[(i + 6)][(j + 3)] = scv_98;
                C[(i + 6)][(j + 4)] = scv_99;
                C[(i + 6)][(j + 5)] = scv_100;
                C[(i + 6)][(j + 6)] = scv_101;
                C[(i + 6)][(j + 7)] = scv_102;
                C[(i + 6)][(j + 8)] = scv_103;
                C[(i + 6)][(j + 9)] = scv_104;
                C[(i + 6)][(j + 10)] = scv_105;
                C[(i + 6)][(j + 11)] = scv_106;
                C[(i + 7)][j] = scv_107;
                C[(i + 7)][(j + 1)] = scv_108;
                C[(i + 7)][(j + 2)] = scv_109;
                C[(i + 7)][(j + 3)] = scv_110;
                C[(i + 7)][(j + 4)] = scv_111;
                C[(i + 7)][(j + 5)] = scv_112;
                C[(i + 7)][(j + 6)] = scv_113;
                C[(i + 7)][(j + 7)] = scv_114;
                C[(i + 7)][(j + 8)] = scv_115;
                C[(i + 7)][(j + 9)] = scv_116;
                C[(i + 7)][(j + 10)] = scv_117;
                C[(i + 7)][(j + 11)] = scv_118;
                C[(i + 8)][j] = scv_119;
                C[(i + 8)][(j + 1)] = scv_120;
                C[(i + 8)][(j + 2)] = scv_121;
                C[(i + 8)][(j + 3)] = scv_122;
                C[(i + 8)][(j + 4)] = scv_123;
                C[(i + 8)][(j + 5)] = scv_124;
                C[(i + 8)][(j + 6)] = scv_125;
                C[(i + 8)][(j + 7)] = scv_126;
                C[(i + 8)][(j + 8)] = scv_127;
                C[(i + 8)][(j + 9)] = scv_128;
                C[(i + 8)][(j + 10)] = scv_129;
                C[(i + 8)][(j + 11)] = scv_130;
                C[(i + 9)][j] = scv_131;
                C[(i + 9)][(j + 1)] = scv_132;
                C[(i + 9)][(j + 2)] = scv_133;
                C[(i + 9)][(j + 3)] = scv_134;
                C[(i + 9)][(j + 4)] = scv_135;
                C[(i + 9)][(j + 5)] = scv_136;
                C[(i + 9)][(j + 6)] = scv_137;
                C[(i + 9)][(j + 7)] = scv_138;
                C[(i + 9)][(j + 8)] = scv_139;
                C[(i + 9)][(j + 9)] = scv_140;
                C[(i + 9)][(j + 10)] = scv_141;
                C[(i + 9)][(j + 11)] = scv_142;
              }
              for (int j = (min(N - 1,jj + 255)) - (((min(N - 1,jj + 255)) - (jj) + 1) % 12) + 1; j <= min(N - 1,jj + 255); j = j + 1) {
                double scv_144, scv_145, scv_146, scv_147, scv_148, scv_149, scv_150, scv_151;
                double scv_152, scv_153;
                scv_144 = C[i][j];
                scv_145 = C[(i + 1)][j];
                scv_146 = C[(i + 2)][j];
                scv_147 = C[(i + 3)][j];
                scv_148 = C[(i + 4)][j];
                scv_149 = C[(i + 5)][j];
                scv_150 = C[(i + 6)][j];
                scv_151 = C[(i + 7)][j];
                scv_152 = C[(i + 8)][j];
                scv_153 = C[(i + 9)][j];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 512) {
                  for (int k = kkk; k <= min(K - 1,kkk + 511); k = k + 1) {
                    double scv_143;
                    scv_143 = B[k][j];
                    scv_144 = scv_144 + A[i][k] * scv_143;
                    scv_145 = scv_145 + A[(i + 1)][k] * scv_143;
                    scv_146 = scv_146 + A[(i + 2)][k] * scv_143;
                    scv_147 = scv_147 + A[(i + 3)][k] * scv_143;
                    scv_148 = scv_148 + A[(i + 4)][k] * scv_143;
                    scv_149 = scv_149 + A[(i + 5)][k] * scv_143;
                    scv_150 = scv_150 + A[(i + 6)][k] * scv_143;
                    scv_151 = scv_151 + A[(i + 7)][k] * scv_143;
                    scv_152 = scv_152 + A[(i + 8)][k] * scv_143;
                    scv_153 = scv_153 + A[(i + 9)][k] * scv_143;
                  }
                }
                C[i][j] = scv_144;
                C[(i + 1)][j] = scv_145;
                C[(i + 2)][j] = scv_146;
                C[(i + 3)][j] = scv_147;
                C[(i + 4)][j] = scv_148;
                C[(i + 5)][j] = scv_149;
                C[(i + 6)][j] = scv_150;
                C[(i + 7)][j] = scv_151;
                C[(i + 8)][j] = scv_152;
                C[(i + 9)][j] = scv_153;
              }
            }
          }
        }
        for (int i = (min(M - 1,ii + 127)) - (((min(M - 1,ii + 127)) - (ii) + 1) % 10) + 1; i <= min(M - 1,ii + 127); i = i + 1) {
          for (int jjj = 0; jjj <= N - 1; jjj = jjj + 1024) {
            for (int jj = jjj; jj <= min(N - 1,jjj + 768); jj = jj + 256) {
              for (int j = jj; j <= min(N - 1,jj + 255) - 11; j = j + 12) {
                double scv_155, scv_156, scv_157, scv_158, scv_159, scv_160, scv_161, scv_162;
                double scv_163, scv_164, scv_165, scv_166;
                scv_155 = C[i][j];
                scv_156 = C[i][(j + 1)];
                scv_157 = C[i][(j + 2)];
                scv_158 = C[i][(j + 3)];
                scv_159 = C[i][(j + 4)];
                scv_160 = C[i][(j + 5)];
                scv_161 = C[i][(j + 6)];
                scv_162 = C[i][(j + 7)];
                scv_163 = C[i][(j + 8)];
                scv_164 = C[i][(j + 9)];
                scv_165 = C[i][(j + 10)];
                scv_166 = C[i][(j + 11)];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 512) {
                  for (int k = kkk; k <= min(K - 1,kkk + 511); k = k + 1) {
                    double scv_154;
                    scv_154 = A[i][k];
                    scv_155 = scv_155 + scv_154 * B[k][j];
                    scv_156 = scv_156 + scv_154 * B[k][(j + 1)];
                    scv_157 = scv_157 + scv_154 * B[k][(j + 2)];
                    scv_158 = scv_158 + scv_154 * B[k][(j + 3)];
                    scv_159 = scv_159 + scv_154 * B[k][(j + 4)];
                    scv_160 = scv_160 + scv_154 * B[k][(j + 5)];
                    scv_161 = scv_161 + scv_154 * B[k][(j + 6)];
                    scv_162 = scv_162 + scv_154 * B[k][(j + 7)];
                    scv_163 = scv_163 + scv_154 * B[k][(j + 8)];
                    scv_164 = scv_164 + scv_154 * B[k][(j + 9)];
                    scv_165 = scv_165 + scv_154 * B[k][(j + 10)];
                    scv_166 = scv_166 + scv_154 * B[k][(j + 11)];
                  }
                }
                C[i][j] = scv_155;
                C[i][(j + 1)] = scv_156;
                C[i][(j + 2)] = scv_157;
                C[i][(j + 3)] = scv_158;
                C[i][(j + 4)] = scv_159;
                C[i][(j + 5)] = scv_160;
                C[i][(j + 6)] = scv_161;
                C[i][(j + 7)] = scv_162;
                C[i][(j + 8)] = scv_163;
                C[i][(j + 9)] = scv_164;
                C[i][(j + 10)] = scv_165;
                C[i][(j + 11)] = scv_166;
              }
              for (int j = (min(N - 1,jj + 255)) - (((min(N - 1,jj + 255)) - (jj) + 1) % 12) + 1; j <= min(N - 1,jj + 255); j = j + 1) {
                double scv_167;
                scv_167 = C[i][j];
                for (int kkk = 0; kkk <= K - 1; kkk = kkk + 512) {
                  for (int k = kkk; k <= min(K - 1,kkk + 511); k = k + 1) {
                    scv_167 = scv_167 + A[i][k] * B[k][j];
                  }
                }
                C[i][j] = scv_167;
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
    printf("{'[4, 5, 0, 3, 5, 4, 5, 6, 0, 1, 0, 0, 0]' : %g}\n", orio_t);
    
    if (orio_i==0) {
      
    }
  }
  
  
  
  return 0;
}
