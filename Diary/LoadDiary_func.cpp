#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

string diaryName;
ofstream input;
Main main = Main();
char ch;
void LoadDiary_func::DeleteDiary() {
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "�ϱ⸦ �����մϴ�." << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "�����ϰ� ���� �ϱ��� ������ Ȯ���� ���� �Է����ּ���." << endl;

	cin >> diaryName;
	diaryName.append(".txt");

	
	if (remove(diaryName.c_str())) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout <<"�������� �ʴ� �����Դϴ�. ������ �����Ͽ����ϴ�." << endl;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << diaryName << "������ ���������� �����Ǿ����ϴ�." << endl;
	}
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
void LoadDiary_func::ModifyDiary() {
	system("cls");
	
}
void LoadDiary_func::WatchDiary() {
	string content;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "�ۼ��� �ϱ⸦ ���ϴ�." << endl;
	cout << "���� ���� �ϱ��� ������ Ȯ���� ���� �Է����ּ���.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	ifstream file(diaryName);
	cout << endl << endl<<endl<<endl;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, content);
			cout << content << endl;
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "������ �������� �ʽ��ϴ�." << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}

}