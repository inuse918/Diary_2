#include <iostream>
#include <Windows.h>
#include "Help.h"
using namespace std;

void Help::PrintHelp() {
	system("cls");
	MovePosition(45, 3);
	cout << "[����]" << endl;
	MovePosition(40, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �۾� ���� �ٲ�
	cout << "�ܼ� �ϱ��� �Դϴ�." << endl;
	MovePosition(40, 8);
	cout << "�޴� 1���� ���� �ϱ⸦ �ۼ��մϴ�. ���� ��ĥ ���� Enter �� // �� �Է��մϴ�." << endl;
	MovePosition(40, 10);
	cout << "�޴� 2���� ���� �ۼ��ߴ� �ϱ⸦ �ҷ��ɴϴ�." << endl;
	MovePosition(40, 12);
	cout << "�޴� 4���� ���� �����մϴ�." << endl;
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
