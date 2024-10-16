#include <stdio.h>

int min(int arr[], int length){
    
    int min = arr[0];
    for (int i = 1; i < length; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int main(void){
    int burger[3] = {0,};
    int beverage[2] = {0,};
    
    for (int i = 0; i < 5; i++){
        if (i <= 2){
            scanf("%d", &burger[i]);
        }
        else if(i > 2){
            scanf("%d", &beverage[i-3]);
        }
    }
    
    int bg_len = sizeof(burger)/sizeof(burger[0]);
    int br_len = sizeof(beverage)/sizeof(beverage[0]);
    //printf("%d", br_len);
    
    //printf("%d", min(burger, bg_len));
    //printf("%d", min(beverage, br_len));
    int total = min(burger, bg_len) + min(beverage, br_len) - 50;
    
    printf("%d", total);
    
}