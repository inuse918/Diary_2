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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �۾� ���� �ٲ�
	cout << "[�ܼ� �ϱ���]" << endl;

	MovePosition(45, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "1. �ϱ� ����" << endl;

	MovePosition(45, 5);
	cout << "2. �ϱ� �ҷ�����" << endl;

	MovePosition(45, 7);
	cout << "3. ����" << endl;

	MovePosition(45, 9);
	cout << "4. �����ϱ�" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	MovePosition(45, 12);
	cout << "������ �޴��� �Է��ϼ��� => " << endl;
}

int Menu::GetSelectedMenu() {
	return selectedMenu;
}

void Menu::RecieveMenu() {
	MovePosition(75, 12);
	cin >> selectedMenu;
}