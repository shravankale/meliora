#include <stdio.h>

#define N 5

//void identity(int a[N][N], int N);

void identity(int a[N][N]){

    int loop_i,loop_j,loop_k, loop_l;

    for(loop_i=0; loop_i<N; loop_i++){
        for(loop_j=0; loop_j<N; loop_j++){
            a[loop_i][loop_j]=0;
        }
    }

    for(loop_k=0; loop_k<N; loop_k++){
        for(loop_l=0; loop_l<N; loop_l++){
            if(loop_k==loop_l){
                a[loop_l][loop_l]=1;
            }
        }
    }
}

int main(){

    //int N = 5;
    int a[N][N];

    identity(a);

    int a_size = sizeof(a)/sizeof(a[0][0]);
    printf("Array Size: %d",a_size);

    // Print the resulting array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;

}