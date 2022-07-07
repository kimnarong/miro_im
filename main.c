#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void end_msg(int* cnt_move);

int main(void)
{
    FILE* fp = fopen("D:\\소스\\map.txt", "r");   //map.txt 열기 (지도 설정 항상 수정)
    char map[11][11] = { 0, };   //9*9 2차원 배열 map 선언 및 초기화
    int cur_x = 1;      //위치좌표 선언 및 초기화
    int cur_y = 9;      //초기값 (1,9)
    int act = 0;      //Action Switch 상수 변수 선언 및 초기화 1, 2, 3, 4
    int cnt_move = 0;   //움직인 횟수 선언 및 초기화

    for (int i = 0; i < 11; i++) {      //예외처리를 맵 전체 벽으로 초기화      ***맵 초기화***
        for (int j = 0; j < 11; j++) {
            map[i][j] = 'X';
        }
    }

    for (int i = 1; i < 11; i++) {      //띄어쓰기를 제외하고 2차원 배열에 값 입력      ***맵 로딩***
        for (int j = 1; j < 10; j++) {   //테두리 벽 작업시 i<height+2, j<width+1
            fscanf(fp, " %c ", &map[i][j]);
        }
    }

    while (map[cur_y][cur_x] != 'F')  //F도착까지 게임 반복
    {   
        system("cls");

        ///* 현재 위치와 상하좌우 확인      ***현재정보***
        printf("움직인 횟수 : %d\n\n", cnt_move);

        printf("현재위치? : %c\n", map[cur_y][cur_x]);
        printf("현재 좌표 : (%d, %d)\n", cur_y, cur_x);  //★★★
        printf("현재위치 위쪽에 무엇? : %c\n", map[cur_y - 1][cur_x]);
        printf("현재위치 아래쪽에 무엇? : %c\n", map[cur_y + 1][cur_x]);
        printf("현재위치 왼쪽에 무엇? : %c\n", map[cur_y][cur_x - 1]);
        printf("현재위치 오른쪽에 무엇? : %c\n", map[cur_y][cur_x + 1]);
        //*/

        ///* map 2차원 배열 값 확인      ***미니맵***
        //★★★ 반복문을 활용해서 지도 만들기
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        //*/

        printf("어디로 갈까? : \n");

        if (map[cur_y - 1][cur_x] != 'x' && map[cur_y - 1][cur_x] != 'X') printf("위로 이동 : 8\n");
        if (map[cur_y + 1][cur_x] != 'x' && map[cur_y + 1][cur_x] != 'X') printf("아래로 이동 : 2\n");
        if (map[cur_y][cur_x - 1] != 'x' && map[cur_y][cur_x - 1] != 'X') printf("왼쪽으로 이동 : 4\n");
        if (map[cur_y][cur_x + 1] != 'x' && map[cur_y][cur_x + 1] != 'X') printf("오른쪽으로 이동 : 6\n");
        scanf("%d", &act);


        switch (act) {   //이동 선택지
        case 8:   //위로         y-1
            if (map[cur_y - 1][cur_x] == 'x' || map[cur_y - 1][cur_x] == 'X') break;
            cur_y -= 1;
            cnt_move += 1;
            break;
        case 2:   //아래로      y+1
            if (map[cur_y + 1][cur_x] == 'x' || map[cur_y + 1][cur_x] == 'X') break;
            cur_y += 1;
            cnt_move += 1;
            break;
        case 4:   //왼쪽으로      x-1
            if (map[cur_y][cur_x - 1] == 'x' || map[cur_y][cur_x - 1] == 'X') break;
            cur_x -= 1;
            cnt_move += 1;
            break;
        case 6:   //오른쪽으로   x+1
            if (map[cur_y][cur_x + 1] == 'x' || map[cur_y][cur_x + 1] == 'X') break;
            cur_x += 1;
            cnt_move += 1;
            break;
        default:
            break;
        }
        act = 0;
    }

    end_msg(&cnt_move);

    fclose(fp);
    return 0;

}

void end_msg(int* cnt_move) {
    printf("FINISH!!!!!!!!\n");
    printf("You Moved %d Times\n", *cnt_move);
    printf("FINISH!!!!!!!!\n");
}