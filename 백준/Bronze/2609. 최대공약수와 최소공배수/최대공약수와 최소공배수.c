#include <stdio.h>

int GCB(int a, int b){ // 최대 공약수
    
    int A = 0;
    int B = 0;
    if (a > b){ // 큰 수에 작은 수 나눠서 하기 때문
        A = a;
        B = b;
    }
    else {
        A = b;
        B = a;
    }
    
    if(A % B == 0){
        return B;
    }
    else{
        GCB(B, A%B);
    }
    
}

int LCM(int a, int b, int r){ // 최소 공배수
    return (a*b)/r;
}

int main(){
    
    int A;
    int B;
    
    scanf("%d %d", &A, &B);
    
    int n = GCB(A, B);
    
    printf("%d\n", n);
    
    printf("%d", LCM(A, B, n));
    
}