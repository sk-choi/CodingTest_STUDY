#include <stdio.h>
#include <string.h>

int main() {
  
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++){
      char words[101] = {};
      
      scanf("%s", words);
      printf("%c%c\n", words[0], words[strlen(words)-1]);
  }
  
  
}