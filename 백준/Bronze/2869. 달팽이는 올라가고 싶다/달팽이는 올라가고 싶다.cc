#include<iostream>
using namespace std;

//날짜 = n이라면,
//낮에 도착하는 경우만 존재...
//이미 목표에 도착하고 나서 다시 내려가는 경우는 없다!
//
//따라서 길이의 범위 :
//(n - 2)(A - B) + A < v <= (n - 1)(A - B) + A
//
//(n - 2)(A - B) < v - A = > (n - 2) < (v - A) / (A - B) = > n < (v - A) / (A - B) + 2
//
//v - A <= (n - 1)(A - B) = >(v - A) / (A - B) <= (n - 1) = >(v - A) / (A - B) + 1 <= n
//
//
//따라서(v - A) / (A - B) + 1 <= n < (v - A) / (A - B) + 2라는 공식 도출...
//
//따라서(v - A) / (A - B) 에서 나머지가 0이면(v - A) / (A - B) + 1,
//(v - A) / (A - B)에서 나머지가 0이 아니라면(v - A) / (A - B) + 2 대입




int main()
{
    int up, down, v;
    cin >> up >> down >> v;

    int day = (v - up) / (up - down);
    
    if (((v - up) % (up - down)) == 0)
    {
        cout << day + 1;
    }
    else
    {
        cout << day + 2;
    }
    
   
    return 0;
}