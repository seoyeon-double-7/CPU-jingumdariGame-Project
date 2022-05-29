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
        if (menuCode == 1) {   //게임시작
            //gloop();
        }
        else if (menuCode == 2) {   //게임방법
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
    system("mode con cols=120 lines=30 | title 게임제목");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
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
    printf("1. 게임시작\n");
    gotoxy(x, y + 1);
    printf("2. 게임방법\n");
    gotoxy(x, y + 2);
    scanf_s("%d", &a);
    return a;
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   //콘솔 핸들 가져오기
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
    printf("징검다리 게임 방법");
    gotoxy(x, y + 1);
    printf("안깨진 징검다리는 뭐게요~\n");
    gotoxy(x, y + 2);
    printf("죽지 말고, 끝까지 징검다리를 건너세요!\n");
    gotoxy(x, y + 4);
    printf("스페이스바를 누르면 메인화면으로 돌아갑니다..");

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
            arr_glass[i][j] = '□';
        }
    }

    printf("\n\n\n");
    gotoxy(45, 5);
    gotoxy(45, 5);
    printf("오징어 게임 징검 다리 건너기\n\n");
    for (int i = 0; i < 10; i++) {
        gotoxy(45, 10 + i);
        printf("|  □  □  |\n");
    }
    while (1) {

    }



    while (1) {
        int ch2;
        progress(arr_glass, turn);
        printf("%d번 참가자 도전!\n", 17 - life);
        printf("당신의 선택은?\n1.왼쪽 2. 오른쪽\n");
        scanf_s("%d", &ch2);
        if (ch2 == 1 || ch2 == 2) {
            if (arr_bool[index][ch2 - 1] == 1) {
                printf("성공!\n");
                index--;
                turn--;
            }
            else {
                printf("사망!\n");
                arr_glass[index][ch2 - 1] = ' ';
                index = 17;
                turn = 17;
                life--;
            }
        }
        if (life == 0) {
            printf("게임오버!\n");
            break;
        }
        else if (turn == -1) {
            break;
            printf("우승!!!\n");
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
            printf("<--------현위치\n");
        else
            printf("\n");
    }
}

}