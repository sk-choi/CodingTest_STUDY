#include<iostream>
using namespace std;

int main()
{
    int hour, min, sec, plus;
    cin >> hour >> min >> sec >> plus;
    int total = hour * 3600 + min * 60 + sec + plus;
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = (total % 3600) % 60;

    if (h >= 24)
    {
        while (h >= 24) 
        {
            h = h - 24;
        }
    }
    cout << h << " " << m << " " << s;
}