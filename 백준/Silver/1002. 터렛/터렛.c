#include <stdio.h>
#include <math.h>

int main() {
        
    int num = 0;
    
    scanf("%d", &num);
        
    for (int i = 0; i < num; i++){

        int x1 = 0;
        int y1 = 0;
        int r1 = 0;
        int x2 = 0;
        int y2 = 0;
        int r2 = 0;
        
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        double D = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
        
        if (D > (r1 + r2) || D < abs(r1 - r2)){
            printf("%d\n", 0);
        } else if (D == (r1 + r2) || D == abs(r1 - r2)) {
            if(D == 0){
                printf("%d\n", -1);
            } else {
                printf("%d\n", 1);
            }
        } else if (D < abs(r1 + r2) && D > abs(r1 - r2)){
            printf("%d\n", 2);
        }
    }
}