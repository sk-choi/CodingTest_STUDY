#include <iostream>
using namespace std;
#include <array>
//500, 100, 50, 10, 5, 1

int main()
{
    int input; 
    cin >> input;
    int rest = 1000 - input;
    int count = 0;

    rest / 500;
    count += (rest / 500);
    rest = rest % 500;
    rest / 100;
    count += (rest / 100);
    rest = rest % 100;
    rest / 50;
    count += (rest / 50);
    rest = rest % 50;
    rest / 10;
    count += (rest / 10);
    rest = rest % 10;
    rest / 5;
    count += (rest / 5);
    rest = rest % 5;
    rest / 1;
    count += (rest / 1);
    rest = rest % 1;

    cout << count;
    return 0;

}