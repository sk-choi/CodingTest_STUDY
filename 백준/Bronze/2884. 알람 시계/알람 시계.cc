#include <iostream>
using namespace std;

int main() {
    int H;
    int M;
    cin >> H >> M;
   
    if (M < 45)
    {
        H = H - 1;
        M = M + 15;
        if (H < 0)
        {
            H = 23;
        }
        cout << H << " " << M << endl;
    }
    else
    {
        M = M - 45;
        cout << H << " " << M << endl;
    }
return 0;
}   