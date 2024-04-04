#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {

	deque<int> deque1;

	int cycle;
	cin >> cycle;
	for (int i = 0; i < cycle; i++) {
		string oper;
		cin >> oper;

		if (oper == "push_front") {
			int num;
			cin >> num;
			deque1.push_front(num);
		}
		else if (oper == "push_back") {
			int num;
			cin >> num;
			deque1.push_back(num);
		}
		else if (oper == "pop_front") {
			//empty 조건 추가
			if (deque1.empty() == 0){
				cout << deque1.front() << endl;
				deque1.pop_front();
			}
			else
				cout << -1 << endl;
		}
		else if (oper == "pop_back") {
			//empty 조건 추가
			if (deque1.empty() == 0) {
				cout << deque1.back() << endl;
				deque1.pop_back();
			}
			else
				cout << -1 << endl;
		}
		else if (oper == "size") {
			cout << deque1.size() << endl;
		}
		else if (oper == "empty") {
			cout << deque1.empty() << endl;
		}
		else if (oper == "front") {
			if (deque1.empty() == 0)
				cout << deque1.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (oper == "back") {
			if (deque1.empty() == 0)
				cout << deque1.back() << endl;
			else
				cout << -1 << endl;
		}
	}
}
