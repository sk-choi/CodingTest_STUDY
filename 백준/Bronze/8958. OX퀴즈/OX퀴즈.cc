#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int num = 0;
	int n;
	cin >> n;
	char ox[80] = {};
	int score = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> ox;

		for (int j = 0; j < strlen(ox); j++)
		{
			if (ox[j] == 'O')
			{
				score++;
				count += score;
			}
			if (ox[j] == 'X')
			{
				score = 0;
			}

		}
		cout << count << endl;
		count = 0;
		score = 0;
	}
	return 0;
}