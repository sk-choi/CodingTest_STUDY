#include <stdio.h>
#include <stdlib.h>

int main() {

    int* arr = (int*)malloc(sizeof(int) * 8);
    //int* test = (int*)malloc(sizeof(int) * 7)
    int ascending = 0;
    int descending = 0;
    int mixed = 0;
    
    for (int i = 0; i < 8; i++){
        scanf("%d", &arr[i]);
        if (i > 0){
            if(arr[i-1] - arr[i] == -1){
                ascending = 1;
            }
            else if(arr[i-1] - arr[i] == 1){
                descending = 1;
            }
            else{
                mixed = 1;
            }
        }
    }
    
    if (mixed == 1 || (ascending == 1 && descending == 1)){ 
        printf("mixed");
    }
    else{
        if (ascending == 1 && descending != 1){
            printf("ascending");
        }
        else if (descending == 1 && ascending != 1){
            printf("descending");
        }
    }
    
    
}