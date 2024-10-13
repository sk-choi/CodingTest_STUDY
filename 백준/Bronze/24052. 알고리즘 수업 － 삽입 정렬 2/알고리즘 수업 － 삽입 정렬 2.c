#include <stdio.h>
#include <stdlib.h>

void printarr(int data[], int length){
    
    for (int i = 0; i < length; i++){
        printf("%d ", data[i]);
    }
}


void insertionsort(int data[], int length, int K){
    int i = 0;
    int j = 0;
    int value = 0;
    int count = 0;
    
    for (i = 1; i < length; i++){
        value = data[i];
        for (j = i - 1; j >= 0 && data[j] > value; j--){
            if (count == K){
                //printf("%d", data[j]);
                printarr(data, length);
                break;
            }
            data[j+1] = data[j];
            count++;
        }
        if (data[i] != value){
            count++;
        }
        data[j+1] = value;
    }
    if(count < K){
        printf("%d", -1);
    }
}

int main(void){
    
    int N, K;
    
    scanf("%d %d", &N, &K);
    
    int* data = (int*)malloc(sizeof(int)*N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &data[i]);
    }
    
    insertionsort(data, N, K);
    
    return 0;
}