#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ESC 27
#define ENTER 13


void init();
void gotoxy(int, int);
void titleDraw();
int menuDraw();
void infoDraw();
//void gloop();
//void progress(char[][], int);

int main() {
    init();
    while (1) {
        system("cls");
        ;      titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 1) {   //���ӽ���
            //gloop();
        }
        else if (menuCode == 2) {   //���ӹ��
            infoDraw();
            system("cls");
        }
        else if(menuCode == ESC) {
            printf("00000000000000000000000");
            break;
        }
    }

    return 0;
}

void titleDraw() {
    printf("\n\n\n");
    printf("\t\t          __.__                                                          .___      .__  .__ \n");
    printf("\t\t         |__|__| ____    ____             ____   ____  ____   _____    __| _/____  |  | |__|\n");
    printf("\t\t         |  |  |/    \  / ___\   ______  / ___\_/ __ \/  _ \ /     \  / __ |\__  \ |  | |  |\n");
    printf("\t\t         |  |  |   |  \/ /_/  > /_____/ / /_/  >  ___(  <_> )  Y Y  \/ /_/ | / __ \|  |_|  |\n");
    printf("\t\t     /\__|  |__|___| _/\___  /          \___  / \_____>____/|__|_|__/\_____|(______/____/__|\n");
    printf("\t\t     \______|         /_____/          /_____/                                              \n");


}

void init() {
    system("mode con cols=120 lines=30 | title ��������");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
int menuDraw() {
    int a;
    int x = 55;
    int y = 20;
    gotoxy(x, y);
    printf("1. ���ӽ���\n");
    gotoxy(x, y + 1);
    printf("2. ���ӹ��\n");
    gotoxy(x, y + 2);
    scanf_s("%d", &a);
    return a;
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   //�ܼ� �ڵ� ��������
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void infoDraw() {
    system("cls");
    int x = 45;
    int y = 10;
    char s;
    gotoxy(x, y - 1);
    printf("¡�˴ٸ� ���� ���");
    gotoxy(x, y + 1);
    printf("�ȱ��� ¡�˴ٸ��� ���Կ�~\n");
    gotoxy(x, y + 2);
    printf("���� ����, ������ ¡�˴ٸ��� �ǳʼ���!\n");
    gotoxy(x, y + 4);
    printf("�����̽��ٸ� ������ ����ȭ������ ���ư��ϴ�..");

    while (1) {
        s = getch();
        if (s == ' ') break;
    }
}

void gloop() {
    system("cls");
    int index = 17;
    int turn = 17;
    int life = 16;

    boolean arr_bool[18][2] = { 1 };
    char arr_glass[18][2] = { 0 };
    for (int i = 0; i < sizeof(arr_bool); i++) {
        //arr_bool[i][0] = rand().nextBoolean();
        arr_bool[i][1] = !arr_bool[i][0];
        for (int j = 0; j < sizeof(arr_bool[i]); j++) {
            arr_glass[i][j] = '��';
        }
    }

    printf("\n\n\n");
    gotoxy(45, 5);
    gotoxy(45, 5);
    printf("��¡�� ���� ¡�� �ٸ� �ǳʱ�\n\n");
    for (int i = 0; i < 10; i++) {
        gotoxy(45, 10 + i);
        printf("|  ��  ��  |\n");
    }
    while (1) {

    }



    while (1) {
        int ch2;
        progress(arr_glass, turn);
        printf("%d�� ������ ����!\n", 17 - life);
        printf("����� ������?\n1.���� 2. ������\n");
        scanf_s("%d", &ch2);
        if (ch2 == 1 || ch2 == 2) {
            if (arr_bool[index][ch2 - 1] == 1) {
                printf("����!\n");
                index--;
                turn--;
            }
            else {
                printf("���!\n");
                arr_glass[index][ch2 - 1] = ' ';
                index = 17;
                turn = 17;
                life--;
            }
        }
        if (life == 0) {
            printf("���ӿ���!\n");
            break;
        }
        else if (turn == -1) {
            break;
            printf("���!!!\n");
        }
    }
}

void progress(char arr_glass[][], int turn) {
    for (int i = 0; i < sizeof(arr_glass); i++) {
        printf("|");
        for (int j = 0; j < sizeof(arr_glass[i]); j++) {
            printf("  " + arr_glass[i][j] + "  ");
        }
        printf("|");
        if (i == turn + 1)
            printf("<--------����ġ\n");
        else
            printf("\n");
    }
}

}