#include <stdio.h>
#include <string.h>

int main() {
    
    while(1){
        char input[6] = {};
        int flag = 0;
        scanf("%s", input);
        if (strcmp(input, "0") == 0){
            break;
        }
        else {
            int num = strlen(input);
            int len = num/2;
            for (int i = 0; i < len; i++){
                if (input[i] == input[num-i-1]){
                    flag = 0;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
}