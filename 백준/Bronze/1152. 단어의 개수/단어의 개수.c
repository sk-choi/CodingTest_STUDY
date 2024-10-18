#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000001] = {};
    
    scanf("%[^\n]s", sentence);
    
    int i = 0;
    
    int len = strlen(sentence);
    
    if (sentence[0] == ' '){
        sentence[0] = '0';
    }
    if (sentence[len-1] == ' '){
        sentence[len-1] = '0';
    }
    
    int count = 0;
    while (i < len){
        if (sentence[i] == ' '){
            count++;
        }
        i++;
    }
    if (sentence[0] == '0' && len == 1){
            count = 0;
    }
    else
        count++;
    
    printf("%d", count);
    
}