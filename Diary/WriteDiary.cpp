#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	//string diary;
	string diaryName;
	FILE* diary;
	ofstream input;
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ϱ� ������ �Է��ϼ���"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ϱ��� ������ �Է��ϼ���." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
	//��¥ �Է�
	input << curr_tm->tm_year + 1900 << "�� " << curr_tm->tm_mon + 1 << "�� " << curr_tm->tm_mday << "��" << endl;

	
}