#include <iostream>
using namespace std;

int main()
{
    int yun_year;
    cin >> yun_year;
    
    if (yun_year%4 == 0 && yun_year%100 != 0 || yun_year%400 == 0)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }

return 0;
}