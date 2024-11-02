#include <stdio.h>
#include <string.h>

int main(void){
    char word[101] = {};
    
    scanf("%s", &word);
    
    int length = strlen(word);
    
    int* alphabet = (int*)calloc(26, sizeof(int));
    
    for (int i = 0; i < length; i++){
        int index = word[i] - 'a';
        
        alphabet[index]++;
    }
    
    for (int i = 0; i < 26; i++){
        printf("%d ", alphabet[i]);
    }
    
}