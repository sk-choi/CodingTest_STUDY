#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string input;
        cin >> input;

        stack<char> stack;
        bool is_valid = true;

        for (int j = 0; j < input.length(); j++) {
            char current_char = input[j];
            if (current_char == '(') {
                stack.push(current_char);
            } else if (current_char == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    is_valid = false;
                    break;
                }
            } else {
                is_valid = false; // 괄호가 아닌 문자가 있음
                break;
            }
        }

        if (is_valid && stack.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}