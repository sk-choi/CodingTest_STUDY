#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int set[] = {1, 2, 4, 8, 16, 32, 64};
    
    int X;
    
    scanf("%d", &X);
    
    int count = 0;
    int index = 6;
    while(1){
        
        if (X == 0){
            break;
        }
        else{
            if (X <= set[index] && X >= set[index-1]){
                if (X == set[index]){
                    X = X - set[index];
                }
                else{
                    X = X - set[index-1];
                }
                count++;
            }
            else{
                index--;
            }
        }
    }
    printf("%d", count);
}