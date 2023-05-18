
/* Kernel written by Bing(Chat-GPT) 

Prompt: Write a C program for me with a function called array_access_pattern 
that accepts a two dimensional array. Within the function first fill the array 
with 0s using two loops, and second create a loop nest to randomly access the 
same array and insert in it a value of 1. Create a main function that calls the 
array_access_pattern function and passes it an array. 

This program defines a function called `array_access_pattern` that accepts 
a two-dimensional array and its dimensions as arguments. Within the 
function, it first fills the array with `0`s using two nested loops. 
Then it creates another loop nest to randomly access the same array and insert it 
with a value of `1`. The `main` function calls the `array_access_pattern` function and 
passes it an array. Finally, the resulting array is printed to the console.
I hope this helps! Let me know if you have any questions or need further assistance. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

void array_access_pattern(int arr[N][M]) {
    // Fill the array with 0s using two loops
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }

    // Create a loop nest to randomly access the same array and insert in it a value of 1
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int rand_row = rand() % N;
            int rand_col = rand() % M;
            arr[rand_row][rand_col] = 1;
        }
    }
}

int main() {
    int arr[N][M];
    array_access_pattern(arr);

    // Print the resulting array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
