#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort(char arr[], char exist[], int length){
    char* save = (char*)malloc(sizeof(char)*(length+1));
    int i,j;
    char key;
    
    for (i = 1; i < length; i++){
        key = arr[i];
        for (j = i-1; j >=0 && arr[j] > key; j--){
            if (strcmp(arr, exist) == 0){
                memmove(save, arr, length+1);
                break;
            }
            else{
                arr[j+1] = arr[j];
            }
        }
        //arr[j+1] = key;
        if (strcmp(arr, exist) == 0){
            memmove(save, arr, length+1);
            break;
        }
        else{
            arr[j+1] = key;
        }
    }
    if (strcmp(save, exist) == 0){
        printf("%d", 1);
    }
    else{
        printf("%d", 0);
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    
    char* arr = (char*)malloc(sizeof(char) * (N+1));
    char* exist = (char*)malloc(sizeof(char) * (N+1));
    
    for (int i = 0; i < N; i++){
        int a;
        scanf("%d", &a);
        arr[i] = a + '0';
    }
    
    for (int i = 0; i < N; i++){
        int b;
        scanf("%d", &b);
        exist[i] = b + '0';
    }
    
    insertionsort(arr, exist, N);
    
    //printf("%s", arr);
    
}