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


int main(void){
    
    int N;
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int)*N); 
    
    for(int i = 0 ; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, N, sizeof(int), compare);
    
    for (int j = 0; j < N; j++){
        printf("%d", arr[j]);
        if (j < N-1){
            printf("\n");
        }
    }
}