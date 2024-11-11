#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string word;
    
    cin >> word;
    
    int len = word.length();
    
    int count = 0;
    for (int i = 0; i < len; i++){
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            count++;
        }
    } 
    
    printf("%d", count);
}