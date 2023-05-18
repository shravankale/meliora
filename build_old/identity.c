//#include <iostream>

void identity(int** a, int N){
    int i, j, loop_i;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            a[i][j]=0;
        }
    }

    for(loop_i=0; i<N; i++){
        a[loop_i][loop_i]=1;
    }
}

/*
int main(){
    return 0;
}
*/


int main(){

    int N = 5;
    int *a[N][N];

    identity(*a, N);
    return 0;
}
