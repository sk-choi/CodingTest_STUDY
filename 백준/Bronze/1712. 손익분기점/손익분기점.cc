#include <iostream>
using namespace std;

int main()
{
	long long int a, b, c; //각각 고정비용, 가변비용, 가격
	cin >> a >> b >> c;

	if (b >= c)
	{
		cout << -1 << endl;
	}

	else
	{
		cout << a / (c - b) + 1;
	}
	
	
	return 0;
}