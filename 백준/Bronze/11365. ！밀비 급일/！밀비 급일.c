#include <stdio.h>
#include <string.h>

int main(){
    char crypto[501] = {};


    while(1){
        fgets(crypto, sizeof(crypto), stdin);
        crypto[strcspn(crypto, "\n")] = 0; //strcspn을 사용하면 개행문자를 찾아 거기에 널 문자를 넣는다.
        if (strcmp(crypto, "END") == 0){
            break;
        }
        else{
            for(int i = strlen(crypto)-1; i >= 0; i--){
                printf("%c", crypto[i]);
            }
            printf("\n");
        }
    }
}