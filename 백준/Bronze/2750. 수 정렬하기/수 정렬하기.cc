#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int* array = new int[num];
	int i, j, temp, id = 0, min;

	for (int i = 0; i < num; i++)
	{
		cin >> array[i];
	}

	for (i = 0; i < num; i++)
	{
		min = 1001;
		for (j = i; j < num; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				id = j;
			}
		}
		temp = array[i];
		array[i] = array[id];
		array[id] = temp;
	}

	for (int i = 0; i < num; i++)
	{
		cout << array[i] << endl;
	}
}