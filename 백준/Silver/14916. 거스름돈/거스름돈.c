#include <stdio.h>

int main(void){
    
    int n;
    scanf("%d", &n);
    
    int five = 0;
    int two = 0;
    int m = 0;
    int result = 0;
    if ((n == 1) || (n == 3)){
        printf("%d", -1);
    }
    
    else if ((n % 5) != 0){
        five = (n/5); //2
        m = n - (5 * five);
        if ((m % 2) == 0){
            two = m/2;
            result = five+two;
            printf("%d", result);
        }
        else{
            five = five - 1; //2-1 =1 
            m = n - (5 * five); // 13-5 = 8
            if ((m % 2) != 0){
                result = -1;
                printf("%d", result);
            }
            else{
                two = m/2; // 8나누기 2 = 4;
                result = five+two;
                printf("%d", result);
            }
        }
    }
    else
        printf("%d", (n / 5));
}