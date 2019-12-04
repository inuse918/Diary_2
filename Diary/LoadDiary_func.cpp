#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

string diaryName;
ofstream input;

char ch;
void LoadDiary_func::DeleteDiary() {
	Main main = Main();
	LoadDiary loaddiary = LoadDiary();
	int choose;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "�ϱ⸦ �����մϴ�." << endl;

	cout << "�����ϰ� ���� �ϱ��� ������ Ȯ���� ���� �Է����ּ���." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cin >> diaryName;
	diaryName.append(".txt");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << " ������ ������ �ǵ��� �� �����ϴ�. ���� ������ ��� �����Ͻðڽ��ϱ�?" << endl;
	cout << "��� �����Ϸ��� 1, �������� ���ư����� 0�� �Է��� �ּ���=> " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choose;

	switch (choose)
	{
	case 1:
		if (remove(diaryName.c_str()) != 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�������� �ʴ� �����Դϴ�. ������ �����Ͽ����ϴ�." << endl;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << diaryName << "������ ���������� �����Ǿ����ϴ�." << endl;
		}
		input.close();
		cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			main.printMain();
		}
		break;
	case 0:
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}
}
void LoadDiary_func::ModifyDiary() {
	system("cls");
	LoadDiary loaddiary = LoadDiary();
	ofstream out;
	int choose;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
	std::cout << "[����] ������ ������ ������ϴ�." << endl;
	cout << "�׷��� �����Ͻ÷��� 1, �������� �ǵ��ư����� 0�� �Է��ϼ���=> ";
	cin >> choose;

	switch (choose) {
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "�����ϰ� ���� �ϱ� ������ Ȯ���� ���� �Է����ּ���." << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		out.open(diaryName, ios::out);

		out.close();

		break;
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n�ǵ��ư��ϴ�." << endl;
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}

	
}
void LoadDiary_func::WatchDiary() {
	Main main = Main();
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