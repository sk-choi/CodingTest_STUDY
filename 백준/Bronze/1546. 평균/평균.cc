#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[1000] = {};
	double b[1000] = {};
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = (a[i] / max) * 100;
		sum = sum + b[i];
	}
	cout << fixed;
	cout.precision(6);
	cout << double(sum / n);
}