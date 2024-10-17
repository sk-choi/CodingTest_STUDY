#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    
    int* A = (int*)a;
    int* B = (int*)b;
    
    if (*A > *B){
        return 1;
    }
    else if (*A < *B){
        return -1;
    }
    else{
        return 0;
    }
}


int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, N, sizeof(int), compare);
    
    printf("%d", arr[K-1]);
}