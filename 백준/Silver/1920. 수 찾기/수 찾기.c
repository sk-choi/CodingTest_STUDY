#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int* aa = (int*)a;
    int* bb = (int*)b;
    
    if (*aa > *bb){
        return 1;
    }
    else if (*aa < *bb){
        return -1;
    }
    else{
        return 0;
    }
}

void binarysearch(int arr[], int target, int start, int length){
    
    if (start > length){
        printf("%d\n", 0);
        return;
    }
    
    int median = start + (length - start) / 2;
    
    if (arr[median] == target){
        printf("%d\n", 1);
    }
    else if (arr[median] < target){
        binarysearch(arr, target, median+1, length);
    }
    else{
        binarysearch(arr, target, start, median-1);
    }
}

int main(void){
    
    int N, M;
    
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int)*N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, N, sizeof(int), compare);
    
    scanf("%d", &M);
    
    int* exist = (int*)malloc(sizeof(int)*M); 
    
    for(int i = 0; i < M; i++){
        scanf("%d", &exist[i]);
    }
    
    for (int i = 0; i < M; i++){
        binarysearch(arr, exist[i], 0, N-1);
    }
}