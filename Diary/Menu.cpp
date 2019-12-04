#include "Main.h"

Menu::Menu(int x, int y) {
	MovePosition(x, y);
}
Menu::Menu() {
	selectedMenu=0;
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
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 글씨 색을 바꿈
	MovePosition(50, 1);
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
	cout << "선택할 메뉴를 입력하세요" << endl;
	MovePosition(40, 14);
	cout<<"(메뉴 이외의 숫자를 입력할 경우 메뉴가 다시 로딩됩니다.) = > " << endl;
}
void Menu::LPrintMenu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "[기능]";
	MovePosition(55, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "1. 일기 보기";
	MovePosition(55, 4);
	cout << "2. 일기 수정하기";
	MovePosition(55, 6);
	cout << "3. 일기 삭제하기";
	MovePosition(55, 8);
	cout << "4. 메인화면으로 돌아가기";
	MovePosition(55, 10);
	cout << "메뉴 선택==> ";
}


int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(103, 14);
	cin >> selectedMenu;
}

int Menu::LGetSelectedMenu() {
	return selectedMenu;
}

void Menu::LRecieveMenu() {
	MovePosition(70, 10);
	cin >> selectedMenu;
}