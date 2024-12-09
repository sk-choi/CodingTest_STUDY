#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int N;
    scanf("%d", &N);
    
    long int* arr = (long int*)calloc((N+1), sizeof(long int));

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    
    for (int i = 3; i <= N; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    printf("%ld", arr[N]);
}