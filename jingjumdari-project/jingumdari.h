﻿#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#ifndef KEY_CODE
#define KEY_CODE

/*기본 함수*/

void gotoxy(int, int);
void setColor(int);

/*함수 선언*/
void drawTitle();
int JmenuDraw();
int JkeyControl();
void gloop();

//키보드 값
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#endif

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);   //콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}