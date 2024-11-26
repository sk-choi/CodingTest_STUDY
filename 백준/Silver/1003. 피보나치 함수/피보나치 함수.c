#include <stdio.h>
#include <stdlib.h>


int main(void){
    
    int* arr_0 = (int*)calloc(41, sizeof(int));
    int* arr_1 = (int*)calloc(41, sizeof(int));
    
    arr_0[0] = 1;
    arr_1[1] = 1;
    
    for (int i = 2; i <= 40; i++){
        arr_0[i] = arr_0[i-1] + arr_0[i-2];
        arr_1[i] = arr_1[i-1] + arr_1[i-2];
    }
    
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++){
        int num;
        scanf("%d", &num);
        
        printf("%d %d\n", arr_0[num], arr_1[num]);
        
    }

}