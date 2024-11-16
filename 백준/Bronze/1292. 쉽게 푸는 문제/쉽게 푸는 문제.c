#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int* arr = (int*)calloc((b+1), sizeof(int));
    
    int sum = 0;
    int j = 1;
    for (int i = 1; i <= b; i++){
        int num = i;
        while(num-- > 0){
            if(j > b){
                break;
            }
            sum += i;
            arr[j] = sum;
            j++;
        }
    }
    
    printf("%d", arr[b] - arr[a-1]);
    
}