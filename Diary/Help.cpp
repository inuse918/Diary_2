#include <iostream>
#include <Windows.h>
#include "Help.h"
using namespace std;

void Help::PrintHelp() {
	system("cls");
	MovePosition(45, 3);
	cout << "[도움말]" << endl;
	MovePosition(40, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 글씨 색을 바꿈
	cout << "콘솔 일기장 입니다." << endl;
	MovePosition(40, 8);
	cout << "메뉴 1번을 통해 일기를 작성합니다. 글을 마칠 때는 Enter 후 // 을 입력합니다." << endl;
	MovePosition(40, 10);
	cout << "메뉴 2번을 통해 작성했던 일기를 불러옵니다." << endl;
	MovePosition(40, 12);
	cout << "메뉴 4번을 눌러 종료합니다." << endl;
}
void Help::MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
Help::Help() {

}
