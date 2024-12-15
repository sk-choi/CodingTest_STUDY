#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int cnt;
    scanf("%d", &cnt);
    
    for (int i = 0; i < cnt; i++){
    
        int H; //  높이
        int W; //  너비
        int N; //  몇 번째 손님인지
    
        scanf("%d %d %d", &H, &W, &N);
    
        int room_num = 101;
        int refloor = room_num;
        int floor_cnt = 1;
        for(int i = 1; i < N; i++){
            if (floor_cnt == H){ //층 세는 횟수가 높이까지 도달하면 다시 1층으로(시작점의 다음 호실로)
                refloor += 1;
                room_num = refloor;
                floor_cnt = 1;
            }
            else { // 아니면 100씩 증가해서 윗층으로
                room_num += 100;
                floor_cnt += 1;
            }
        }
        printf("%d\n", room_num);
    }
}