#include "jingumdari.h"

int main(void) {
	while (1) {
		drawTitle();
		if (!JmenuDraw()) {
			gloop();
		}
		else
			break;
	}
	system("cls");
	return 0;
}

void drawTitle() {
	int x = 48;
	int y = 4;
	system("cls");

	setColor(yellow);
	gotoxy(x, y);
	printf("    _ _                            _           _      ");
	gotoxy(x, ++y);
	printf("   (_|_)_ _   __ _  _  _ _ __   __| | __ _ _ _(_)     ");
	gotoxy(x, ++y);
	printf("   | | | ' | / _` |  || | '  ＼/ _`  / _` | '_| |     ");
	gotoxy(x, ++y);
	printf("  _/ |_|_||_＼__, |＼_,_|_|_|_＼__,_＼__,_|_| |_|     ");
	gotoxy(x, ++y);
	printf(" |__/        |___/                                    ");

	setColor(white);
	x = 45, y = 12;
	gotoxy(x, y);
	printf(" ---||-------||-------||----||------||-------||-----");
	gotoxy(x, ++y);
	printf("|                                                   |");
	gotoxy(x, ++y);
	printf("|      ○△□ 이번 게임은 징검다리 입니다 ○△□    |");
	gotoxy(x, ++y);
	printf("|                                                   |");
	gotoxy(x, ++y);
	printf("|      죽지 말고, 끝까지 징검다리를 건너세요        |");
	gotoxy(x, ++y);
	printf("|  총 10번의 기회 안에 징검다리를 건너면 통과입니다 |");
	gotoxy(x, ++y);
	printf("|                                                   |");
	gotoxy(x, ++y);
	printf("|          엔터키(ENTER)를 눌러 시작하세요          |");
	gotoxy(x, ++y);
	printf("|                                                   |");
	gotoxy(x, ++y);
	printf(" ---||-------||-------||----||------||-------||-----");

	x = 85, y = 24;
	gotoxy(x, ++y);
	printf("/⌒＞―――＜⌒ヘ");
	gotoxy(x, ++y);
	printf("｜／　　　　　＼｜");
	gotoxy(x, ++y);
	printf(" Y　　　　　　　Y");
	gotoxy(x, ++y);
	printf(" | ●　　　 ●　|");
	gotoxy(x, ++y);
	printf(" ＼ //(_人_) //ノ");
	gotoxy(x, ++y);
	printf("　 ＞――――イ");
	gotoxy(x, ++y);
	printf("　/　|　　　|)");

	gotoxy(50, 33);
	setColor(darkgray);
	printf("developed by 배서연 윤소희 최가을 황채민");
	setColor(white);
}

