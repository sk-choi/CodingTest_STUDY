#include <iostream>
using namespace std;

int main()
{
	//2007년 1월 1일은 월요일
	int x , y;
	cin >> x >> y;
	//2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int resultdays = 0;

	resultdays += y;
	for (int i = 0; i < x-1; i++) //각 달의 요일 수 더하기
	{
		resultdays += month[i];
	}

	switch (resultdays % 7)//7로 나눈 나머지를 통해 요일 출력
	{
	case 0: 
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2: 
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5: 
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;

	}

	return 0;
}