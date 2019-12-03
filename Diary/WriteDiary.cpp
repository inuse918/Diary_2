#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	string diaryName;
	Main main = Main();
	ofstream input;
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	char ch;

	vector<string> content;
	string line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ϱ� ������ �Է��ϼ���(30�� �̳�): ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n�ϱ��� ������ �Է��ϼ���.\n(��¥�� �ý��� �ð��� ���߾� �ڵ����� �Էµ˴ϴ�.)" << endl;
	cout << "���� �ϱ⸦ ������ �ʹٸ� ������ �ٿ��� enter �� '<end>'�� �Է��� �ּ���.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
	//��¥ �Է�
	input << curr_tm->tm_year + 1900 << "�� " << curr_tm->tm_mon + 1 << "�� " << curr_tm->tm_mday << "��" << endl;
	
	while (1) {
		getline(cin, line);  
		if (line.compare("<end>") == 0) 
			break;
		content.push_back(line); 
	}
	vector<string>::iterator iter;
	for (iter = content.begin(); iter != content.end(); ++iter) {
		input << *iter << endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n�ϱ� ���� �Ϸ�" <<endl;
	cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
