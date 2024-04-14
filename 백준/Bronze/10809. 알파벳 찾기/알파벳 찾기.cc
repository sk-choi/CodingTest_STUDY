#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string a = "abcdefghijklmnopqrstuvwxyz";
	

	for (int i = 0; i < 26; i++) //a의 길이만큼 반복, 알파벳 개수인 26으로 해도 되고 a.length()를 사용해도 결과는 같다.
	{
		cout << (int)s.find(a[i]) << " "; //원하는 문자의 위치를 찾는 find함수를 사용한다. 찾는 문자열이 없을 경우 -1을 리턴 
	}
	return 0;
}