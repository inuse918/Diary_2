#include <iostream>
#include <Windows.h>
#include "Menu.h"
using namespace std;

Menu::Menu(int x, int y) {
	MovePosition(x, y);
}
	

void Menu::MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Menu::PrintMenu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 글씨 색을 바꿈
	cout << "[콘솔 일기장]" << endl;

	MovePosition(45, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "1. 일기 쓰기" << endl;

	MovePosition(45, 5);
	cout << "2. 일기 불러오기" << endl;

	MovePosition(45, 7);
	cout << "3. 도움말" << endl;

	MovePosition(45, 9);
	cout << "4. 종료하기" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	MovePosition(45, 12);
	cout << "선택할 메뉴를 입력하세요 => " << endl;
}

int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(75, 12);
	cin >> selectedMenu;
}