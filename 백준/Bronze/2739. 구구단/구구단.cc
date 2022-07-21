#include <iostream>
using namespace std;

int main()
{
    int N;
    int multi;
    cin >> N;
    for (int i = 1; i < 10; i++)
    {
        multi = N * i;
        cout << N << " * " << i << " = " << multi << endl;
    }
    return 0;
}