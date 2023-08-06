#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[100] = {};
    int find;
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cin >> find;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == find)
        {
            count += 1;
        }
        

    }
    cout << count;
}