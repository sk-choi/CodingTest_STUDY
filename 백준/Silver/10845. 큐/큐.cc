#include <iostream>
#include <string>
#include <queue>
using namespace std;

// push X : 정수 X를 큐에 넣는 연산이다.
// pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// size : 큐에 들어있는 정수의 개수를 출력한다.
// empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
// front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
// back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.

/*int size(int* arr, int count) {

	int leng = 0;
	for (int i = 0; i < count; i++)
	{
		if (arr[i] > 0)
			leng = leng + 1;
		else
			continue;
	}
	if (leng <= 0)
		return 0;
	else
		return leng;
}

int empty(int* arr, int count) {
	if (size(arr, count) == 0)
		return 1;
	else
		return 0;
}

void push(int* arr, int count) {
	int num;
	cin >> num;
	if (empty(arr, count) == 1)
		arr[0] = num;
	else
		arr[size(arr, count)] = num;
}

int pop(int* arr, int count) {

	int temp = 0;
	if (empty(arr, count) == 1)
		return (-1);
	else
		temp = arr[0];
	for (int i = 0; i < size(arr, count); i++)
	{
		arr[i] = arr[i + 1];
	}
	//arr[size(arr, count)] = 0;
	return temp;
}

int front(int* arr, int count) {
	if (empty(arr, count) == 1)
		return (-1);
	else
		return arr[0];
}

int back(int* arr, int count) {

	int temp = 0;
	if (empty(arr, count) == 1)
		return (-1);
	for (int i = size(arr, count) - 1; i >= 0; i--)
	{
		if (arr[i] <= 0)
			arr[i] = arr[i];
		else
			temp = i;
		break;
	}
	return arr[temp];
}
*/
int main() {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int cycle = 0;
	cin >> cycle;

	//int* arr = { new int[cycle] {0,} };
	//int a, b, c, d, e = 0;

	queue<int> que;
	for (int i = 0; i < cycle; i++)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}
		else if (command == "pop")
		{
			if (que.empty() == 0) {
				cout << que.front() << endl;
				que.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (command == "size")
		{
			cout << que.size() << endl;
		}
		else if (command == "empty")
		{
			cout << que.empty() << endl;
		}
		else if (command == "front")
		{
			if (que.empty() == 0) {
				cout << que.front() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (command == "back")
		{
			if (que.empty() == 0) {
				cout << que.back() << endl;
			}
			else
				cout << -1 << endl;
		}
	}

	return 0;
}