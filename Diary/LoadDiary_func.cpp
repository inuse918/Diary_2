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
	cout << "������ ������ �ǵ��� �� �����ϴ�. ���� ������ ��� �����Ͻðڽ��ϱ�?" << endl;
	cout << "��� �����Ϸ��� 1, �������� ���ư����� 0�� �Է��� �ּ���=> ";
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
	Main main = Main();
	system("cls");
	LoadDiary loaddiary = LoadDiary();
	ofstream out;
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	char ch;
	int choose;
	FILE* file;
	vector<string> content;
	string line;
	//vector<string>::iterator iter;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
	std::cout << "[����] ������ ������ ������ϴ�." << endl;
	cout << "�׷��� �����Ͻ÷��� 1, �������� �ǵ��ư����� 0�� �Է��ϼ���=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //���
	cin >> choose;
	switch (choose) {
	case 1: {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "�����ϰ� ���� �ϱ� ������ Ȯ���� ���� �Է����ּ���." << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		file = fopen(diaryName.c_str(), "rb+");
		fclose(file);
		out.open(diaryName);
		if (file == NULL) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
			cout << "�������� �ʴ� �����Դϴ�. �ƹ�Ű�� ������ �������� �ǵ��ư��ϴ�." << endl;
			ch = _getch();
			if (ch != 0) {
				system("cls");
				loaddiary.Load();
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\n�ϱ��� ������ �ٽ� �Է��ϼ���.\n(��¥�� �ý��� �ð��� ���߾� �ڵ����� �Էµ˴ϴ�.)" << endl;
		cout << "���� �ϱ⸦ ������ �ʹٸ� ������ �ٿ��� enter �� '***'�� �Է��� �ּ���.\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		//��¥ �Է�
		out << curr_tm->tm_year + 1900 << "�� " << curr_tm->tm_mon + 1 << "�� " << curr_tm->tm_mday << "��" << endl;
		while (1) {
			getline(cin, line);
			if (line.compare("***") == 0)
				break;
			content.push_back(line);
		}
		vector<string>::iterator iter;
		for (iter = content.begin(); iter != content.end(); ++iter) {
			out << *iter << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		out.close();
		cout << "\n\n�ϱ� ���� �Ϸ�" << endl;
		cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			main.printMain();
		}
		//break;
	}
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