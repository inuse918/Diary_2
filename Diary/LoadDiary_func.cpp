#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

char ch;

bool FileExists(const string& filename)
{
	WIN32_FIND_DATAA fd = { 0 };
	HANDLE hFound = FindFirstFileA(filename.c_str(), &fd);
	bool retval = hFound != INVALID_HANDLE_VALUE;
	FindClose(hFound);

	return retval;
}

void LoadDiary_func::DeleteDiary() {
	fstream input;
	Main main = Main();
	LoadDiary loaddiary = LoadDiary();
	int choose;
	string diaryName;
	//ofstream out;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "�ϱ⸦ �����մϴ�." << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "������ ������ �ǵ��� �� �����ϴ�. ���� ������ ��� �����Ͻðڽ��ϱ�?" << endl;
	cout << "��� �����Ϸ��� 1, �������� ���ư����� 0�� �Է��� �ּ���=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choose;
	switch (choose)
	{
	case 1: {
		cout << "�����ϰ� ���� �ϱ��� ������ Ȯ���� ���� �Է����ּ���." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		input.open(diaryName.c_str(), ios::in | ios::out | ios::ate);
		if (input.is_open())
		{
			input.close();
		}
		input.close();
		if (FileExists(diaryName)==0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "�������� �ʴ� �����Դϴ�. ������ �����Ͽ����ϴ�." << endl;
		}
		else {
			input.close();
			DeleteFile(diaryName.c_str());
			//remove(diaryName.c_str());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << diaryName << "������ ���������� �����Ǿ����ϴ�." << endl;
		}
		cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			loaddiary.Load();
		}
		break;
	}
	case 0:
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}
}
void LoadDiary_func::ModifyDiary() {
	fstream input;
	Main main = Main();
	system("cls");
	LoadDiary loaddiary = LoadDiary();
	string diaryName;
	
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	char ch;
	int choose;
	vector<string> content;
	string line;

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
		input.open(diaryName);
		cout << endl << endl << endl << endl;
		if (FileExists(diaryName) != 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "\n�ϱ��� ������ �ٽ� �Է��ϼ���.\n(��¥�� �ý��� �ð��� ���߾� �ڵ����� �Էµ˴ϴ�.)" << endl;
			cout << "���� �ϱ⸦ ������ �ʹٸ� ������ �ٿ��� enter �� '***'�� �Է��� �ּ���.\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			//��¥ �Է�
			input << curr_tm->tm_year + 1900 << "�� " << curr_tm->tm_mon + 1 << "�� " << curr_tm->tm_mday << "��" << endl;
			while (1) {
				getline(cin, line);
				if (line.compare("***") == 0)
					break;
				content.push_back(line);
			}
			vector<string>::iterator iter;
			for (iter = content.begin(); iter != content.end(); ++iter) {
				input << *iter << endl;
			}
			input.close();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n\n�ϱ� ���� �Ϸ�" << endl;
			cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
			ch = _getch();
			if (ch != 0) {
				system("cls");
				main.printMain();
			}
		} 
		else  {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "������ �������� �ʽ��ϴ�." << endl;
			cout << "�ƹ� Ű�� ������ �ǵ��ư��ϴ�." << endl;
			ch = _getch();
			if (ch != 0) {
				system("cls");
				loaddiary.Load();
			}
		}
		break;
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
	string diaryName;
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
	file.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�������� ���ư����� �ƹ� Ű�� ��������." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}