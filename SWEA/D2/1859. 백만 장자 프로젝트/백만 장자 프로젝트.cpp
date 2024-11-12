/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
 
using namespace std;
 
int max(int start, int end, int arr[]){
     
    int maxim = arr[start];
    for(int i = start+1; i < end; i++){
        if (maxim < arr[i]){
            maxim = arr[i];
        }
    }
    return maxim;
}
 
int main() {
     
    int test_case;
    int T;
     
    cin>>T;
     
    for(test_case = 1; test_case <= T; ++test_case){
        
       int soldday;
       long long int result = 0;
       cin >> soldday;
       
       int* arr = new int[soldday];
       
       for (int i = 0; i < soldday; i++){
           cin >> arr[i];
       }
       
       int last = soldday - 1;
       for (int i = soldday-2; i >= 0; i--){
           if (arr[last] < arr[i]){
               //result += (count * arr[last]) - profit;
               last = i;
           }
           else{
                result += arr[last] - arr[i];
                
           }
       }
       cout << "#" << test_case <<  ' ' << result << "\n"; 
       
       delete[] arr;
    }
     
     
    return 0;
}