int JmenuDraw() {
	int input;
	int x = 68, y = 26;
	int key = y;
	gotoxy(x - 2, y);
	printf("> 시작하기\n");
	gotoxy(x, y + 1);
	printf("종료하기");
	while (1) {
		input = _getch();
		switch (input) {
		case UP: {
			if (y > key) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < key + 1) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case ENTER: {
			return y - key;
		}
		case ESC: {
			return 3;
		}
		}
	}
	return 0;
}
int JkeyControl() {
	int input;
	while (1) {
		input = _getch();
		switch (input) {
			case LEFT: {
				return 1;
				break;
			}
			case RIGHT: {
				return 2;
				break;
			}
		}
	}
	return 0;
}
void gloop() {
	int center = 15;
	int index = center;
	int turn = center;
	int life = center - 1;
	int arr_bool[16][2];	// 1 0 들어갈 배열
	char arr_glass[16][2];
	int key, x, y;

	//값 넣어주기
	system("cls");
	srand(time(NULL));
	for (int i = 0; i < 16; i++) {
		arr_bool[i][0] = rand() % 2;
		arr_bool[i][1] = !arr_bool[i][0];
		for (int j = 0; j < 2; j++) {
			arr_glass[i][j] = 'O';
			//printf("%d ", arr_bool[i][j]);
		}
		//printf("\n");
	}
	while (1) {

		system("cls");
		//테두리 그려주기
		for (int i = 2; i < 70; i++) {
			gotoxy(i, 2);
			printf("■");
			gotoxy(i, 30);
			printf("■");
		}
		for (int i = 2; i < 30; i++) {
			gotoxy(2, i);
			printf("■");
			gotoxy(70, i);
			printf("■");
			setColor(white);
		}
		x = 28, y = 8;
		// 징검다리 그려주기
		for (int i = 0; i < 16; i++) {
			gotoxy(x, ++y);
			printf("||");
			setColor(yellow);
			for (int j = 0; j < 2; j++) {
				printf("   %c   ", arr_glass[i][j]);
			}
			setColor(white);
			printf("||");
			if (i == turn + 1) printf("<------현위치\n");
			else printf("\n");
		}
		gotoxy(28, 25);
		printf("↑ 여기서 시작!");


		x = 90;
		y = 2;
		gotoxy(x, y);
		printf("  - - - - - - - - - - - - - - -");
		gotoxy(x, ++y);
		printf("/                              ＼");
		gotoxy(x, ++y);
		printf("|  저것 봐봐.. 저길 통과한대... |");
		gotoxy(x, ++y);
		printf("＼                             /");
		gotoxy(x, ++y);
		printf("  - - - - - - - -     - - - - -");
		gotoxy(x, ++y);
		printf("                 ＼  /");
		gotoxy(x, ++y);
		printf("                  ＼/");
		gotoxy(x, ++y);
		printf(" /⌒＞―――＜⌒ヘ");
		gotoxy(x, ++y);
		printf("｜／　　　　　＼｜");
		gotoxy(x, ++y);
		printf(" Y　　　　　　　Y");
		gotoxy(x, ++y);
		printf(" | ●　　　 ●　|");
		gotoxy(x, ++y);
		printf(" ＼ //(_人_) //ノ");
		gotoxy(x, ++y);
		printf("　 ＞――――イ");
		gotoxy(x, ++y);
		printf("　/　|　　　|)");

		y += 2;
		setColor(white);
		gotoxy(x, y);
		printf(" -----게 임 방 법-----");
		gotoxy(x, ++y);
		printf("|                     |");
		gotoxy(x, ++y);
		printf("|                     |");
		gotoxy(x, ++y);
		printf("|    당신의 선택은?   |");
		gotoxy(x, ++y);
		printf("|                     |");
		gotoxy(x, ++y);
		printf("|    ←(왼) →(오)    |");
		gotoxy(x, ++y);
		printf("|  방향키를 움직여서  |");
		gotoxy(x, ++y);
		printf("|  두 다리 중 하나를  |");
		gotoxy(x, ++y);
		printf("|      고르세요!      |");
		gotoxy(x, ++y);
		printf("|                     |");
		gotoxy(x, ++y);
		printf("|   %d번 참가자 도전!  |", center - life);
		gotoxy(x, ++y);
		printf("|                     |");
		gotoxy(x, ++y);
		printf(" ---------------------");

		x = 15, y = 3;
		gotoxy(x, y);
		gotoxy(x, ++y);
		printf("           -----------------------------");
		gotoxy(x, ++y);
		printf("생명 %d번 |", life);
		setColor(red);
		for (int i = 1; i <= life; i++) {
			printf("♥");
		}
		setColor(white);
		for (int i = 0; i <= 14 - life; i++) {
			printf("  ");
		}
		printf("|");
		gotoxy(x, ++y);
		printf("           -----------------------------");

		key = JkeyControl();

		x = 33, y = 27;
		if (key == 1 || key == 2) {
			if (arr_bool[index][key - 1] == 1) {
				gotoxy(x, y);
				setColor(lightcyan);
				printf("성공!\n");
				setColor(white);
				x = 90;
				y = 2;
				gotoxy(x, y);
				printf("  - - - - - - - - - - - - - - -");
				gotoxy(x, ++y);
				printf("/                              ＼");
				gotoxy(x, ++y);
				printf("|          후~ 살았다!          |");
				gotoxy(x, ++y);
				printf("＼                             /");
				gotoxy(x, ++y);
				printf("  - - - - - - - -     - - - - -");
				gotoxy(x, ++y);
				printf("                 ＼  /");
				gotoxy(x, ++y);
				printf("                  ＼/");
				setColor(yellow, black);
				gotoxy(x, ++y);
				printf(" /⌒＞―――＜⌒ヘ");
				gotoxy(x, ++y);
				printf("｜／　　　　　＼｜");
				gotoxy(x, ++y);
				printf(" Y　　　　　　　Y");
				gotoxy(x, ++y);
				printf(" |   >　　　 <　|");
				gotoxy(x, ++y);
				printf(" ＼ //(_人_) //ノ");
				gotoxy(x, ++y);
				printf("　 ＞――――イ");
				gotoxy(x, ++y);
				printf("　/　|　　　|)");
				Sleep(1200);
				setColor(white);
				index--;
				turn--;
			}
			else {
				gotoxy(x, y);
				setColor(red);
				printf("사망!\n");
				setColor(white);
				x = 90;
				y = 2;
				gotoxy(x, y);
				printf("  - - - - - - - - - - - - - - -");
				gotoxy(x, ++y);
				printf("/                              ＼");
				gotoxy(x, ++y);
				printf("|     으악 사망!! 떨어진다!!    |");
				gotoxy(x, ++y);
				printf("＼                             /");
				gotoxy(x, ++y);
				printf("  - - - - - - - -     - - - - -");
				gotoxy(x, ++y);
				printf("                 ＼  /");
				gotoxy(x, ++y);
				printf("                  ＼/");
				setColor(red);
				gotoxy(x, ++y);
				printf(" /⌒＞―――＜⌒ヘ");
				gotoxy(x, ++y);
				printf("｜／　　　　　＼｜");
				gotoxy(x, ++y);
				printf(" Y　　　　　　　Y");
				gotoxy(x, ++y);
				printf(" |   ㅠ　　 ㅠ　|");
				gotoxy(x, ++y);
				printf(" ＼ //(_人_) //ノ");
				gotoxy(x, ++y);
				printf("　 ＞――――イ");
				gotoxy(x, ++y);
				printf("　/　|　　　|)");
				Sleep(1200);
				setColor(white);
				arr_glass[index][key - 1] = ' ';
				index = center;
				turn = center;
				life--;
			}
		}
		if (life == 0) {
			int x = 58;
			int y = 10;
			system("cls");
			gotoxy(x, y);
			printf("게임 오버...");
			Sleep(3000);
			break;
		}
		if (turn == -1) {
			system("cls");
			gotoxy(x, y);
			printf("우승!!!");
			Sleep(2000);
			break;
		}
	}
}