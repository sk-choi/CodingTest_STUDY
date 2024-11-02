#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagword{
    
    char word[502];
    
} Words;


int compare(const void* a, const void* b){
    
    Words* aa = (Words*)a;
    Words* bb = (Words*)b;
    
    return (strcmp(aa->word, bb->word));
    
}

int main(void){
    
    int A;
    int B;
    scanf("%d %d", &A, &B);
    
    Words* set = (Words*)malloc(sizeof(Words) * A);
    
    for (int i = 0; i < A; i++){
        scanf("%s", set[i].word);
    }
    
    qsort(set, A, sizeof(Words), compare);
    
    int count = 0;
    
    for (int i = 0; i < B; i++){
        char input[502];
        scanf("%s", input);
        if (bsearch(&input, set, A, sizeof(Words), compare) != NULL){
            count++;
        }
    }
    printf("%d", count);
    
    //for (int i = 0; i < B; i++){
    //    printf("%s\n", set[i].word);
    //}
}