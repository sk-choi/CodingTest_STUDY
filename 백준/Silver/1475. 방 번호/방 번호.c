#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int arr[]){
    
    int min_num = arr[0];
    for (int i = 1; i <= 9; i++){
        if (min_num > arr[i]){
            min_num = arr[i];
        }
    }
    return min_num;
}

int main(void){
    
    int number[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    char input[1000001] = {};
    
    scanf("%s", &input);
    
    int len = strlen(input);
    
    for (int i = 0; i < len; i++){
        int index = input[i] - '0';
        
        if (input[i] == '6' || input[i] == '9'){
            if(number[6] > number[9]){
                number[6]--;
            }
            else if (number[6] < number[9]){
                number[9]--;
            }
            else{
                number[index]--;
            }
        }
        else{
            number[index]--;
        }

    }
    
    int result = 1 - min(number);
    
    printf("%d\n", result);
    

}