#include <stdio.h>
#include <math.h>
#define SIZE 1000000

void eratosthenes(int arr[], int length){
    
    for (int i = 2; i < sqrt(length); i++){
        if (arr[i] == 0){
            for (int j = 2; i * j < length; j++){
                arr[i * j] = 1;
            }
        }
    }
    
    arr[0] = 1;
    arr[1] = 1;
}


int main(void){
    
    int* prime = (int*)calloc(SIZE, sizeof(int));
    
    eratosthenes(prime, SIZE);
    
    int M, N;
    
    scanf("%d %d", &M, &N);
    
    for (int i = M; i <= N; i++){
        if (prime[i] == 0){
            printf("%d\n", i);
        }
    }
    
    
}