#include <stdio.h>

int number(a, b, n){
    
    int temp = 0;
    
    if (n == 0)
        return (a / b);
    else{
        temp = a % b;
        temp = temp * 10;
        return number(temp, b, n-1);
    }
}

//A나누기B를 했을 때 N번째 소수자리 수 구하기

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    
    printf("%d", number(a, b, n));
    
    
    return 0;
}