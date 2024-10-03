#include <stdio.h>

int main() {
    unsigned long int S;
    scanf("%lu", &S);
    
    unsigned long int minus = 1;
    int count = 0;
    unsigned long int sum = 0;
    while(1){
        
        if (sum > S){
            count = count-1;
            break;
        }
        else{
            sum = sum+minus;
            minus++;
            count++;
        }
    }
    //printf("%d\n", S);
    printf("%d", count);
}