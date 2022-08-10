#include<iostream>
using namespace std;


int main()
{
	string num1, num2;
	cin >> num1 >> num2;
	string max;

	for (int i = 2; i >= 0; i--)
	{
		if (num1[i] > num2[i])
		{
			max = num1; 
            break;
		}
		if (num1[i] < num2[i])
		{
			max = num2; 
            break;
		}
	}
	cout << max[2] << max[1] << max[0];
}