#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int data[], int left, int right){
    int first = left;
    int pivot_index = left + rand() % (right-left+1);
    swap(&data[first], &data[pivot_index]);
    
    int pivot = data[first];
    ++left;
    
    while(left <= right){
        while(data[left] >= pivot && left <= right){
            left++;
        }
        while(data[right] < pivot && left <= right){
            right--;
        }
        if (left <= right){
            swap(&data[left], &data[right]);
        }
        else{
            break;
        }
    }
    if (data[first] != data[right]){
        swap(&data[first], &data[right]);
    }
    
    return right;
}

void quicksort(int data[], int left, int right){
    if (left <= right){
        int index = partition(data, left, right);
        quicksort(data, left, index-1);
        quicksort(data, index+1, right);
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int)*N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    int length = N; //sizeof(arr)은 포인터 크기를 반환하기 때문에 sizeof(arr)/sizeof(int) 사용하면 오류 발생;
    
    quicksort(arr, 0, length-1);
    
    for(int i = 0; i < length; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    
}