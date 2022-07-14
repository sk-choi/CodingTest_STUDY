#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int n1 = n % 10;
	int n2 = (n % 10 + n / 10) % 10;
	int n3= -1;
	int count = 0;

	while (n3 != n) {

		n3 = (n1 * 10) + n2;
		n1 = n2;
		n2 = (n3 / 10 + n3 % 10) % 10;
		count++;

	}
	cout << count;
}