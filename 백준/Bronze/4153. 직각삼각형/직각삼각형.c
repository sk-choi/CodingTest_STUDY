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
    
    while(1){
        
        int num;
        int arr[3] = {};

        for (int i = 0; i < 3; i++){
            scanf("%d", &num);
            arr[i] = num;
        }
        
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0){
            break;
        }
        else{
            qsort(arr, 3, sizeof(int), compare);
            
            if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == (arr[2] * arr[2])){
                printf("right\n");
            }
            else{
                printf("wrong\n");
            }
        }
        
    }
}