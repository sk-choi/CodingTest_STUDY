#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int* aa = (int*)a;
    int* bb = (int*)b;
    
    if (*aa > *bb){
        return 1;
    }
    else if (*bb > *aa){
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
   
   int n;
   scanf("%d", &n);
   
   int* arr = (int*)malloc(sizeof(int) * n);
   
   for (int i = 0; i < n; i++){
       scanf("%d", &arr[i]);
   }
   
   qsort(arr, n, sizeof(int), compare);
   
   int result = 0;
   int sum = 0;
   for (int i = 0; i < n; i++){
       for (int j = 0; j <= i; j++){
           sum += arr[j];
       }
       result += sum;
       sum = 0; // 1 2 3 3 4
   }
   
   printf("%d", result);
   
   
}