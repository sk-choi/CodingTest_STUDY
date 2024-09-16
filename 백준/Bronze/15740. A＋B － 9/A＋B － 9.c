#include <stdio.h>
#include <string.h>

int main() {

	char num1[10001] = {'\0'};
	char num2[10001] = {'\0'};
	char total[11000] = {'\0'};
	
    scanf("%s %s", num1, num2);
    
    int i = strlen(num1)-1;
    int j = strlen(num2)-1;
    int k = 0;
    
    int mok = 0;
    int A = 0;
    int B = 0;
    while((i >= 0) || (j >= 0)){
            
        if ((i >= 0) && (j >= 0)){
            A = (int)num1[i] -'0';
            B = (int)num2[j] -'0';
        }
        else if (i < 0){
            A = 0;
            B = (int)num2[j] -'0';
        }
        else if (j < 0){
            A = (int)num1[i] -'0';
            B = 0;
        }
        
        if(A + B + mok <= 9){
            total[k] = (A + B + mok) % 10 + '0';
            mok = 0;
        }
        else{
            total[k] = (A + B + mok) % 10 + '0';
            mok = 1;
        }
    
        //printf("%c", total[k]);
        i--;
        j--;
        k++;
    }
    if (mok >=1){
        total[k] = '1';
        k++;
    }
    total[k] = '\0';
    
    for (int i = k-1; i >= 0; i--){
        printf("%c", total[i]);
    }    
}