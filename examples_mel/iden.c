#include <stdio.h>

#define N 5

//void identity(int a[N][N], int N);

void identity(int a[N][N]){

    int loop_i,loop_j,loop_k;

    for(loop_i=0; loop_i<N; loop_i++){
        for(loop_j=0; loop_j<N; loop_j++){
            a[loop_i][loop_j]=0;
        }
    }

    for(loop_k=0; loop_k<N; loop_k++){
        a[loop_k][loop_k]=1;
    }
}

int main(){

    //int N = 5;
    int a[N][N];

    identity(a);

    int a_size = sizeof(a)/sizeof(a[0][0]);
    printf("Array Size: %d",a_size);

    return 0;

}