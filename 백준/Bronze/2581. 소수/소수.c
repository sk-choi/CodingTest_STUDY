#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int start, end;
    
    scanf("%d", &start);
    scanf("%d", &end);

    int flag = 0;
    int sum = 0;
    int min = 0;
    for (int i = start; i <= end; i++){
        int count = 0;
        for (int j = 1; j <= i; j++){
        
            if (i % j == 0){
                count++;
            }
        }
    
        if (count == 2){
            sum += i;
            if (flag == 0){
                min = i;
                flag = 1;
            }
        }   
    }
    
    if (sum != 0){
        printf("%d\n", sum);
        printf("%d", min);
    }
    else{
        printf("%d", -1);
    }
}

//2,3,5,7,11