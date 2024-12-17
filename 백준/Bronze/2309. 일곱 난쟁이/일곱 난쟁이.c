#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int* aa = (int*)a;
    int* bb = (int*)b;
    
    if(*aa > *bb){
        return 1;
    }
    else if(*aa < *bb){
        return -1;
    }
    else{
        return 0;
    }
}

int main(){
    int arr[9] = {};
    int result[7] = {};
    
    for (int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
    }
    
    int add = 0;
    for (int a = 0; a < 3; a++){
        for (int b = a+1; b < 4; b++){
            for (int c = b+1; c < 5; c++){
                for (int d = c+1; d < 6; d++){
                    for (int e = d+1; e < 7; e++){
                        for (int f = e+1; f < 8; f++){
                            for (int g = f+1; g < 9; g++){
                                add = arr[a] + arr[b] + arr[c] + arr[d] + arr[e] + arr[f] + arr[g];
                                if (add == 100){
                                    result[0] = arr[a];
                                    result[1] = arr[b];
                                    result[2] = arr[c];
                                    result[3] = arr[d];
                                    result[4] = arr[e];
                                    result[5] = arr[f];
                                    result[6] = arr[g];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    qsort(result, 7, sizeof(int), compare);
    
    for (int i = 0; i < 7; i++){
        printf("%d\n", result[i]);
    }
    
}