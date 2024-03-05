#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int A, B;
    for (int i = 1; i <= T; i++)
    {
        cin >> A >> B;
        cout << A + B << "\n";
    }
}