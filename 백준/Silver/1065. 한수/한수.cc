#include<iostream>
using namespace std;

int count_arithmetic(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int a = i / 100;
		int b = (i % 100) / 10;
		int c = i % 10;
		if ((a <= b <= c) || (a >= b >= c) || (a==b==c))
		{
			if ((a - b) == (b - c) && (b - c) == c || (b - a) == (c - b))
			{
				count++;
			}
			else if (i < 100)
			{
				if (c == c)
				{
					count++;
				}
			}
			else if ((a == b) && (b == c))
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int num;
	cin >> num;
	cout << count_arithmetic(num);
}