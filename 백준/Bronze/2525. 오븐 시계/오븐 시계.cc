#include <iostream>
using namespace std;

int main()
{
    int hour;
    int minute;
    int addtime;

    cin >> hour >> minute;
    cin >> addtime;

    int sum = (hour * 60) + minute + addtime;

    if ((sum / 60) < 24)
    {
        cout << sum / 60 << " " << sum % 60;
    }
    else if ((sum / 60) >= 24)
    {
        cout << (sum / 60) - 24 << " " << sum % 60;
    }

    return 0;
}