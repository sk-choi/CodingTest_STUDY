#include<iostream>
using namespace std;

int main()
{
	int A;
	int B; 
	int C;
	cin >> A >> B >> C;
	int abc = A * B * C;
	int num = -1; //while문 안에서 한 번 돌 때 0부터 시작해야 하므로 -1로 초기화

	int arr[10] = {};//배열 초기화

	while (abc > 0)
	{
		num = abc % 10; //세 숫자의 곱을 10으로 나눈 나머지를 num에 할당
		arr[num]++; //나머지가 있는 인덱스부터 1씩 더해서 증가시킴
		abc = abc/10; //abc는 abc를 10으로 나눈 값으로 갱신
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl; //arr[]배열의 값을 인덱스 0부터 출력
	}
	return 0;
}