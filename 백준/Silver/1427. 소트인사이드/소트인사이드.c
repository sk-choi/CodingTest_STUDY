#include <stdio.h>
#include <string.h>

int main(void){
    
    char arr[100];
    
    scanf("%s", &arr);
    
    for (int i = 0; i < strlen(arr)-1; i++){
        for (int j = i+1; j < strlen(arr); j++){
            if (arr[i] < arr[j]){
                char temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("%s", arr);
    
}
