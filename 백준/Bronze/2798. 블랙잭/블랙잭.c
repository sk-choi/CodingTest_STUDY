#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int M;
    scanf("%d %d", &N, &M);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    int max = 0;
    int add = 0;
    for (int i = 0; i < N-2; i++){
        for (int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
                add = arr[i] + arr[j] + arr[k];
                if (add <= M){
                    if (max < add){
                        max = add;
                    } 
                }
            }
        }
    }
    printf("%d", max);
}