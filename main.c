#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void end_msg(int* cnt_move);

int main(void)
{
    FILE* fp = fopen("D:\\�ҽ�\\map.txt", "r");   //map.txt ���� (���� ���� �׻� ����)
    char map[11][11] = { 0, };   //9*9 2���� �迭 map ���� �� �ʱ�ȭ
    int cur_x = 1;      //��ġ��ǥ ���� �� �ʱ�ȭ
    int cur_y = 9;      //�ʱⰪ (1,9)
    int act = 0;      //Action Switch ��� ���� ���� �� �ʱ�ȭ 1, 2, 3, 4
    int cnt_move = 0;   //������ Ƚ�� ���� �� �ʱ�ȭ

    for (int i = 0; i < 11; i++) {      //����ó���� �� ��ü ������ �ʱ�ȭ      ***�� �ʱ�ȭ***
        for (int j = 0; j < 11; j++) {
            map[i][j] = 'X';
        }
    }

    for (int i = 1; i < 11; i++) {      //���⸦ �����ϰ� 2���� �迭�� �� �Է�      ***�� �ε�***
        for (int j = 1; j < 10; j++) {   //�׵θ� �� �۾��� i<height+2, j<width+1
            fscanf(fp, " %c ", &map[i][j]);
        }
    }

    while (map[cur_y][cur_x] != 'F')  //F�������� ���� �ݺ�
    {   
        system("cls");

        ///* ���� ��ġ�� �����¿� Ȯ��      ***��������***
        printf("������ Ƚ�� : %d\n\n", cnt_move);

        printf("������ġ? : %c\n", map[cur_y][cur_x]);
        printf("���� ��ǥ : (%d, %d)\n", cur_y, cur_x);  //�ڡڡ�
        printf("������ġ ���ʿ� ����? : %c\n", map[cur_y - 1][cur_x]);
        printf("������ġ �Ʒ��ʿ� ����? : %c\n", map[cur_y + 1][cur_x]);
        printf("������ġ ���ʿ� ����? : %c\n", map[cur_y][cur_x - 1]);
        printf("������ġ �����ʿ� ����? : %c\n", map[cur_y][cur_x + 1]);
        //*/

        ///* map 2���� �迭 �� Ȯ��      ***�̴ϸ�***
        //�ڡڡ� �ݺ����� Ȱ���ؼ� ���� �����
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }
        //*/

        printf("���� ����? : \n");

        if (map[cur_y - 1][cur_x] != 'x' && map[cur_y - 1][cur_x] != 'X') printf("���� �̵� : 8\n");
        if (map[cur_y + 1][cur_x] != 'x' && map[cur_y + 1][cur_x] != 'X') printf("�Ʒ��� �̵� : 2\n");
        if (map[cur_y][cur_x - 1] != 'x' && map[cur_y][cur_x - 1] != 'X') printf("�������� �̵� : 4\n");
        if (map[cur_y][cur_x + 1] != 'x' && map[cur_y][cur_x + 1] != 'X') printf("���������� �̵� : 6\n");
        scanf("%d", &act);


        switch (act) {   //�̵� ������
        case 8:   //����         y-1
            if (map[cur_y - 1][cur_x] == 'x' || map[cur_y - 1][cur_x] == 'X') break;
            cur_y -= 1;
            cnt_move += 1;
            break;
        case 2:   //�Ʒ���      y+1
            if (map[cur_y + 1][cur_x] == 'x' || map[cur_y + 1][cur_x] == 'X') break;
            cur_y += 1;
            cnt_move += 1;
            break;
        case 4:   //��������      x-1
            if (map[cur_y][cur_x - 1] == 'x' || map[cur_y][cur_x - 1] == 'X') break;
            cur_x -= 1;
            cnt_move += 1;
            break;
        case 6:   //����������   x+1
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