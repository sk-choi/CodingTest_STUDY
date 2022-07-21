#include<iostream>
using namespace std;

int d(int n)
{
	int new_num;
	new_num = (n / 1000) + ((n % 1000) / 100) + ((n% 100) / 10) + (n % 10) + n;
	return new_num;
}


int main()
{
	bool num[10025] = {}; //d(9993) + 1 크기의 배열
	for (int i = 0; d(i) <= 10024; i++)
	{
		num[d(i)] = true;
		
		if (num[i] == !num[d(i)])
		{
			cout << i << endl;
		}
		
	}
	return 0;
}