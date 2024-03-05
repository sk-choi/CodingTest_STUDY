#include <iostream>
#include <string>
#include <stack>
using namespace std;

// push X: 정수 X를 스택에 넣는 연산이다.
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 스택에 들어있는 정수의 개수를 출력한다.
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int length(int* arr, int count)
{
    int leng = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > 0)
            leng = leng + 1;
        else
            continue;
    }
    return leng;
}

int size(int* arr, int count){
    int leng = length(arr, count);
    if (length(arr, count) == 0)
        return 0;
    else
        return leng;
}

int empty(int* arr, int count) {
    if (size(arr, count) == 0)
        return 1;
    else
        return 0;
}

int top(int* arr, int count) {
    if (empty(arr, count) == 1)
        return (-1);
    else
        return arr[size(arr, count) - 1];
}


void push(int* arr, int count) {
    int num;
    cin >> num;

    if (empty(arr, count) == 1)
        arr[0] = num;
    else
        arr[size(arr, count)] = num;
}

int pop(int* arr, int count) {
    int leng = size(arr, count);
    int temp = 0;
    if (empty(arr, count) == 1)
        return (-1);
    else
        temp = arr[leng - 1];
        arr[leng - 1] = -1;
        return temp;
}

int main() {

    int cycle;
    cin >> cycle;
    int* arr{ new int[cycle] {0,} };

    for (int i = 0; i < cycle; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            push(arr, cycle);
        }
        else if (command == "pop")
        {
            int a = pop(arr, cycle);
            cout << a << endl;
        }
        else if (command == "size")
        {
            int b = size(arr, cycle);
            cout << b << endl;
        }
        else if (command == "empty")
        {
            int c = empty(arr, cycle);
            cout << c << endl;
        }
        else if (command == "top")
        {
            int d = top(arr, cycle);
            cout << d << endl;
        }
    }

    return 0;
}
