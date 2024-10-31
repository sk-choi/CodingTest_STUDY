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
    
    int A_count, B_count;
    
    scanf("%d %d", &A_count, &B_count);
    
    int* set_A = (int*)malloc(sizeof(int) * A_count);
    int* set_B = (int*)malloc(sizeof(int) * B_count);
    
    for (int i = 0; i < A_count; i++){
        int num;
        scanf("%d", &num);
        
        set_A[i] = num;
    }
    
    for (int i = 0; i < B_count; i++){
        int num;
        scanf("%d", &num);
        
        set_B[i] = num;
    }
    
    qsort(set_A, A_count, sizeof(int), compare);
    qsort(set_B, B_count, sizeof(int), compare);
    
    int count01 = 0; 
    int count02 = 0;
    
    for (int i = 0; i < B_count; i++){
        if (bsearch(&set_B[i], set_A, A_count, sizeof(int), compare) == NULL){
            count01++;
        }
    }
    
    for (int i = 0; i < A_count; i++){
        if (bsearch(&set_A[i], set_B, B_count, sizeof(int), compare) == NULL){
            count02++;
        }
    }
    printf("%d", count01+count02);
    
    
}